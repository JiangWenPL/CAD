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
int32_t String_Index;
char Words_string[100];
int32_t m_Text_Postion_x = 0;
int32_t m_Text_Postion_y = 0;
ACL_Color m_CurrentColor = BLACK;
MsgQueue* p_MsgHead = NULL;
MsgQueue CAD_Msg;
int32_t IO_Init();
int32_t DrawRectangle(int x0, int y0, int size, int style);
int32_t Erase(int x0, int y0, int size, int style);
int32_t Craming(int x0, int y0, int size, int style);
int32_t Words(int x0, int y0, int size, int style);
//bellows are newly added function
int32_t	Regular_Triangle(int x0, int y0, int size, int style);
int32_t Right_Triangle(int x0, int y0, int size, int style);
int32_t Five_Star(int x0, int y0, int size, int style);
int32_t Up_Arrow(int x0, int y0, int size, int style);
int32_t DrawSquare(int x0, int y0, int size, int style);
int32_t DrawCurve(int x0, int y0, int size, int style);
int32_t DrawCircle(int x0, int y0, int size, int style);
int32_t Arc_Rectangle(int x0, int y0, int size, int style);
int32_t DrawPentagon(int x0, int y0, int size, int style);
int32_t DownArrow(int x0, int y0, int size, int style);
int32_t Hexagon(int x0, int y0, int size, int style);
int32_t Rhombus(int x0, int y0, int size, int style);
int32_t Six_Star(int x0, int y0, int size, int style);
int32_t ForeStar(int x0, int y0, int size, int style);
//Pick color
int32_t pickcolor(int x, int y);
//barcket the latetst comment
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
	//static String Words = NULL;
	static int32_t Pre_Pos_x, Pre_Pos_y;
	printf("Charb =%d", c);
	if (m_lMode != WORDS_MODE) {
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
			//New feature caretpos.
			SetCaretPos(CARET_POSITON_X_SIZE + length*SIZE_PER_CARET, CARET_POSITON_Y);
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
	else if(c!=8){
		if (Pre_Pos_x != m_Text_Postion_x && Pre_Pos_y != m_Text_Postion_y) {
			memset(Words_string, 0, sizeof(Words_string));
			String_Index = 0;
		}
		Pre_Pos_x = m_Text_Postion_x;
		Pre_Pos_y = m_Text_Postion_y;
		beginPaint();
		String Words_Temp;
		sprintf(Words_Temp, "%c", c);
		strcat(Words_string, Words_Temp);
		paintText(m_Text_Postion_x, m_Text_Postion_y, Words_string);
		int32_t strlength = strlen(Words_string);
		setTextSize(TEXT_SIZE);
		printf("StringIndex = %d\n", String_Index);
		endPaint();
	}
}
KeyboardEventCallback KeyboardEvent(int key, int event) {
	printf("Key = %d,event = %d\n", key, event);
	if (key == CHAR_ENTER) {
		MsgQueue Msg_Enter;
		Msg_Enter.Style = -1;
		Msg_Enter.Size = -1;
		Push_Back_Msg(&Msg_Enter);
	}
	if (event == 1) {
		if (key == 37) {
			String_Index = String_Index - 1;
		}
		else if (key == 39) {
			String_Index = String_Index + 1;
		}
		else if (key == 8) {
			beginPaint();
			Words_string[String_Index] = '\0';
			setTextSize(TEXT_SIZE*3);
			paintText(m_Text_Postion_x + (String_Index-1) * 16, m_Text_Postion_y + 15, "  ");
			String_Index--;
			endPaint();
			if (String_Index < 0) return -1;
		}
		else {
			String_Index++;
		}
		setCaretPos(m_Text_Postion_x + String_Index * 16, m_Text_Postion_y + 15);
		showCaret();
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
	printf("x=%d, y=%d, butoton =%d, event = %d\n", x, y, button, event);
	if (x > RECTANGLE_X_LEFT && x < RECTANGLE_X_RIGHT && y > RECTANGLE_Y_UP && y < RECTANGLE_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 8;
	}
	else if (x > PEN_BUTTON_X_LEFT && x < PEN_BUTTON_X_RIGHT && y > PEN_BUTTON_Y_UP && y < PEN_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
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
	else if (x > CURVE_BUTTON_X_LEFT && x<CURVE_BUTTON_X_RIGHT && y>CURVE_BUTTON_Y_UP && y < CURVE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 4;
	}
	else if (x > CRAMING_BUTTON_X_LEFT && x<CRAMING_BUTTON_X_RIGHT && y>CRAMING_BUTTON_Y_UP && y < CRAMING_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 5;
	}
	else if (x > LINE_BUTTON_X_LEFT && x< LINE_BUTTON_X_RIGHT && y > LINE_BUTTON_Y_UP && y < LINE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 2;
	}

	else if (x > WORDS_BUTTON_X_LEFT && x< WORDS_BUTTON_X_RIGHT && y> WORDS_BUTTON_Y_UP && y < WORDS_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 7;
	}
	else if (x > CIRCLE_BUTTON_X_LEFT && x< CIRCLE_BUTTON_X_RIGHT && y> CIRCLE_BUTTON_Y_UP && y < CIRCLE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 6;
	}
	else if (x >REGULAR_TRIANGLE_BUTTON_X_LEFT && x< REGULAR_TRIANGLE_BUTTON_X_RIGHT && y> REGULAR_TRIANGLE_BUTTON_Y_UP && y < REGULAR_TRIANGLE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 9;
	}
	else if (x >ARC_RECTANGLE_BUTTON_X_LEFT && x< ARC_RECTANGLE_BUTTON_X_RIGHT && y> ARC_RECTANGLE_BUTTON_Y_UP && y < ARC_RECTANGLE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 10;
	}
	else if (x >RIGHT_TRIANGLE_BUTTON_X_LEFT && x< RIGHT_TRIANGLE_BUTTON_X_RIGHT && y>RIGHT_TRIANGLE_BUTTON_Y_UP && y < RIGHT_TRIANGLE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 11;
	}
	else if (x >FREE_SHAPE_BUTTON_X_LEFT && x< FREE_SHAPE_BUTTON_X_RIGHT && y>FREE_SHAPE_BUTTON_Y_UP && y <FREE_SHAPE_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 11;//12 in contribution
	}
	else if (x >FORE_STAR_BUTTON_X_LEFT && x< FORE_STAR_BUTTON_X_RIGHT && y>FORE_STAR_BUTTON_Y_UP && y < FORE_STAR_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 16;
	}
	else if (x >PENTAGON_BUTTON_X_LEFT && x< PENTAGON_BUTTON_X_RIGHT && y>PENTAGON_BUTTON_Y_UP && y < PENTAGON_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 14;
	}
	else if (x >HEXAGON_BUTTON_X_LEFT && x< HEXAGON_BUTTON_X_RIGHT && y>HEXAGON_BUTTON_Y_UP && y < HEXAGON_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 15;
	}
	else if (x >RHOMBUS_BUTTON_X_LEFT && x< RHOMBUS_BUTTON_X_RIGHT && y>RHOMBUS_BUTTON_Y_UP && y < RHOMBUS_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 13;
	}
	else if (x >FIVE_STAR_BUTTON_X_LEFT && x<FIVE_STAR_BUTTON_X_RIGHT && y>FIVE_STAR_BUTTON_Y_UP && y < FIVE_STAR_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 17;
	}
	else if (x >SIX_STAR_BUTTON_X_LEFT && x<SIX_STAR_BUTTON_X_RIGHT && y>SIX_STAR_BUTTON_Y_UP && y < SIX_STAR_BUTTON_Y_DOWN && button == 1 && event == 0) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = 18;
	}
	else if (x >COLORS_X_LEFT && x<COLORS_X_RIGHT && y>COLORS_Y_UP && y < COLORS_Y_DOWN && button == 1 && event == 0) {
		pickcolor( x,  y);
	}
	/*int32_t	Rgular_Triangle(int x0, int y0, int size, int style) { ; }
	int32_t Right_Triangle(int x0, int y0, int size, int style) { ; }
	int32_t Five_Star(int x0, int y0, int size, int style) { ; }
	int32_t Up_Arrow(int x0, int y0, int size, int style) { ; }
	int32_t DrawSquare(int x0, int y0, int size, int style) { ; }
	int32_t DrawCurve(int x0, int y0, int size, int style) { ; }
	int32_t DrawCircle(int x0, int y0, int size, int style) { ; }
	int32_t Arc_Rectangle(int x0, int y0, int size, int style) { ; }
	int32_t DrawPentagon(int x0, int y0, int size, int style) { ; }
	int32_t DownArrow(int x0, int y0, int size, int style) { ; }
	int32_t Hexagon(int x0, int y0, int size, int style) { ; }*/
	if (0 != m_lMode && PressDown == 1)
		//Beacuse we have varible PressDown we don't care the event and button.
	{
		switch (m_lMode) {
		case 8:
			DrawRectangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
			//Rectangle tool
		case 1:
			Pen(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 4:
			DrawCurve(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;

		case 3:
			printf("In call erase\n");
			Erase(x, y, CAD_Msg.Size, CAD_Msg.Style);
			//Erase mode.
			break;
		case 5:
			Craming(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 2:
			StraightLine(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 7:
			Words(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 9:
			Regular_Triangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 10:
			Arc_Rectangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 11:
			Right_Triangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 13:
			Rhombus(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 14:
			DrawPentagon(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 15:
			Hexagon(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 16:
			ForeStar(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 17:
			Five_Star(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case 18:
			Six_Star(x, y, CAD_Msg.Size, CAD_Msg.Style);
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
		default:
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
int32_t StraightLine(int x0, int y0, int size, int style) {
	static int32_t Pen_Times = 0;
	static int32_t Alert_Flag = 1;
	static int32_t Pre_x = 0, Pre_y = 0;
	if (Pen_Times == 0) {
		Pen_Times = 1;
		beginPaint();
		setPenColor(WHITE);
		endPaint();
	}
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(Pre_x, Pre_y, x0, y0);
			endPaint();
			break;
		case 2:
			beginPaint();
			line(Pre_x, Pre_y, x0, y0);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	if (Pen_Times == 1) {
		beginPaint();
		setPenColor(m_CurrentColor);
		Pen_Times = -1;
		endPaint();
	}
	Pre_x = x0;
	Pre_y = y0;
}
int32_t Words(int x0, int y0, int size, int style) {
	beginPaint();
	SetCaretPos(x0, y0);
	showCaret();
	endPaint();
	m_Text_Postion_x = x0;
	m_Text_Postion_y = y0;
}
int32_t DrawRectangle(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0 + size, y0);
			line(x0, y0, x0, y0 + size);
			line(x0 + size, y0, x0 + size, y0 + size);
			line(x0, y0 + size, x0 + size, y0 + size);
			endPaint();
			break;
		case 2:
			beginPaint();
			line(x0, y0, x0 + size*1.5, y0);
			line(x0, y0, x0, y0 + size);
			line(x0 + size*1.5, y0, x0 + size*1.5, y0 + size);
			line(x0, y0 + size, x0 + size*1.5, y0 + size);
			endPaint();
			break;
		case 3:
			beginPaint();
			line(x0, y0, x0 + size, y0);
			line(x0, y0, x0, y0 + size*1.5);
			line(x0 + size, y0, x0 + size, y0 + size*1.5);
			line(x0, y0 + size*1.5, x0 + size, y0 + size*1.5);
			endPaint();
			break;

		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;
}
int32_t	Regular_Triangle(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0 + size / 2, y0 - size*1.732 / 2);
			line(x0, y0, x0 + size, y0);
			line(x0 + size / 2, y0 - size*1.732 / 2, x0 + size, y0);
			endPaint();
			break;
		case 2:
			beginPaint();
			line(x0, y0, x0 + size, y0);
			line(x0, y0, x0 + size / 2, y0 + size*1.732 / 2);
			line(x0 + size, y0, x0 + size / 2, y0 + size*1.732 / 2);
			endPaint();
			break;

		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;
}
int32_t Right_Triangle(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0, y0 - size);
			line(x0, y0, x0 + size, y0);
			line(x0, y0 - size, x0 + size, y0);
			endPaint();
			break;
		case 2:
			beginPaint();
			line(x0, y0, x0, y0 + size*1.732);
			line(x0, y0, x0 + size, y0 + size*1.732);
			line(x0, y0 + size*1.732, x0 + size, y0 + size*1.732);
			endPaint();
			break;
		case 3:
			beginPaint();
			line(x0, y0, x0, y0 + size);
			line(x0, y0, x0 + size*1.732, y0 + size);
			line(x0, y0 + size, x0 + size*1.732, y0 + size);
			endPaint();
			break;

		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 3", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;

}
int32_t DrawPentagon(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0 + size*0.81, y0 - size*0.59);
			line(x0, y0, x0 + size*0.3, y0 + size*0.95);
			line(x0 + size*0.81, y0 - size*0.59, x0 + size*1.62, y0);
			line(x0 + size*0.3, y0 + size*0.95, x0 + size*1.3, y0 + size*0.95);
			line(x0 + size*1.62, y0, x0 + size*1.3, y0 + size*0.95);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;

}
int32_t Hexagon(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0 + size / 2, y0 - size*1.732 / 2);
			line(x0, y0, x0 + size / 2, y0 + size*1.732 / 2);
			line(x0 + size / 2, y0 - size*1.732 / 2, x0 + size*1.5, y0 - size*1.732 / 2);
			line(x0 + size / 2, y0 + size*1.732 / 2, x0 + size*1.5, y0 + size*1.732 / 2);
			line(x0 + size*1.5, y0 - size*1.732 / 2, x0 + size * 2, y0);
			line(x0 + size*1.5, y0 + size*1.732 / 2, x0 + size * 2, y0);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;

}
int32_t Rhombus(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0 + size*1.414, y0 - size*1.414);
			line(x0, y0, x0 + size*1.414, y0 + size*1.414);
			line(x0 + size*1.414, y0 - size*1.414, x0 + size*2.828, y0);
			line(x0 + size*1.414, y0 + size*1.414, x0 + size*2.828, y0);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;

}
int32_t Five_Star(int x0, int y0, int size, int style)
{
	int s;
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			s = size / 2;
			beginPaint();
			line(x0, y0, x0 + s, y0);
			line(x0 + s, y0, x0 + s*1.3, y0 - s*0.95);
			line(x0 + s*1.3, y0 - s*0.95, x0 + s*1.6, y0);
			line(x0 + s*1.6, y0, x0 + s*2.6, y0);
			line(x0 + s*2.6, y0, x0 + s*2.6 - s*0.81, y0 + s*0.59);
			line(x0 + s*2.6 - s*0.81, y0 + s*0.59, x0 + s*2.6 - s*0.81 + s*0.3, y0 + s*0.59 + s*0.95);
			line(x0 + s*2.6 - s*0.81 + s*0.3, y0 + s*0.59 + s*0.95, x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81, y0 + s*0.59 + s*0.95 - s*0.59);
			line(x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81, y0 + s*0.59 + s*0.95 - s*0.59, x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81 * 2, y0 + s*0.59 + s*0.95);
			line(x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81 * 2, y0 + s*0.59 + s*0.95, x0 + s*0.81, y0 + s*0.59);
			line(x0, y0, x0 + s*0.81, y0 + s*0.59);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;

}
int32_t Six_Star(int x0, int y0, int size, int style)
{
	int s;
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			s = size / 3;
			beginPaint();
			line(x0, y0, x0 + s, y0);
			line(x0 + s, y0, x0 + s*1.5, y0 - s*1.732 / 2);
			line(x0 + s*1.5, y0 - s*1.732 / 2, x0 + s * 2, y0);
			line(x0 + s * 2, y0, x0 + size, y0);
			line(x0 + size, y0, x0 + s*2.5, y0 + s*1.732 / 2);
			line(x0 + s*2.5, y0 + s*1.732 / 2, x0 + size, y0 + s*1.732);
			line(x0, y0, x0 + s / 2, y0 + s*1.732 / 2);
			line(x0 + s / 2, y0 + s*1.732 / 2, x0, y0 + s*1.732);
			line(x0, y0 + s*1.732, x0 + s, y0 + s*1.732);
			line(x0 + s, y0 + s*1.732, x0 + s*1.5, y0 + s*1.732 * 3 / 2);
			line(x0 + s*1.5, y0 + s*1.732 * 3 / 2, x0 + s * 2, y0 + s*1.732);
			line(x0 + s * 2, y0 + s*1.732, x0 + size, y0 + s*1.732);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;

}
int32_t Arc_Rectangle(int x0, int y0, int size, int style){
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			line(x0, y0, x0 + size, y0);
			line(x0, y0, x0, y0 + size);
			line(x0 + size, y0, x0 + size, y0 + size);
			line(x0, y0 + size, x0 + size, y0 + size);
			endPaint();
			break;
		case 2:
			beginPaint();
			line(x0, y0, x0 + size*1.5, y0);
			line(x0, y0, x0, y0 + size);
			line(x0 + size*1.5, y0, x0 + size*1.5, y0 + size);
			line(x0, y0 + size, x0 + size*1.5, y0 + size);
			endPaint();
			break;
		case 3:
			beginPaint();
			line(x0, y0, x0 + size, y0);
			line(x0, y0, x0, y0 + size*1.5);
			line(x0 + size, y0, x0 + size, y0 + size*1.5);
			line(x0, y0 + size*1.5, x0 + size, y0 + size*1.5);
			endPaint();
			break;

		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;
}

int32_t ForeStar(int x0, int y0, int size, int style) {

	int s;
	static int32_t Alert_Flag = 1;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			s = size / 2;
			beginPaint();
			line(x0, y0, x0 + s, y0);
			line(x0 + s, y0, x0 + s*1.3, y0 - s*0.95);
			line(x0 + s*1.3, y0 - s*0.95, x0 + s*1.6, y0);
			line(x0 + s*1.6, y0, x0 + s*2.6, y0);
			line(x0 + s*2.6, y0, x0 + s*2.6 - s*0.81, y0 + s*0.59);
			line(x0 + s*2.6 - s*0.81, y0 + s*0.59, x0 + s*2.6 - s*0.81 + s*0.3, y0 + s*0.59 + s*0.95);
			line(x0 + s*2.6 - s*0.81 + s*0.3, y0 + s*0.59 + s*0.95, x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81, y0 + s*0.59 + s*0.95 - s*0.59);
			line(x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81, y0 + s*0.59 + s*0.95 - s*0.59, x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81 * 2, y0 + s*0.59 + s*0.95);
			line(x0 + s*2.6 - s*0.81 + s*0.3 - s*0.81 * 2, y0 + s*0.59 + s*0.95, x0 + s*0.81, y0 + s*0.59);
			line(x0, y0, x0 + s*0.81, y0 + s*0.59);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	return 0;
}
int32_t Pen(int x0, int y0, int size, int style) {
	static int32_t Pen_Times = 0;
	static int32_t Alert_Flag = 1;
	static int32_t Pre_x = 0, Pre_y = 0;
	printf("0\n");
	/*if (Pen_Times == 0) {
	Pen_Times = 1;
	printf("1\n");
	return;
	}
	if (Pen_Times == 1) {
	Pre_x = x0;
	Pre_y = y0;
	Pen_Times = 2;
	printf("2\n");
	}

	if (Pen_Times == 2 && abs(getX() - Pre_x) > 20 || abs(getY() - Pre_y) > 20) {
	Pen_Times = 0;
	}
	setPenColor(BLACK);
	*/
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN && abs(x0 - Pre_x) < 20 && abs(y0 - Pre_y) < 20) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			setPenWidth(size);
			printf("3\n");
			line(Pre_x, Pre_y, x0, y0);
			endPaint();
			break;
		case 2:
			beginPaint();
			setPenWidth(size);
			line(Pre_x, Pre_y, x0, y0);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}
	if (Pen_Times == 1) {
		beginPaint();
		setPenColor(m_CurrentColor);
		Pen_Times = -1;
		endPaint();
	}
	Pre_x = x0;
	Pre_y = y0;
}
int32_t DrawCurve(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = 1;
	static int32_t Pre_x = 0, Pre_y = 0;


	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			arc(Pre_x, Pre_y, x0, y0, Pre_x - 30, Pre_y, x0, y0);
			endPaint();
			break;
		case 2:
			beginPaint();
			line(Pre_x, Pre_y, x0, y0);
			endPaint();
			break;
		default:
			printf("In msgBox\n");
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = -1;
			break;
		}
	}

	Pre_x = x0;
	Pre_y = y0;
}
int pickcolor(int x, int y)
{
	if (x < AA_BUTTON_X_LEFT || y<AA_BUTTON_Y_UP || y>AT_BUTTON_Y_DOWN)return -1;
	if (x > AA_BUTTON_X_LEFT&&x<AA_BUTTON_X_RIGHT&&y>AA_BUTTON_Y_UP&&y < AA_BUTTON_Y_DOWN) {
		setPenColor(AA);
		setBrushColor(AA);
	}
	else if (x > AB_BUTTON_X_LEFT&&x<AB_BUTTON_X_RIGHT&&y>AB_BUTTON_Y_UP&&y < AB_BUTTON_Y_DOWN) {
		setPenColor(AB);
		setBrushColor(AB);
	}
	else if (x > AC_BUTTON_X_LEFT&&x<AC_BUTTON_X_RIGHT&&y>AC_BUTTON_Y_UP&&y < AC_BUTTON_Y_DOWN) {
		setPenColor(AC);
		setBrushColor(AC);
	}
	else if (x > AD_BUTTON_X_LEFT&&x<AD_BUTTON_X_RIGHT&&y>AD_BUTTON_Y_UP&&y < AD_BUTTON_Y_DOWN) {
		setPenColor(AD);
		setBrushColor(AD);
	}
	else if (x > AE_BUTTON_X_LEFT&&x<AE_BUTTON_X_RIGHT&&y>AE_BUTTON_Y_UP&&y < AE_BUTTON_Y_DOWN) {
		setPenColor(AE);
		setBrushColor(AE);
	}
	else if (x > AF_BUTTON_X_LEFT&&x<AF_BUTTON_X_RIGHT&&y>AF_BUTTON_Y_UP&&y < AF_BUTTON_Y_DOWN) {
		setPenColor(AF);
		setBrushColor(AF);
	}
	else if (x > AG_BUTTON_X_LEFT&&x<AG_BUTTON_X_RIGHT&&y>AG_BUTTON_Y_UP&&y < AG_BUTTON_Y_DOWN) {
		setPenColor(AG);
		setBrushColor(AG);
	}
	else if (x > AH_BUTTON_X_LEFT&&x<AH_BUTTON_X_RIGHT&&y>AH_BUTTON_Y_UP&&y < AH_BUTTON_Y_DOWN) {
		setPenColor(AH);
		setBrushColor(AH);
	}
	else if (x > AI_BUTTON_X_LEFT&&x<AI_BUTTON_X_RIGHT&&y>AI_BUTTON_Y_UP&&y < AI_BUTTON_Y_DOWN) {
		setPenColor(AI);
		setBrushColor(AI);
	}
	else if (x > AJ_BUTTON_X_LEFT&&x<AJ_BUTTON_X_RIGHT&&y>AJ_BUTTON_Y_UP&&y < AJ_BUTTON_Y_DOWN) {
		setPenColor(AJ);
		setBrushColor(AJ);
	}
	else if (x > AK_BUTTON_X_LEFT&&x<AK_BUTTON_X_RIGHT&&y>AK_BUTTON_Y_UP&&y < AK_BUTTON_Y_DOWN) {
		setPenColor(AK);
		setBrushColor(AK);
	}
	else if (x > AL_BUTTON_X_LEFT&&x<AL_BUTTON_X_RIGHT&&y>AL_BUTTON_Y_UP&&y < AL_BUTTON_Y_DOWN) {
		setPenColor(AL);
		setBrushColor(AL);
	}
	else if (x > AM_BUTTON_X_LEFT&&x<AM_BUTTON_X_RIGHT&&y>AM_BUTTON_Y_UP&&y < AM_BUTTON_Y_DOWN) {
		setPenColor(AM);
		setBrushColor(AM);
	}
	else if (x > AN_BUTTON_X_LEFT&&x<AN_BUTTON_X_RIGHT&&y>AN_BUTTON_Y_UP&&y < AN_BUTTON_Y_DOWN) {
		setPenColor(AN);
		setBrushColor(AN);
	}
	else if (x > AO_BUTTON_X_LEFT&&x<AO_BUTTON_X_RIGHT&&y>AO_BUTTON_Y_UP&&y < AO_BUTTON_Y_DOWN) {
		setPenColor(AO);
		setBrushColor(AO);
	}
	else if (x > AP_BUTTON_X_LEFT&&x<AP_BUTTON_X_RIGHT&&y>AP_BUTTON_Y_UP&&y < AP_BUTTON_Y_DOWN) {
		setPenColor(AP);
		setBrushColor(AP);
	}
	else if (x > AQ_BUTTON_X_LEFT&&x<AQ_BUTTON_X_RIGHT&&y>AQ_BUTTON_Y_UP&&y < AQ_BUTTON_Y_DOWN) {
		setPenColor(AQ);
		setBrushColor(AQ);
	}
	else if (x > AR_BUTTON_X_LEFT&&x<AR_BUTTON_X_RIGHT&&y>AR_BUTTON_Y_UP&&y < AR_BUTTON_Y_DOWN) {
		setPenColor(AR);
		setBrushColor(AR);
	}
	else if (x > AS_BUTTON_X_LEFT&&x<AS_BUTTON_X_RIGHT&&y>AS_BUTTON_Y_UP&&y < AS_BUTTON_Y_DOWN) {
		setPenColor(AS);
		setBrushColor(AS);
	}
	else if (x > AT_BUTTON_X_LEFT&&x<AT_BUTTON_X_RIGHT&&y>AT_BUTTON_Y_UP&&y < AT_BUTTON_Y_DOWN) {
		setPenColor(AT);
		setBrushColor(AT);
	}
	else if (x > BA_BUTTON_X_LEFT&&x<BA_BUTTON_X_RIGHT&&y>BA_BUTTON_Y_UP&&y < BA_BUTTON_Y_DOWN) {
		setPenColor(BA);
		setBrushColor(BA);
	}
	else if (x > BB_BUTTON_X_LEFT&&x<BB_BUTTON_X_RIGHT&&y>BB_BUTTON_Y_UP&&y < BB_BUTTON_Y_DOWN) {
		setPenColor(BB);
		setBrushColor(BB);
	}
	else if (x > BC_BUTTON_X_LEFT&&x<BC_BUTTON_X_RIGHT&&y>BC_BUTTON_Y_UP&&y < BC_BUTTON_Y_DOWN) {
		setPenColor(BC);
		setBrushColor(BC);
	}
	else if (x > BD_BUTTON_X_LEFT&&x<BD_BUTTON_X_RIGHT&&y>BD_BUTTON_Y_UP&&y < BD_BUTTON_Y_DOWN) {
		setPenColor(BD);
		setBrushColor(BD);
	}
	else if (x > BE_BUTTON_X_LEFT&&x<BE_BUTTON_X_RIGHT&&y>BE_BUTTON_Y_UP&&y < BE_BUTTON_Y_DOWN) {
		setPenColor(BE);
		setBrushColor(BE);
	}
	else if (x > BF_BUTTON_X_LEFT&&x<BF_BUTTON_X_RIGHT&&y>BF_BUTTON_Y_UP&&y < BF_BUTTON_Y_DOWN) {
		setPenColor(BF);
		setBrushColor(BF);
	}
	else if (x > BG_BUTTON_X_LEFT&&x<BG_BUTTON_X_RIGHT&&y>BG_BUTTON_Y_UP&&y < BG_BUTTON_Y_DOWN) {
		setPenColor(BG);
		setBrushColor(BG);
	}
	else if (x > BH_BUTTON_X_LEFT&&x<BH_BUTTON_X_RIGHT&&y>BH_BUTTON_Y_UP&&y < BH_BUTTON_Y_DOWN) {
		setPenColor(BH);
		setBrushColor(BH);
	}
	else if (x > BI_BUTTON_X_LEFT&&x<BI_BUTTON_X_RIGHT&&y>BI_BUTTON_Y_UP&&y < BI_BUTTON_Y_DOWN) {
		setPenColor(BI);
		setBrushColor(BI);
	}
	else if (x > BJ_BUTTON_X_LEFT&&x<BJ_BUTTON_X_RIGHT&&y>BJ_BUTTON_Y_UP&&y < BJ_BUTTON_Y_DOWN) {
		setPenColor(BJ);
		setBrushColor(BJ);
	}
	else if (x > BK_BUTTON_X_LEFT&&x<BK_BUTTON_X_RIGHT&&y>BK_BUTTON_Y_UP&&y < BK_BUTTON_Y_DOWN) {
		setPenColor(BK);
		setBrushColor(BK);
	}
	else if (x > BL_BUTTON_X_LEFT&&x<BL_BUTTON_X_RIGHT&&y>BL_BUTTON_Y_UP&&y < BL_BUTTON_Y_DOWN) {
		setPenColor(BL);
		setBrushColor(BL);
	}
	else if (x > BM_BUTTON_X_LEFT&&x<BM_BUTTON_X_RIGHT&&y>BM_BUTTON_Y_UP&&y < BM_BUTTON_Y_DOWN) {
		setPenColor(BM);
		setBrushColor(BM);
	}
	else if (x > BN_BUTTON_X_LEFT&&x<BN_BUTTON_X_RIGHT&&y>BN_BUTTON_Y_UP&&y < BN_BUTTON_Y_DOWN) {
		setPenColor(BN);
		setBrushColor(BN);
	}
	else if (x > BO_BUTTON_X_LEFT&&x<BO_BUTTON_X_RIGHT&&y>BO_BUTTON_Y_UP&&y < BO_BUTTON_Y_DOWN) {
		setPenColor(BO);
		setBrushColor(BO);
	}
	else if (x > BP_BUTTON_X_LEFT&&x<BP_BUTTON_X_RIGHT&&y>BP_BUTTON_Y_UP&&y < BP_BUTTON_Y_DOWN) {
		setPenColor(BP);
		setBrushColor(BP);
	}
	else if (x > BQ_BUTTON_X_LEFT&&x<BQ_BUTTON_X_RIGHT&&y>BQ_BUTTON_Y_UP&&y < BQ_BUTTON_Y_DOWN) {
		setPenColor(BQ);
		setBrushColor(BQ);
	}
	else if (x > BR_BUTTON_X_LEFT&&x<BR_BUTTON_X_RIGHT&&y>BR_BUTTON_Y_UP&&y < BR_BUTTON_Y_DOWN) {
		setPenColor(BR);
		setBrushColor(BR);
	}
	else if (x > BS_BUTTON_X_LEFT&&x<BS_BUTTON_X_RIGHT&&y>BS_BUTTON_Y_UP&&y < BS_BUTTON_Y_DOWN) {
		setPenColor(BS);
		setBrushColor(BS);
	}
	else if (x > BT_BUTTON_X_LEFT&&x<BT_BUTTON_X_RIGHT&&y>BT_BUTTON_Y_UP&&y < BT_BUTTON_Y_DOWN) {
		setPenColor(BT);
		setBrushColor(BT);
	}
	else if (x > CA_BUTTON_X_LEFT&&x<CA_BUTTON_X_RIGHT&&y>CA_BUTTON_Y_UP&&y < CA_BUTTON_Y_DOWN) {
		setPenColor(CA);
		setBrushColor(CA);
	}
	else if (x > CB_BUTTON_X_LEFT&&x<CB_BUTTON_X_RIGHT&&y>CB_BUTTON_Y_UP&&y < CB_BUTTON_Y_DOWN) {
		setPenColor(CB);
		setBrushColor(CB);
	}
	else if (x > CC_BUTTON_X_LEFT&&x<CC_BUTTON_X_RIGHT&&y>CC_BUTTON_Y_UP&&y < CC_BUTTON_Y_DOWN) {
		setPenColor(CC);
		setBrushColor(CC);
	}
	else if (x > CD_BUTTON_X_LEFT&&x<CD_BUTTON_X_RIGHT&&y>CD_BUTTON_Y_UP&&y < CD_BUTTON_Y_DOWN) {
		setPenColor(CD);
		setBrushColor(CD);
	}
	else if (x > CE_BUTTON_X_LEFT&&x<CE_BUTTON_X_RIGHT&&y>CE_BUTTON_Y_UP&&y < CE_BUTTON_Y_DOWN) {
		setPenColor(CE);
		setBrushColor(CE);
	}
	else if (x > CF_BUTTON_X_LEFT&&x<CF_BUTTON_X_RIGHT&&y>CF_BUTTON_Y_UP&&y < CF_BUTTON_Y_DOWN) {
		setPenColor(CF);
		setBrushColor(CF);
	}
	else if (x > CG_BUTTON_X_LEFT&&x<CG_BUTTON_X_RIGHT&&y>CG_BUTTON_Y_UP&&y < CG_BUTTON_Y_DOWN) {
		setPenColor(CG);
		setBrushColor(CG);
	}
	else if (x > CH_BUTTON_X_LEFT&&x<CH_BUTTON_X_RIGHT&&y>CH_BUTTON_Y_UP&&y < CH_BUTTON_Y_DOWN) {
		setPenColor(CH);
		setBrushColor(CH);
	}
	else if (x > CI_BUTTON_X_LEFT&&x<CI_BUTTON_X_RIGHT&&y>CI_BUTTON_Y_UP&&y < CI_BUTTON_Y_DOWN) {
		setPenColor(CI);
		setBrushColor(CI);
	}
	else if (x > CJ_BUTTON_X_LEFT&&x<CJ_BUTTON_X_RIGHT&&y>CJ_BUTTON_Y_UP&&y < CJ_BUTTON_Y_DOWN) {
		setPenColor(CJ);
		setBrushColor(CJ);
	}
	else if (x > CK_BUTTON_X_LEFT&&x<CK_BUTTON_X_RIGHT&&y>CK_BUTTON_Y_UP&&y < CK_BUTTON_Y_DOWN) {
		setPenColor(CK);
		setBrushColor(CK);
	}
	else if (x > CL_BUTTON_X_LEFT&&x<CL_BUTTON_X_RIGHT&&y>CL_BUTTON_Y_UP&&y < CL_BUTTON_Y_DOWN) {
		setPenColor(CL);
		setBrushColor(CL);
	}
	else if (x > CM_BUTTON_X_LEFT&&x<CM_BUTTON_X_RIGHT&&y>CM_BUTTON_Y_UP&&y < CM_BUTTON_Y_DOWN) {
		setPenColor(CM);
		setBrushColor(CM);
	}
	else if (x > CN_BUTTON_X_LEFT&&x<CN_BUTTON_X_RIGHT&&y>CN_BUTTON_Y_UP&&y < CN_BUTTON_Y_DOWN) {
		setPenColor(CN);
		setBrushColor(CN);
	}
	else if (x > CO_BUTTON_X_LEFT&&x<CO_BUTTON_X_RIGHT&&y>CO_BUTTON_Y_UP&&y < CO_BUTTON_Y_DOWN) {
		setPenColor(CO);
		setBrushColor(CO);
	}
	else if (x > CP_BUTTON_X_LEFT&&x<CP_BUTTON_X_RIGHT&&y>CP_BUTTON_Y_UP&&y < CP_BUTTON_Y_DOWN) {
		setPenColor(CP);
		setBrushColor(CP);
	}
	else if (x > CQ_BUTTON_X_LEFT&&x<CQ_BUTTON_X_RIGHT&&y>CQ_BUTTON_Y_UP&&y < CQ_BUTTON_Y_DOWN) {
		setPenColor(CQ);
		setBrushColor(CQ);
	}
	else if (x > CR_BUTTON_X_LEFT&&x<CR_BUTTON_X_RIGHT&&y>CR_BUTTON_Y_UP&&y < CR_BUTTON_Y_DOWN) {
		setPenColor(CR);
		setBrushColor(CR);
	}
	else if (x > CS_BUTTON_X_LEFT&&x<CS_BUTTON_X_RIGHT&&y>CS_BUTTON_Y_UP&&y < CS_BUTTON_Y_DOWN) {
		setPenColor(CS);
		setBrushColor(CS);
	}
	else if (x > CT_BUTTON_X_LEFT&&x<CT_BUTTON_X_RIGHT&&y>CT_BUTTON_Y_UP&&y < CT_BUTTON_Y_DOWN) {
		setPenColor(CT);
		setBrushColor(CT);
	}
	return 0;
}
