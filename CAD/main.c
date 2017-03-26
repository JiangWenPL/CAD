/*
*    main.c
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 3/14/2017.
*    Copyright (c) 2017 Wen Jiang. All rights reserved.
*/
#include"main.h"
//typedef struct MSGQUEUE {
//	int32_t size;
//	int32_t style;
//	struct MSGQUEUE *pNext;
//}MsgQueue;
int32_t m_lMode = 0;
ACL_Color m_CurrentColor = BLACK;
MsgQueue* p_MsgHead = NULL;
MsgQueue CAD_Msg;
int32_t IO_Init();
int32_t DrawRectangle(int x0, int y0, int size, int style);
int32_t Erase(int x0, int y0, int size, int style);
int32_t Craming(int x0, int y0, int size, int style);
int32_t Words(int x0, int y0, int size, int style);
MsgQueue* NewMsgQueue();
MsgQueue* Push_Back_Msg(const MsgQueue* p_CurrentMsg);
MsgQueue Pop_Msg();
TimerEventCallback TimerEvent(int timerID);
CharEventCallback CharEvent(char c);
KeyboardEventCallback KeyboardEvent(int key, int event);
MouseEventCallback MouseEvent(int x, int y, int button, int event);

int Setup() {
	initWindow("CAD", DEFAULT, DEFAULT, 1024, 768);
	initConsole();
	IO_Init();
	registerTimerEvent(&TimerEvent);
	registerKeyboardEvent(&KeyboardEvent);
	registerCharEvent(&CharEvent);
	registerMouseEvent(&MouseEvent);
	return 0;
}
TimerEventCallback TimerEvent(int timerID) { ; }
CharEventCallback CharEvent(char c) {
	static int32_t flag_input = 0;
	static int32_t num = 0;
	static MsgQueue Msg;
	int32_t length = 0;
	int32_t length_Temp = num;
	while (length_Temp != 0) {
		length++;
		length_Temp = length_Temp / 10;
	}
	if (0 == flag_input) flag_input = 1;
	if (CHAR_ENTER == c) {
		flag_input++;
		num = 0;
	}
	beginPaint();
	paintText(0, 0, CLEAN_LINE);
	switch (flag_input)
	{
	case 0:break;
	case 1:
		//New feature
		SetCaretPos(CARET_POSITON_X_SIZE+length*SIZE_PER_CARET,CARET_POSITON_Y );
		showCaret();
		if (isdigit(c)) {
			num = num * 10 + c - '0';
		}
		String Dynamic_Size;
		sprintf(Dynamic_Size, "size = %d pixels", num);
		paintText(0, 0, Dynamic_Size);
		CAD_Msg.Size = num;
		break;
	case 2:
		SetCaretPos(CARET_POSITON_X_STYLE + length*SIZE_PER_CARET, CARET_POSITON_Y);
		if (isdigit(c)) {
			num = num * 10 + c - '0';
		}
		sprintf(Dynamic_Size, "style = %d", num);
		paintText(0, 0, Dynamic_Size);
		CAD_Msg.Style = num;
		break;
	case 3:
		flag_input = 0;
		hideCaret();
		break;
	default:
		break;
	}
	endPaint();
}
KeyboardEventCallback KeyboardEvent(int key, int event) {
	printf("Key = %d,event = %d\n", key, event);
	if (key == CHAR_ENTER) {
		MsgQueue Msg_Enter;
		Msg_Enter.Style = -1;
		Msg_Enter.Size = -1;
		Push_Back_Msg(&Msg_Enter);
	}
}
MouseEventCallback MouseEvent(int x, int y, int button, int event) {
	//static int32_t  Click_Times = 0;
	static int32_t PressDown = 0;
	static MsgQueue Current_Msg;
	switch (event)
	{
	case 0: PressDown = 1; break;
	case 1: PressDown = 2; break;
	case 2: PressDown = 0; break;
	}
	//Use Static variable to check whether the user's Mouse is pressing & moving.
	//Also it can be easy to write the pen function and erase.
	static int i = 0;
	if (i == 0) {
		DrawRectangle(100, 100, 5, 1);
		i = 1;
	}
	printf("x=%d, y=%d, butoton =%d, event = %d\n", x, y, button, event);
	if (x > RECTANGLE_X_LEFT && x < RECTANGLE_X_RIGHT && y > RECTANGLE_Y_UP && y < RECTANGLE_Y_DOWN && button == 1 && event == 0) {
		m_lMode = 1;
	}
	else if (x > ERASE_X_LEFT && x < ERASE_X_RIGHT && y > ERASE_Y_UP && y < ERASE_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 3;
	}
	else if (x > CRAMING_BUTTON_X_LEFT && x<CRAMING_BUTTON_X_RIGHT && y>CRAMING_BUTTON_Y_UP && y < CRAMING_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 5;
	}
	if (0 != m_lMode && PressDown == 1)
		//Beacuse we have varible PressDown we don't care the event and button.
	{
		switch (m_lMode) {
		case 1:
			DrawRectangle(x, y, 1, 1);
			break;
			//Rectangle tool
		case 3:
			printf("In call erase\n");
			Erase(x, y, CAD_Msg.Size, CAD_Msg.Style);
			//Erase mode.
			break;
		case 5:
			Craming(x,y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		}
	}
}
int32_t IO_Init() {
	p_MsgHead = NewMsgQueue();
	CAD_Msg.Size = 10;
	CAD_Msg.Style = 1;
	beginPaint();
	ACL_Image Pallet, DashBoard;
	loadImage(".//pallet.bmp", &Pallet);
	putImage(&Pallet, PALLETX, PALLETY);
	loadImage(".//DashBoard.bmp", &DashBoard);
	putImage(&Pallet, PALLETX, PALLETY);
	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
}
int32_t DrawRectangle(int x0, int y0, int size, int style) {
	switch (style) {
	case 1:
		printf("In darw\n");
		beginPaint();
		setPenColor(RED);
		rectangle(x0, y0, x0 + size * 30, y0 + size * 20);
		endPaint();
	}
}
int32_t Erase(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			setBrushColor(WHITE);
			setPenColor(WHITE);
			rectangle(x0, y0, x0 + size, y0 + size);
			setBrushColor(m_CurrentColor);
			setPenColor(m_CurrentColor);
			endPaint();
			break;
		case 2:
			beginPaint();
			setBrushColor(WHITE);
			setPenColor(WHITE);
			ellipse(x0, y0, x0 + size, y0 + size);
			setBrushColor(m_CurrentColor);
			setPenColor(m_CurrentColor);
			endPaint();
			break;
		default :
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;
}
int32_t Craming(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			rectangle(x0, y0, x0 + size, y0 + size);
			endPaint();
			break;
		case 2:
			beginPaint();
			ellipse(x0, y0, x0 + size, y0 + size);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
}
MsgQueue* NewMsgQueue() {
	MsgQueue *p_Temp = (MsgQueue*)malloc(sizeof(MsgQueue));
	p_Temp->pNext = NULL;
}//Encapusule to avoid dangling pointer.
MsgQueue* Push_Back_Msg(const MsgQueue* p_CurrentMsg) {
	MsgQueue *p_Iterator = NULL;
	if (NULL == p_MsgHead->pNext) {
		p_Iterator = p_MsgHead;
		p_MsgHead->pNext = NewMsgQueue();
	}
	else {
		for (p_Iterator = p_MsgHead; p_Iterator->pNext != NULL; p_Iterator = p_Iterator->pNext);
		p_Iterator->pNext = NewMsgQueue();
	}
	p_Iterator->Size = p_CurrentMsg->Size;
	p_Iterator->Style = p_CurrentMsg->Style;
	return p_Iterator;
}
MsgQueue Pop_Msg() {
	MsgQueue p_Return = *p_MsgHead;
	MsgQueue *p_FreeTemp = p_MsgHead;
	if (NULL == p_MsgHead->pNext) {
		p_MsgHead = NewMsgQueue();
	}
	else {
		p_MsgHead = p_MsgHead->pNext;
	}
	free(p_FreeTemp);
	return p_Return;
}
