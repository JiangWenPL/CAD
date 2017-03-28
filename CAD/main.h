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
//Color Position defination
#define COORDINATE_ORIGIN 0
#define TOOLS_RIGHT_X 70
#define AA_BUTTON_X_LEFT 965
#define AA_BUTTON_X_RIGHT 984
#define AA_BUTTON_Y_DOWN 52
#define AA_BUTTON_Y_UP 33
#define AB_BUTTON_X_LEFT 965
#define AB_BUTTON_X_RIGHT 984
#define AB_BUTTON_Y_DOWN 71
#define AB_BUTTON_Y_UP 52
#define AC_BUTTON_X_LEFT 965
#define AC_BUTTON_X_RIGHT 984
#define AC_BUTTON_Y_DOWN 90
#define AC_BUTTON_Y_UP 71
#define AD_BUTTON_X_LEFT 965
#define AD_BUTTON_X_RIGHT 984
#define AD_BUTTON_Y_DOWN 109
#define AD_BUTTON_Y_UP 90
#define AE_BUTTON_X_LEFT 965
#define AE_BUTTON_X_RIGHT 984
#define AE_BUTTON_Y_DOWN 128
#define AE_BUTTON_Y_UP 109
#define AF_BUTTON_X_LEFT 965
#define AF_BUTTON_X_RIGHT 984
#define AF_BUTTON_Y_DOWN 147
#define AF_BUTTON_Y_UP 128
#define AG_BUTTON_X_LEFT 965
#define AG_BUTTON_X_RIGHT 984
#define AG_BUTTON_Y_DOWN 166
#define AG_BUTTON_Y_UP 147
#define AH_BUTTON_X_LEFT 965
#define AH_BUTTON_X_RIGHT 984
#define AH_BUTTON_Y_DOWN 185
#define AH_BUTTON_Y_UP 166
#define AI_BUTTON_X_LEFT 965
#define AI_BUTTON_X_RIGHT 984
#define AI_BUTTON_Y_DOWN 204
#define AI_BUTTON_Y_UP 185
#define AJ_BUTTON_X_LEFT 965
#define AJ_BUTTON_X_RIGHT 984
#define AJ_BUTTON_Y_DOWN 223
#define AJ_BUTTON_Y_UP 204
#define AK_BUTTON_X_LEFT 965
#define AK_BUTTON_X_RIGHT 984
#define AK_BUTTON_Y_DOWN 242
#define AK_BUTTON_Y_UP 223
#define AL_BUTTON_X_LEFT 965
#define AL_BUTTON_X_RIGHT 984
#define AL_BUTTON_Y_DOWN 258
#define AL_BUTTON_Y_UP 242
#define AM_BUTTON_X_LEFT 965
#define AM_BUTTON_X_RIGHT 984
#define AM_BUTTON_Y_DOWN 277
#define AM_BUTTON_Y_UP 258
#define AN_BUTTON_X_LEFT 965
#define AN_BUTTON_X_RIGHT 984
#define AN_BUTTON_Y_DOWN 296
#define AN_BUTTON_Y_UP 277
#define AO_BUTTON_X_LEFT 965
#define AO_BUTTON_X_RIGHT 984
#define AO_BUTTON_Y_DOWN 315
#define AO_BUTTON_Y_UP 296
#define AP_BUTTON_X_LEFT 965
#define AP_BUTTON_X_RIGHT 984
#define AP_BUTTON_Y_DOWN 334
#define AP_BUTTON_Y_UP 315
#define AQ_BUTTON_X_LEFT 965
#define AQ_BUTTON_X_RIGHT 984
#define AQ_BUTTON_Y_DOWN 353
#define AQ_BUTTON_Y_UP 334
#define AR_BUTTON_X_LEFT 965
#define AR_BUTTON_X_RIGHT 984
#define AR_BUTTON_Y_DOWN 372
#define AR_BUTTON_Y_UP 353
#define AS_BUTTON_X_LEFT 965
#define AS_BUTTON_X_RIGHT 984
#define AS_BUTTON_Y_DOWN 391
#define AS_BUTTON_Y_UP 372
#define AT_BUTTON_X_LEFT 965
#define AT_BUTTON_X_RIGHT 984
#define AT_BUTTON_Y_DOWN 409
#define AT_BUTTON_Y_UP 391
#define BA_BUTTON_X_LEFT 985
#define BA_BUTTON_X_RIGHT 1004
#define BA_BUTTON_Y_DOWN 52
#define BA_BUTTON_Y_UP 33
#define BB_BUTTON_X_LEFT 985
#define BB_BUTTON_X_RIGHT 1004
#define BB_BUTTON_Y_DOWN 71
#define BB_BUTTON_Y_UP 52
#define BC_BUTTON_X_LEFT 985
#define BC_BUTTON_X_RIGHT 1004
#define BC_BUTTON_Y_DOWN 90
#define BC_BUTTON_Y_UP 71
#define BD_BUTTON_X_LEFT 985
#define BD_BUTTON_X_RIGHT 1004
#define BD_BUTTON_Y_DOWN 109
#define BD_BUTTON_Y_UP 90
#define BE_BUTTON_X_LEFT 985
#define BE_BUTTON_X_RIGHT 1004
#define BE_BUTTON_Y_DOWN 128
#define BE_BUTTON_Y_UP 109
#define BF_BUTTON_X_LEFT 985
#define BF_BUTTON_X_RIGHT 1004
#define BF_BUTTON_Y_DOWN 147
#define BF_BUTTON_Y_UP 128
#define BG_BUTTON_X_LEFT 985
#define BG_BUTTON_X_RIGHT 1004
#define BG_BUTTON_Y_DOWN 166
#define BG_BUTTON_Y_UP 147
#define BH_BUTTON_X_LEFT 985
#define BH_BUTTON_X_RIGHT 1004
#define BH_BUTTON_Y_DOWN 185
#define BH_BUTTON_Y_UP 166
#define BI_BUTTON_X_LEFT 985
#define BI_BUTTON_X_RIGHT 1004
#define BI_BUTTON_Y_DOWN 204
#define BI_BUTTON_Y_UP 185
#define BJ_BUTTON_X_LEFT 985
#define BJ_BUTTON_X_RIGHT 1004
#define BJ_BUTTON_Y_DOWN 223
#define BJ_BUTTON_Y_UP 204
#define BK_BUTTON_X_LEFT 985
#define BK_BUTTON_X_RIGHT 1004
#define BK_BUTTON_Y_DOWN 242
#define BK_BUTTON_Y_UP 223
#define BL_BUTTON_X_LEFT 985
#define BL_BUTTON_X_RIGHT 1004
#define BL_BUTTON_Y_DOWN 258
#define BL_BUTTON_Y_UP 242
#define BM_BUTTON_X_LEFT 985
#define BM_BUTTON_X_RIGHT 1004
#define BM_BUTTON_Y_DOWN 277
#define BM_BUTTON_Y_UP 258
#define BN_BUTTON_X_LEFT 985
#define BN_BUTTON_X_RIGHT 1004
#define BN_BUTTON_Y_DOWN 296
#define BN_BUTTON_Y_UP 277
#define BO_BUTTON_X_LEFT 985
#define BO_BUTTON_X_RIGHT 1004
#define BO_BUTTON_Y_DOWN 315
#define BO_BUTTON_Y_UP 296
#define BP_BUTTON_X_LEFT 985
#define BP_BUTTON_X_RIGHT 1004
#define BP_BUTTON_Y_DOWN 334
#define BP_BUTTON_Y_UP 315
#define BQ_BUTTON_X_LEFT 985
#define BQ_BUTTON_X_RIGHT 1004
#define BQ_BUTTON_Y_DOWN 353
#define BQ_BUTTON_Y_UP 334
#define BR_BUTTON_X_LEFT 985
#define BR_BUTTON_X_RIGHT 1004
#define BR_BUTTON_Y_DOWN 372
#define BR_BUTTON_Y_UP 353
#define BS_BUTTON_X_LEFT 985
#define BS_BUTTON_X_RIGHT 1004
#define BS_BUTTON_Y_DOWN 391
#define BS_BUTTON_Y_UP 372
#define BT_BUTTON_X_LEFT 985
#define BT_BUTTON_X_RIGHT 1004
#define BT_BUTTON_Y_DOWN 409
#define BT_BUTTON_Y_UP 391
#define CA_BUTTON_X_LEFT 1004
#define CA_BUTTON_X_RIGHT 1023
#define CA_BUTTON_Y_DOWN 52
#define CA_BUTTON_Y_UP 33
#define CB_BUTTON_X_LEFT 1004
#define CB_BUTTON_X_RIGHT 1023
#define CB_BUTTON_Y_DOWN 71
#define CB_BUTTON_Y_UP 52
#define CC_BUTTON_X_LEFT 1004
#define CC_BUTTON_X_RIGHT 1023
#define CC_BUTTON_Y_DOWN 90
#define CC_BUTTON_Y_UP 71
#define CD_BUTTON_X_LEFT 1004
#define CD_BUTTON_X_RIGHT 1023
#define CD_BUTTON_Y_DOWN 109
#define CD_BUTTON_Y_UP 90
#define CE_BUTTON_X_LEFT 1004
#define CE_BUTTON_X_RIGHT 1023
#define CE_BUTTON_Y_DOWN 128
#define CE_BUTTON_Y_UP 109
#define CF_BUTTON_X_LEFT 1004
#define CF_BUTTON_X_RIGHT 1023
#define CF_BUTTON_Y_DOWN 147
#define CF_BUTTON_Y_UP 128
#define CG_BUTTON_X_LEFT 1004
#define CG_BUTTON_X_RIGHT 1023
#define CG_BUTTON_Y_DOWN 166
#define CG_BUTTON_Y_UP 147
#define CH_BUTTON_X_LEFT 1004
#define CH_BUTTON_X_RIGHT 1023
#define CH_BUTTON_Y_DOWN 185
#define CH_BUTTON_Y_UP 166
#define CI_BUTTON_X_LEFT 1004
#define CI_BUTTON_X_RIGHT 1023
#define CI_BUTTON_Y_DOWN 204
#define CI_BUTTON_Y_UP 185
#define CJ_BUTTON_X_LEFT 1004
#define CJ_BUTTON_X_RIGHT 1023
#define CJ_BUTTON_Y_DOWN 223
#define CJ_BUTTON_Y_UP 204
#define CK_BUTTON_X_LEFT 1004
#define CK_BUTTON_X_RIGHT 1023
#define CK_BUTTON_Y_DOWN 242
#define CK_BUTTON_Y_UP 223
#define CL_BUTTON_X_LEFT 1004
#define CL_BUTTON_X_RIGHT 1023
#define CL_BUTTON_Y_DOWN 258
#define CL_BUTTON_Y_UP 242
#define CM_BUTTON_X_LEFT 1004
#define CM_BUTTON_X_RIGHT 1023
#define CM_BUTTON_Y_DOWN 277
#define CM_BUTTON_Y_UP 258
#define CN_BUTTON_X_LEFT 1004
#define CN_BUTTON_X_RIGHT 1023
#define CN_BUTTON_Y_DOWN 296
#define CN_BUTTON_Y_UP 277
#define CO_BUTTON_X_LEFT 1004
#define CO_BUTTON_X_RIGHT 1023
#define CO_BUTTON_Y_DOWN 315
#define CO_BUTTON_Y_UP 296
#define CP_BUTTON_X_LEFT 1004
#define CP_BUTTON_X_RIGHT 1023
#define CP_BUTTON_Y_DOWN 334
#define CP_BUTTON_Y_UP 315
#define CQ_BUTTON_X_LEFT 1004
#define CQ_BUTTON_X_RIGHT 1023
#define CQ_BUTTON_Y_DOWN 353
#define CQ_BUTTON_Y_UP 334
#define CR_BUTTON_X_LEFT 1004
#define CR_BUTTON_X_RIGHT 1023
#define CR_BUTTON_Y_DOWN 372
#define CR_BUTTON_Y_UP 353
#define CS_BUTTON_X_LEFT 1004
#define CS_BUTTON_X_RIGHT 1023
#define CS_BUTTON_Y_DOWN 391
#define CS_BUTTON_Y_UP 372
#define CT_BUTTON_X_LEFT 1004
#define CT_BUTTON_X_RIGHT 1023
#define CT_BUTTON_Y_DOWN 409
#define CT_BUTTON_Y_UP 391
//Panels position's Marco definaton.
#define PEN_BUTTON_X_LEFT 0
#define PEN_BUTTON_X_RIGHT 35
#define PEN_BUTTON_Y_UP 25
#define PEN_BUTTON_Y_DOWN 55
#define ERASER_BUTTON_X_LEFT 0
#define ERASER_BUTTON_X_RIGHT
#define ERASER_BUTTON_Y_UP 55
#define ERASER_BUTTON_Y_DOWN 85
#define CRAMING_BUTTON_X_LEFT 0
#define CRAMING_BUTTON_X_RIGHT 35
#define CRAMING_BUTTON_Y_UP 85
#define CRAMING_BUTTON_Y_DOWN 120
#define WORDS_BUTTON_X_LEFT 0
#define WORDS_BUTTON_X_RIGHT 35
#define WORDS_BUTTON_Y_UP 120
#define WORDS_BUTTON_Y_DOWN 155
#define REGULAR_TRIANGLE_BUTTON_X_LEFT 0
#define REGULAR_TRIANGLE_BUTTON_X_RIGHT 35
#define REGULAR_TRIANGLE_BUTTON_Y_UP 155
#define REGULAR_TRIANGLE_BUTTON_Y_DOWN 185
#define RIGHT_TRIANGLE_BUTTON_X_LEFT 0
#define RIGHT_TRIANGLE_BUTTON_X_RIGHT 35
#define RIGHT_TRIANGLE_BUTTON_Y_UP 185
#define RIGHT_TRIANGLE_BUTTON_Y_DOWN 215
#define RHOMBUS_BUTTON_X_LEFT 0
#define RHOMBUS_BUTTON_X_RIGHT 35
#define RHOMBUS_BUTTON_Y_UP 215
#define RHOMBUS_BUTTON_Y_DOWN 250
#define HEXAGON_BUTTON_X_LEFT 0
#define HEXAGON_BUTTON_X_RIGHT 35
#define HEXAGON_BUTTON_Y_UP 250
#define HEXAGON_BUTTON_Y_DOWN 285
#define FIVE_STAR_BUTTON_X_LEFT 0
#define FIVE_STAR_BUTTON_X_RIGHT 35
#define FIVE_STAR_BUTTON_Y_UP 285
#define FIVE_STAR_BUTTON_Y_DOWN 315
#define RIGHT_ARROW_BUTTON_X_LEFT 0
#define RIGHT_ARROW_BUTTON_X_RIGHT 35
#define RIGHT_ARROW_BUTTON_Y_UP 315
#define RIGHT_ARROW_BUTTON_Y_DOWN 350
#define UP_ARROW_BUTTON_X_LEFT 0
#define UP_ARROW_BUTTON_X_RIGHT 35
#define UP_ARROW_BUTTON_Y_UP 350
#define UP_ARROW_BUTTON_Y_DOWN 385
#define SQUARE_DIALOG_BUTTON_X_LEFT 0
#define SQUARE_DIALOG_BUTTON_X_RIGHT 35
#define SQUARE_DIALOG_BUTTON_Y_UP 385
#define SQUARE_DIALOG_BUTTON_Y_DOWN 410
#define LINE_BUTTON_X_LEFT 35
#define LINE_BUTTON_X_RIGHT 70
#define LINE_BUTTON_Y_UP 25
#define LINE_BUTTON_Y_DOWN 55
#define CURVE_BUTTON_X_LEFT 35
#define CURVE_BUTTON_X_RIGHT 70
#define CURVE_BUTTON_Y_UP 55
#define CURVE_BUTTON_Y_DOWN 85
#define CIRCLE_BUTTON_X_LEFT 35
#define CIRCLE_BUTTON_X_RIGHT 70
#define CIRCLE_BUTTON_Y_UP 85
#define CIRCLE_BUTTON_Y_DOWN 120
#define RECTANGLE_BUTTON_X_LEFT 35
#define RECTANGLE_BUTTON_X_RIGHT 70
#define RECTANGLE_BUTTON_Y_UP 120 
#define RECTANGLE_BUTTON_Y_DOWN 155
#define ARC_RECTANGLE_BUTTON_X_LEFT 35
#define ARC_RECTANGLE_BUTTON_X_RIGHT 70
#define ARC_RECTANGLE_BUTTON_Y_UP 155
#define ARC_RECTANGLE_BUTTON_Y_DOWN 185
#define FREE_SHAPE_BUTTON_X_LEFT 35
#define FREE_SHAPE_BUTTON_X_RIGHT 70
#define FREE_SHAPE_BUTTON_Y_UP 185
#define FREE_SHAPE_BUTTON_Y_DOWN 215
#define PENTAGON_BUTTON_X_LEFT 35
#define PENTAGON_BUTTON_X_RIGHT 70
#define PENTAGON_BUTTON_Y_UP 215
#define PENTAGON_BUTTON_Y_DOWN 250
#define FORE_STAR_BUTTON_X_LEFT 35
#define FORE_STAR_BUTTON_X_RIGHT 70
#define FORE_STAR_BUTTON_Y_UP 250
#define FORE_STAR_BUTTON_Y_DOWN 285
#define SIX_STAR_BUTTON_X_LEFT 35
#define SIX_STAR_BUTTON_X_RIGHT 70
#define SIX_STAR_BUTTON_Y_UP 285
#define SIX_STAR_BUTTON_Y_DOWN 315
#define LEFT_ARROW_BUTTON_X_LEFT 35
#define LEFT_ARROW_BUTTON_X_RIGHT 70
#define LEFT_ARROW_BUTTON_Y_UP 315
#define LEFT_ARROW_BUTTON_Y_DOWN 350
#define DOWN_ARROW_BUTTON_X_LEFT 35
#define DOWN_ARROW_BUTTON_X_RIGHT 70
#define DOWN_ARROW_BUTTON_Y_UP 350
#define DOWN_ARROW_BUTTON_Y_DOWN 385
#define CIRCLE_DIALOG_BUTTON_X_LEFT 35
#define CIRCLE_DIALOG_BUTTON_X_RIGHT 70
#define CIRCLE_DIALOG_BUTTON_Y_UP 385
#define CIRCLE_DIALOG_BTTON_Y_DOWN 410
#define CANCLE_BUTTON_X_LEFT 0
#define CANCLE_BUTTON_X_RIGHT 35
#define CANCLE_BUTTON_Y_UP 385
#define CANCLE_BTTON_Y_DOWN 410
#define M_CANCLE 19
//Belowes are RGB color define
#define AA  			RGB(0  ,0, 0)
#define AB  			RGB(64 ,64,64)
#define AC  			RGB(96 ,96,64)
#define AD  			RGB(255  ,255, 0)
#define AE    			RGB(255  ,255, 0)
#define AF  			RGB(224  ,224, 64)
#define AG  			RGB(224  ,160, 0)
#define AH  			RGB(224  ,96, 0)
#define AI  			RGB(224  ,0, 64)
#define AJ  			RGB(160 ,32, 0)
#define AK 				RGB(224  ,96, 192)
#define AL  			RGB(224  ,96, 128)
#define AM 				RGB(160  ,96, 192)
#define AN  			RGB(128  ,96, 128)
#define AO  			RGB(96  ,96, 128)
#define AP  			RGB(96  ,128, 192)
#define AQ  			RGB(64  ,128, 192)
#define AR  			RGB(0  ,192, 192)
#define AS  			RGB(32  ,192, 192)
#define AT  			RGB(64  ,128, 128)
#define BA  			RGB(128,128,128)
#define BB  			RGB(192,192,192)
#define BC  			RGB(192,220,192)
#define BD  			RGB(224,192,64)
#define BE    			RGB(224,224,128)
#define BF  			RGB(192,160, 0)
#define BG  			RGB(192,160, 0)
#define BH  			RGB(32,128,64)
#define BI  			RGB(160  ,96, 0)
#define BJ  			RGB(160  ,64, 0)
#define BK  			RGB(160,96,64)
#define BL  			RGB(128,96,64)
#define BM 				RGB(224  ,0, 64)
#define BN  			RGB(224  ,0, 128)
#define BO 				RGB(160 ,32,128)
#define BP  			RGB(96 ,32,128)
#define BQ  			RGB(32 ,32,128)
#define BR 				RGB(0  ,64,128)
#define BS  			RGB(0  ,64,128)
#define BT  			RGB(64,160,128)
#define CA  			RGB(160,160,164)
#define CB  			RGB(255,251,140)
#define CC  			RGB(255,255,255)
#define CD  			RGB(32,224,64)
#define CE    			RGB(0  ,164,64)
#define CF  			RGB(0  ,96,64)
#define CG 				RGB(64,64,64)
#define CH  			RGB(0  ,96,64)
#define CI 				RGB(0  ,96, 0)
#define CJ 				RGB(64,96, 0)
#define CK  			RGB(128,160,64)
#define CL 				RGB(96,64, 0)
#define CM 				RGB(128,32, 0)
#define CN  			RGB(128,0,0)
#define CO  			RGB(160  ,0, 64)
#define CP 				RGB(96 ,0, 64)
#define CQ 				RGB(64 ,0,128)
#define CR   			RGB(32 ,32,128)
#define CS				RGB(0,0,64)
#define CT  			RGB(0,96,192)

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