/*
*    main.c
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 3/14/2017.
*    Copyright (c) 2017 Wen Jiang. All rights reserved.
*/
#include"main.h"
int32_t IO_Init();
int32_t DrawRectangle(int x0, int y0, int size, int style);
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
	DrawRectangle(100, 100, 5, 1);
	printf("x=%d, y=%d, butoton =%d, event = %d\n", x, y,button,event); 
	if (x > RECTANGLE_X_LEFT && x < RECTANGLE_X_RIGHT && y > RECTANGLE_Y_UP && y < RECTANGLE_Y_DOWN && button ==1 && event ==0 ) {
		flag = 1;
	}
	if (flag ==1 && event ==0 && button ==1) {
		DrawRectangle(x, y, 1, 1);
		flag = 0;
	}
	beginPaint();
	endPaint();

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