/*
*    main.h
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li jianing.
*    This file was created by Wen Jiang on 3/14/2017.
*    Copyright (c) 2017 Wen Jiang. All rights reserved.
*/
#pragma once
#ifndef MAIN_H
#define MAIN_H

#include "acllib.h"
#include<stdio.h>
#include"Functions.h"
#include"ColorMoudule.h"
#pragma warning(disable:4244)
#pragma warning(disable:4047)
#pragma warning(disable:4024)
#define STRING_LENGTH_MAX 100
/*Use typedefine to set our own type. WJ*/
typedef int int32_t;
typedef unsigned int  uint32_t;
typedef char char8_t;

typedef unsigned char uchar8_t;
typedef double double64_t;
typedef struct MSGQUEUE {
	int32_t Size;
	int32_t Style;
	struct MSGQUEUE *pNext;
}MsgQueue;
typedef char String[STRING_LENGTH_MAX];
extern int32_t m_lMode;
extern int32_t String_Index;
extern char Words_string[100];
extern int32_t m_Text_Postion_x;
extern int32_t m_Text_Postion_y;
extern ACL_Color m_CurrentColor;
extern MsgQueue* p_MsgHead;
extern MsgQueue CAD_Msg;
int32_t IO_Init();
int32_t Pen(int x0, int y0, int size, int style);
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
int32_t Cancle(int x0, int y0, int size, int style);
int32_t StraightLine(int x0, int y0, int size, int style);
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
//ToolsModes
#define END_WITHOUT_ERROR 0
#define M_PEN 1
#define M_LINE 2
#define  M_ERASE 3
#define M_CURVE 4
#define M_CRAMING 5
#define M_CIRCLE 6
#define M_WORDS 7
#define M_RECTANGLE 8
#define M_REGULAR_TRI 9
#define M_ARC_RECTANGLE 10
#define M_RIGHT_TRIANGLE 11
#define  M_FREE_SHAPE 12
#define  M_RHOMBUS 13
#define M_PENTAGON 14
#define M_HEXAGON 15
#define M_FIVE_STAR 17
#define M_FOUR_STAR 16
#define M_SIX_STAR 18
//Status
#define TRUE 1
#define FALSE 0
#define OFF -1
#define MOUSE_LEFT 1
#define CLICK 0
//Constants
#define PALLETX 960
#define PALLETY 20
#define DASHBOARDX 0
#define DASHBOARDY 20
#define RECTANGLE_X_LEFT 45
#define RECTANGLE_X_RIGHT 75
#define RECTANGLE_Y_UP 125
#define RECTANGLE_Y_DOWN 145
#define ERASE_X_LEFT 0
#define ERASE_X_RIGHT 30
#define ERASE_Y_UP 55
#define ERASE_Y_DOWN 85
#define PANEL_BUNDARY_LEFT 75
#define PANEL_BUNDARY_RIGHT 960
#define PANEL_BUNDARY_DOWN 740
#define CHAR_ENTER 13
#define CARET_POSITON_Y 5
#define CARET_POSITON_X_SIZE 50
#define CARET_POSITON_X_STYLE 55
#define SIZE_PER_CARET 7
#define MAX_STYLE 2
#define MIN_STYLE 1
#define TEXT_SIZE 30
#define WORDS_MODE 7
#define CLEAN_LINE "                                                                                                                                                                                        "

#define COLORS_X_LEFT 955
#define COLORS_X_RIGHT 1024
#define COLORS_Y_UP 25
#define COLORS_Y_DOWN 415
#define KEY_LEFT 37
#define KEY_RIGHT 39
#define KEY_BACKSPACE 8
#define PIXEL_INTESITY 3
#define DEXMINAL 10
#define STRING_LENGTH 16
#endif // !MAIN_H