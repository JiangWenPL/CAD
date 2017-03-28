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
TimerEventCallback TimerEvent(int timerID);
CharEventCallback CharEvent(char c);
KeyboardEventCallback KeyboardEvent(int key, int event);
MouseEventCallback MouseEvent(int x, int y, int button, int event);

int Setup() {
	initWindow("CAD", DEFAULT, DEFAULT, 1024, 768);
	//Deafult 1024*768 windows.
	IO_Init();
	registerTimerEvent(&TimerEvent);
	registerKeyboardEvent(&KeyboardEvent);
	registerCharEvent(&CharEvent);
	registerMouseEvent(&MouseEvent);
	return 0;
}
TimerEventCallback TimerEvent(int timerID) { return END_WITHOUT_ERROR; }
CharEventCallback CharEvent(char c) {
	static int32_t Pre_Pos_x, Pre_Pos_y;
	//To read the num from keyborad.
	if (m_lMode != WORDS_MODE) {
		static int32_t flag_input = 0;
		static int32_t num = 0;
		static MsgQueue Msg;
		int32_t length = 0;
		int32_t length_Temp = num;
		while (length_Temp != FALSE) {
			length++;
			length_Temp = length_Temp / DEXMINAL;
		}
		if (FALSE == flag_input) flag_input = TRUE;
		if (CHAR_ENTER == c) {
			flag_input++;
			num = 0;
		}
		//get input leght to change the carpet
		beginPaint();
		paintText(0, 0, CLEAN_LINE);
		switch (flag_input)//beacue we have 2 variable to read.
		{
		case 0:break;
		case 1:
			//New feature caretpos.
			SetCaretPos(CARET_POSITON_X_SIZE + length*SIZE_PER_CARET, CARET_POSITON_Y);
			showCaret();
			if (isdigit(c)) {
				num = num *  DEXMINAL + c - '0';
			}
			String Dynamic_Size;
			sprintf_s(Dynamic_Size, STRING_LENGTH_MAX, "size = %d pixels", num);
			paintText(0, 0, Dynamic_Size);
			CAD_Msg.Size = num;
			break;
		case 2:
			SetCaretPos(CARET_POSITON_X_STYLE + length*SIZE_PER_CARET, CARET_POSITON_Y);
			if (isdigit(c)) {
				num = num *DEXMINAL + c - '0';
			}
			sprintf_s(Dynamic_Size, STRING_LENGTH_MAX, "style = %d", num);
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
		sprintf_s(Words_Temp, STRING_LENGTH_MAX, "%c", c);
		strcat_s(Words_string, STRING_LENGTH_MAX, Words_Temp);
		paintText(m_Text_Postion_x, m_Text_Postion_y, Words_string);
		int32_t strlength = (int32_t)strlen(Words_string);
		setTextSize(TEXT_SIZE);
		endPaint();
	}
	return END_WITHOUT_ERROR;
}
KeyboardEventCallback KeyboardEvent(int key, int event) {
	if (key == CHAR_ENTER) {
		MsgQueue Msg_Enter;
		Msg_Enter.Style = -1;
		Msg_Enter.Size = -1;
		Push_Back_Msg(&Msg_Enter);
	}
	if (event == MOUSE_LEFT) {
		if (key == KEY_LEFT) {
			String_Index = String_Index - 1;
		}
		else if (key == KEY_RIGHT) {
			String_Index = String_Index + 1;
		}
		else if (key == KEY_BACKSPACE) {
			beginPaint();
			Words_string[String_Index] = '\0';
			setTextSize(TEXT_SIZE*PIXEL_INTESITY);
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
	return 0;
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
	//To find which button was choosen.
	if (x > RECTANGLE_X_LEFT && x < RECTANGLE_X_RIGHT && y > RECTANGLE_Y_UP && y < RECTANGLE_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_RECTANGLE;
	}
	else if (x > PEN_BUTTON_X_LEFT && x < PEN_BUTTON_X_RIGHT && y > PEN_BUTTON_Y_UP && y < PEN_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_PEN;
	}
	else if (x > ERASE_X_LEFT && x < ERASE_X_RIGHT && y > ERASE_Y_UP && y < ERASE_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_ERASE;
	}
	else if (x > CURVE_BUTTON_X_LEFT && x<CURVE_BUTTON_X_RIGHT && y>CURVE_BUTTON_Y_UP && y < CURVE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_CURVE;
	}
	else if (x > CRAMING_BUTTON_X_LEFT && x<CRAMING_BUTTON_X_RIGHT && y>CRAMING_BUTTON_Y_UP && y < CRAMING_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_CRAMING;
	}
	else if (x > LINE_BUTTON_X_LEFT && x< LINE_BUTTON_X_RIGHT && y > LINE_BUTTON_Y_UP && y < LINE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_LINE;
	}

	else if (x > WORDS_BUTTON_X_LEFT && x< WORDS_BUTTON_X_RIGHT && y> WORDS_BUTTON_Y_UP && y < WORDS_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_WORDS;
	}
	else if (x > CIRCLE_BUTTON_X_LEFT && x< CIRCLE_BUTTON_X_RIGHT && y> CIRCLE_BUTTON_Y_UP && y < CIRCLE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_CIRCLE;
	}
	else if (x >REGULAR_TRIANGLE_BUTTON_X_LEFT && x< REGULAR_TRIANGLE_BUTTON_X_RIGHT && y> REGULAR_TRIANGLE_BUTTON_Y_UP && y < REGULAR_TRIANGLE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_REGULAR_TRI;
	}
	else if (x >ARC_RECTANGLE_BUTTON_X_LEFT && x< ARC_RECTANGLE_BUTTON_X_RIGHT && y> ARC_RECTANGLE_BUTTON_Y_UP && y < ARC_RECTANGLE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_ARC_RECTANGLE;
	}
	else if (x >RIGHT_TRIANGLE_BUTTON_X_LEFT && x< RIGHT_TRIANGLE_BUTTON_X_RIGHT && y>RIGHT_TRIANGLE_BUTTON_Y_UP && y < RIGHT_TRIANGLE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_RIGHT_TRIANGLE;
			;
	}
	else if (x >FREE_SHAPE_BUTTON_X_LEFT && x< FREE_SHAPE_BUTTON_X_RIGHT && y>FREE_SHAPE_BUTTON_Y_UP && y <FREE_SHAPE_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_FREE_SHAPE;//12 in contribution
	}
	else if (x >FORE_STAR_BUTTON_X_LEFT && x< FORE_STAR_BUTTON_X_RIGHT && y>FORE_STAR_BUTTON_Y_UP && y < FORE_STAR_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_FOUR_STAR;
	}
	else if (x >PENTAGON_BUTTON_X_LEFT && x< PENTAGON_BUTTON_X_RIGHT && y>PENTAGON_BUTTON_Y_UP && y < PENTAGON_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_PENTAGON;
	}
	else if (x >HEXAGON_BUTTON_X_LEFT && x< HEXAGON_BUTTON_X_RIGHT && y>HEXAGON_BUTTON_Y_UP && y < HEXAGON_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_HEXAGON;
	}
	else if (x >RHOMBUS_BUTTON_X_LEFT && x< RHOMBUS_BUTTON_X_RIGHT && y>RHOMBUS_BUTTON_Y_UP && y < RHOMBUS_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_RHOMBUS;
	}
	else if (x >FIVE_STAR_BUTTON_X_LEFT && x<FIVE_STAR_BUTTON_X_RIGHT && y>FIVE_STAR_BUTTON_Y_UP && y < FIVE_STAR_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_FIVE_STAR;
	}
	else if (x >SIX_STAR_BUTTON_X_LEFT && x<SIX_STAR_BUTTON_X_RIGHT && y>SIX_STAR_BUTTON_Y_UP && y < SIX_STAR_BUTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Please input Size(pixels) and Style. Seperated by enter");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_SIX_STAR;
	}
	else if (x >CANCLE_BUTTON_X_LEFT && x<CANCLE_BUTTON_X_RIGHT && y>CANCLE_BUTTON_Y_UP && y < CANCLE_BTTON_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		beginPaint();
		setPenColor(BLACK);
		paintText(0, 0, CLEAN_LINE);
		paintText(0, 0, "Clearing device");
		setPenColor(m_CurrentColor);
		endPaint();
		m_lMode = M_CANCLE;
	}
	else if (x >COLORS_X_LEFT && x<COLORS_X_RIGHT && y>COLORS_Y_UP && y < COLORS_Y_DOWN && button == MOUSE_LEFT && event == CLICK) {
		pickcolor( x,  y);
	}
	if (0 != m_lMode && PressDown == 1)
		//Beacuse we have varible PressDown we don't care the event and button.
	{
		switch (m_lMode) {
		case M_RECTANGLE:
			DrawRectangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
			//Rectangle tool
		case M_PEN:
			Pen(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_CURVE:
			DrawCurve(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;

		case M_ERASE:
			Erase(x, y, CAD_Msg.Size, CAD_Msg.Style);
			//Erase mode.
			break;
		case M_CRAMING:
			Craming(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_LINE:
			StraightLine(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_WORDS:
			Words(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_REGULAR_TRI:
			Regular_Triangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_ARC_RECTANGLE:
			Arc_Rectangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_RIGHT_TRIANGLE:
			Right_Triangle(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_RHOMBUS:
			Rhombus(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_PENTAGON:
			DrawPentagon(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_HEXAGON:
			Hexagon(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_FOUR_STAR:
			ForeStar(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_FIVE_STAR:
			Five_Star(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_SIX_STAR:
			Six_Star(x, y, CAD_Msg.Size, CAD_Msg.Style);
			break;
		case M_CANCLE:
			Cancle(COORDINATE_ORIGIN, COORDINATE_ORIGIN,CAD_Msg.Size, CAD_Msg.Style);
			break;
		}
	}
	return 0;
}
int32_t IO_Init() {
	p_MsgHead = NewMsgQueue();
	CAD_Msg.Size = 10;
	CAD_Msg.Style = 1;
	//initConsole();
	beginPaint();
	//Put the background image and dashborad, clolor pallet.
	ACL_Image Pallet, DashBoard;
	loadImage(".//pallet.bmp", &Pallet);
	putImage(&Pallet, PALLETX, PALLETY);
	loadImage(".//DashBoard.bmp", &DashBoard);
	putImage(&Pallet, PALLETX, PALLETY);
	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
	return 0;
}