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
#endif // !MAIN_H