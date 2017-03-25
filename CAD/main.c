/*
*    main.c
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 3/14/2017.
*    Copyright (c) 2017 Wen Jiang. All rights reserved.
*/
#include"main.h"
ACL_Color m_CurrentColor = BLACK;
int32_t IO_Init();
int32_t DrawRectangle(int x0, int y0, int size, int style);
int32_t Erase(int x0, int y0, int size, int style);
TimerEventCallback TimerEvent(int timerID);
CharEventCallback CharEvent(char c);
KeyboardEventCallback KeyboardEvent(int key, int event);
MouseEventCallback MouseEvent(int x, int y, int button, int event);

int Setup() {
	initWindow("CAD", DEFAULT, DEFAULT, 1024, 768);
	initConsole();
	IO_Init();
	registerTimerEvent(TimerEvent);
	registerKeyboardEvent(KeyboardEvent);
	registerCharEvent(CharEvent);
	registerMouseEvent(MouseEvent);
	return 0;
}
TimerEventCallback TimerEvent(int timerID) { ; }
CharEventCallback CharEvent(char c) { ; }
KeyboardEventCallback KeyboardEvent(int key, int event) { ; }
MouseEventCallback MouseEvent(int x, int y, int button, int event) { 
	static int flag = 0;
	static int i = 0;
	if (i == 0) {
		DrawRectangle(100, 100, 5, 1);
		i = 1;
	}
	printf("x=%d, y=%d, butoton =%d, event = %d\n", x, y,button,event); 
	if (x > RECTANGLE_X_LEFT && x < RECTANGLE_X_RIGHT && y > RECTANGLE_Y_UP && y < RECTANGLE_Y_DOWN && button ==1 && event ==0 ) {
		flag = 1;
	}else if (x > ERASE_X_LEFT && x < ERASE_X_RIGHT && y > ERASE_Y_UP && y < ERASE_Y_DOWN && button == 1 && event == 0) {
		flag = 3;
	}
	if (0 != flag && button == 1 && event == 0)
	{
		switch (flag) {
		case 1:
			DrawRectangle(x, y, 1, 1);
			flag = 0;
			break;
			//Rectangle tool
		case 3:
			Erase(x, y, 10, 0);
			break;
		}
	}
}
int32_t IO_Init() {
	beginPaint();
	ACL_Image Pallet, DashBoard;
	loadImage(".//pallet.bmp",&Pallet);
	putImage(&Pallet, PALLETX, PALLETY);
	loadImage(".//DashBoard.bmp", &DashBoard);
	putImage(&Pallet, PALLETX, PALLETY);
	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
}
int32_t DrawRectangle(int x0, int y0, int size, int style) {
	switch (style){
	case 1:
		printf("In darw\n");
		beginPaint();
		setPenColor(RED);
		rectangle(x0, y0, x0+size * 30, y0+size * 20);
		endPaint();
	}
}
int32_t Erase(int x0, int y0, int size, int style) {
	switch (style)//0 by default
	{
	default:
		beginPaint();
		setBrushColor(WHITE);
		setPenColor(WHITE);
		printf("In erase\n");
		rectangle(x0, y0, x0 + size, y0 + size);
		endPaint();
		break;
	}
}