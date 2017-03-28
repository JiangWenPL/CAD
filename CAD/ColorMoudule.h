/*
*    ColorMoudule.h
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 3/28 2017.
*    Copyright (c) 2017 Wen Jiang,Huang Nianmei, Li Jianing. All rights reserved.
*/
#pragma once
#ifndef COLORMODULE_H
#define COLORMODULE_H
#include"main.h"

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
#pragma warning(disable:4244)
#pragma warning(disable:4047)
#pragma warning(disable:4024)
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
#endif // !COLORMODULE_H
