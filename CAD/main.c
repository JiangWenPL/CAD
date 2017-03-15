/*
*    main.c
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 3/14/2017.
*    Copyright (c) 2017 Wen Jiang. All rights reserved.
*/
#include"main.h"
TimerEventCallback TimerEvent(int timerID);
CharEventCallback CharEvent(char c);
KeyboardEventCallback KeyboardEvent(int key, int event);
MouseEventCallback MouseEvent(int x, int y, int button, int event);
int Setup() {
	initWindow("CAD", DEFAULT, DEFAULT, 1024, 768);
	initConsole();
	registerTimerEvent(TimerEvent);
	registerKeyboardEvent(KeyboardEvent);
	registerCharEvent(CharEvent);
	registerMouseEvent(MouseEvent);
	return 0;
}
TimerEventCallback TimerEvent(int timerID) { ; }
CharEventCallback CharEvent(char c) { ; }
KeyboardEventCallback KeyboardEvent(int key, int event) { ; }
MouseEventCallback MouseEvent(int x, int y, int button, int event) { printf("x=%d, y=%d\n", x, y); }