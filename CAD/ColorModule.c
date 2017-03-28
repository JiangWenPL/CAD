/*
*    ColorModule.c
*    C Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 3/28/2017.
*    Copyright (c) 2017 Wen Jiang,Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"ColorMoudule.h"
int32_t pickcolor(int x, int y)
{
	beginPaint();
	//Contorled by the defination of marco to pick the right color.
	if (x < AA_BUTTON_X_LEFT || y<AA_BUTTON_Y_UP || y>AT_BUTTON_Y_DOWN)return -1;
	if (x > AA_BUTTON_X_LEFT&&x<AA_BUTTON_X_RIGHT&&y>AA_BUTTON_Y_UP&&y < AA_BUTTON_Y_DOWN) {
		setPenColor(AA);
		setBrushColor(AA);
		m_CurrentColor = AA;
	}
	else if (x > AB_BUTTON_X_LEFT&&x<AB_BUTTON_X_RIGHT&&y>AB_BUTTON_Y_UP&&y < AB_BUTTON_Y_DOWN) {
		setPenColor(AB);
		setBrushColor(AB);
		m_CurrentColor = AB;
	}
	else if (x > AC_BUTTON_X_LEFT&&x<AC_BUTTON_X_RIGHT&&y>AC_BUTTON_Y_UP&&y < AC_BUTTON_Y_DOWN) {
		setPenColor(AC);
		setBrushColor(AC);
		m_CurrentColor = AC;
	}
	else if (x > AD_BUTTON_X_LEFT&&x<AD_BUTTON_X_RIGHT&&y>AD_BUTTON_Y_UP&&y < AD_BUTTON_Y_DOWN) {
		setPenColor(AD);
		setBrushColor(AD);
		m_CurrentColor = AD;
	}
	else if (x > AE_BUTTON_X_LEFT&&x<AE_BUTTON_X_RIGHT&&y>AE_BUTTON_Y_UP&&y < AE_BUTTON_Y_DOWN) {
		setPenColor(AE);
		setBrushColor(AE);
		m_CurrentColor = AE;
	}
	else if (x > AF_BUTTON_X_LEFT&&x<AF_BUTTON_X_RIGHT&&y>AF_BUTTON_Y_UP&&y < AF_BUTTON_Y_DOWN) {
		setPenColor(AF);
		setBrushColor(AF);
		m_CurrentColor = AF;
	}
	else if (x > AG_BUTTON_X_LEFT&&x<AG_BUTTON_X_RIGHT&&y>AG_BUTTON_Y_UP&&y < AG_BUTTON_Y_DOWN) {
		setPenColor(AG);
		setBrushColor(AG);
		m_CurrentColor = AG;
	}
	else if (x > AH_BUTTON_X_LEFT&&x<AH_BUTTON_X_RIGHT&&y>AH_BUTTON_Y_UP&&y < AH_BUTTON_Y_DOWN) {
		setPenColor(AH);
		setBrushColor(AH);
		m_CurrentColor = AH;
	}
	else if (x > AI_BUTTON_X_LEFT&&x<AI_BUTTON_X_RIGHT&&y>AI_BUTTON_Y_UP&&y < AI_BUTTON_Y_DOWN) {
		setPenColor(AI);
		setBrushColor(AI);
		m_CurrentColor = AI;
	}
	else if (x > AJ_BUTTON_X_LEFT&&x<AJ_BUTTON_X_RIGHT&&y>AJ_BUTTON_Y_UP&&y < AJ_BUTTON_Y_DOWN) {
		setPenColor(AJ);
		setBrushColor(AJ);
		m_CurrentColor = AJ;
	}
	else if (x > AK_BUTTON_X_LEFT&&x<AK_BUTTON_X_RIGHT&&y>AK_BUTTON_Y_UP&&y < AK_BUTTON_Y_DOWN) {
		setPenColor(AK);
		setBrushColor(AK);
		m_CurrentColor = AK;
	}
	else if (x > AL_BUTTON_X_LEFT&&x<AL_BUTTON_X_RIGHT&&y>AL_BUTTON_Y_UP&&y < AL_BUTTON_Y_DOWN) {
		setPenColor(AL);
		setBrushColor(AL);
		m_CurrentColor = AL;
	}
	else if (x > AM_BUTTON_X_LEFT&&x<AM_BUTTON_X_RIGHT&&y>AM_BUTTON_Y_UP&&y < AM_BUTTON_Y_DOWN) {
		setPenColor(AM);
		setBrushColor(AM);
		m_CurrentColor = AM;
	}
	else if (x > AN_BUTTON_X_LEFT&&x<AN_BUTTON_X_RIGHT&&y>AN_BUTTON_Y_UP&&y < AN_BUTTON_Y_DOWN) {
		setPenColor(AN);
		setBrushColor(AN);
		m_CurrentColor = AN;
	}
	else if (x > AO_BUTTON_X_LEFT&&x<AO_BUTTON_X_RIGHT&&y>AO_BUTTON_Y_UP&&y < AO_BUTTON_Y_DOWN) {
		setPenColor(AO);
		setBrushColor(AO);
		m_CurrentColor = AO;
	}
	else if (x > AP_BUTTON_X_LEFT&&x<AP_BUTTON_X_RIGHT&&y>AP_BUTTON_Y_UP&&y < AP_BUTTON_Y_DOWN) {
		setPenColor(AP);
		setBrushColor(AP);
		m_CurrentColor = AP;
	}
	else if (x > AQ_BUTTON_X_LEFT&&x<AQ_BUTTON_X_RIGHT&&y>AQ_BUTTON_Y_UP&&y < AQ_BUTTON_Y_DOWN) {
		setPenColor(AQ);
		setBrushColor(AQ);
		m_CurrentColor = AQ;
	}
	else if (x > AR_BUTTON_X_LEFT&&x<AR_BUTTON_X_RIGHT&&y>AR_BUTTON_Y_UP&&y < AR_BUTTON_Y_DOWN) {
		setPenColor(AR);
		setBrushColor(AR);
		m_CurrentColor = AR;
	}
	else if (x > AS_BUTTON_X_LEFT&&x<AS_BUTTON_X_RIGHT&&y>AS_BUTTON_Y_UP&&y < AS_BUTTON_Y_DOWN) {
		setPenColor(AS);
		setBrushColor(AS);
		m_CurrentColor = AS;
	}
	else if (x > AT_BUTTON_X_LEFT&&x<AT_BUTTON_X_RIGHT&&y>AT_BUTTON_Y_UP&&y < AT_BUTTON_Y_DOWN) {
		setPenColor(AT);
		setBrushColor(AT);
		m_CurrentColor = AT;
	}
	else if (x > BA_BUTTON_X_LEFT&&x<BA_BUTTON_X_RIGHT&&y>BA_BUTTON_Y_UP&&y < BA_BUTTON_Y_DOWN) {
		setPenColor(BA);
		setBrushColor(BA);
		m_CurrentColor = BA;
	}
	else if (x > BB_BUTTON_X_LEFT&&x<BB_BUTTON_X_RIGHT&&y>BB_BUTTON_Y_UP&&y < BB_BUTTON_Y_DOWN) {
		setPenColor(BB);
		setBrushColor(BB);
		m_CurrentColor = BB;
	}
	else if (x > BC_BUTTON_X_LEFT&&x<BC_BUTTON_X_RIGHT&&y>BC_BUTTON_Y_UP&&y < BC_BUTTON_Y_DOWN) {
		setPenColor(BC);
		setBrushColor(BC);
		m_CurrentColor = BC;
	}
	else if (x > BD_BUTTON_X_LEFT&&x<BD_BUTTON_X_RIGHT&&y>BD_BUTTON_Y_UP&&y < BD_BUTTON_Y_DOWN) {
		setPenColor(BD);
		setBrushColor(BD);
		m_CurrentColor = BD;
	}
	else if (x > BE_BUTTON_X_LEFT&&x<BE_BUTTON_X_RIGHT&&y>BE_BUTTON_Y_UP&&y < BE_BUTTON_Y_DOWN) {
		setPenColor(BE);
		setBrushColor(BE);
		m_CurrentColor = BE;
	}
	else if (x > BF_BUTTON_X_LEFT&&x<BF_BUTTON_X_RIGHT&&y>BF_BUTTON_Y_UP&&y < BF_BUTTON_Y_DOWN) {
		setPenColor(BF);
		setBrushColor(BF);
		m_CurrentColor = BF;
	}
	else if (x > BG_BUTTON_X_LEFT&&x<BG_BUTTON_X_RIGHT&&y>BG_BUTTON_Y_UP&&y < BG_BUTTON_Y_DOWN) {
		setPenColor(BG);
		setBrushColor(BG);
		m_CurrentColor = BG;
	}
	else if (x > BH_BUTTON_X_LEFT&&x<BH_BUTTON_X_RIGHT&&y>BH_BUTTON_Y_UP&&y < BH_BUTTON_Y_DOWN) {
		setPenColor(BH);
		setBrushColor(BH);
		m_CurrentColor = BH;
	}
	else if (x > BI_BUTTON_X_LEFT&&x<BI_BUTTON_X_RIGHT&&y>BI_BUTTON_Y_UP&&y < BI_BUTTON_Y_DOWN) {
		setPenColor(BI);
		setBrushColor(BI);
		m_CurrentColor = BI;
	}
	else if (x > BJ_BUTTON_X_LEFT&&x<BJ_BUTTON_X_RIGHT&&y>BJ_BUTTON_Y_UP&&y < BJ_BUTTON_Y_DOWN) {
		setPenColor(BJ);
		setBrushColor(BJ);
		m_CurrentColor = BJ;
	}
	else if (x > BK_BUTTON_X_LEFT&&x<BK_BUTTON_X_RIGHT&&y>BK_BUTTON_Y_UP&&y < BK_BUTTON_Y_DOWN) {
		setPenColor(BK);
		setBrushColor(BK);
		m_CurrentColor = BK;
	}
	else if (x > BL_BUTTON_X_LEFT&&x<BL_BUTTON_X_RIGHT&&y>BL_BUTTON_Y_UP&&y < BL_BUTTON_Y_DOWN) {
		setPenColor(BL);
		setBrushColor(BL);
		m_CurrentColor = BL;
	}
	else if (x > BM_BUTTON_X_LEFT&&x<BM_BUTTON_X_RIGHT&&y>BM_BUTTON_Y_UP&&y < BM_BUTTON_Y_DOWN) {
		setPenColor(BM);
		setBrushColor(BM);
		m_CurrentColor = BM;
	}
	else if (x > BN_BUTTON_X_LEFT&&x<BN_BUTTON_X_RIGHT&&y>BN_BUTTON_Y_UP&&y < BN_BUTTON_Y_DOWN) {
		setPenColor(BN);
		setBrushColor(BN);
		m_CurrentColor = BN;
	}
	else if (x > BO_BUTTON_X_LEFT&&x<BO_BUTTON_X_RIGHT&&y>BO_BUTTON_Y_UP&&y < BO_BUTTON_Y_DOWN) {
		setPenColor(BO);
		setBrushColor(BO);
		m_CurrentColor = BO;
	}
	else if (x > BP_BUTTON_X_LEFT&&x<BP_BUTTON_X_RIGHT&&y>BP_BUTTON_Y_UP&&y < BP_BUTTON_Y_DOWN) {
		setPenColor(BP);
		setBrushColor(BP);
		m_CurrentColor = BP;
	}
	else if (x > BQ_BUTTON_X_LEFT&&x<BQ_BUTTON_X_RIGHT&&y>BQ_BUTTON_Y_UP&&y < BQ_BUTTON_Y_DOWN) {
		setPenColor(BQ);
		setBrushColor(BQ);
		m_CurrentColor = BQ;
	}
	else if (x > BR_BUTTON_X_LEFT&&x<BR_BUTTON_X_RIGHT&&y>BR_BUTTON_Y_UP&&y < BR_BUTTON_Y_DOWN) {
		setPenColor(BR);
		setBrushColor(BR);
		m_CurrentColor = BR;
	}
	else if (x > BS_BUTTON_X_LEFT&&x<BS_BUTTON_X_RIGHT&&y>BS_BUTTON_Y_UP&&y < BS_BUTTON_Y_DOWN) {
		setPenColor(BS);
		setBrushColor(BS);
		m_CurrentColor = BS;
	}
	else if (x > BT_BUTTON_X_LEFT&&x<BT_BUTTON_X_RIGHT&&y>BT_BUTTON_Y_UP&&y < BT_BUTTON_Y_DOWN) {
		setPenColor(BT);
		setBrushColor(BT);
		m_CurrentColor = BT;
	}
	else if (x > CA_BUTTON_X_LEFT&&x<CA_BUTTON_X_RIGHT&&y>CA_BUTTON_Y_UP&&y < CA_BUTTON_Y_DOWN) {
		setPenColor(CA);
		setBrushColor(CA);
		m_CurrentColor = CA;
	}
	else if (x > CB_BUTTON_X_LEFT&&x<CB_BUTTON_X_RIGHT&&y>CB_BUTTON_Y_UP&&y < CB_BUTTON_Y_DOWN) {
		setPenColor(CB);
		setBrushColor(CB);
		m_CurrentColor = CB;
	}
	else if (x > CC_BUTTON_X_LEFT&&x<CC_BUTTON_X_RIGHT&&y>CC_BUTTON_Y_UP&&y < CC_BUTTON_Y_DOWN) {
		setPenColor(CC);
		setBrushColor(CC);
		m_CurrentColor = CC;
	}
	else if (x > CD_BUTTON_X_LEFT&&x<CD_BUTTON_X_RIGHT&&y>CD_BUTTON_Y_UP&&y < CD_BUTTON_Y_DOWN) {
		setPenColor(CD);
		setBrushColor(CD);
		m_CurrentColor = CD;
	}
	else if (x > CE_BUTTON_X_LEFT&&x<CE_BUTTON_X_RIGHT&&y>CE_BUTTON_Y_UP&&y < CE_BUTTON_Y_DOWN) {
		setPenColor(CE);
		setBrushColor(CE);
		m_CurrentColor = CE;
	}
	else if (x > CF_BUTTON_X_LEFT&&x<CF_BUTTON_X_RIGHT&&y>CF_BUTTON_Y_UP&&y < CF_BUTTON_Y_DOWN) {
		setPenColor(CF);
		setBrushColor(CF);
		m_CurrentColor = CF;
	}
	else if (x > CG_BUTTON_X_LEFT&&x<CG_BUTTON_X_RIGHT&&y>CG_BUTTON_Y_UP&&y < CG_BUTTON_Y_DOWN) {
		setPenColor(CG);
		setBrushColor(CG);
		m_CurrentColor = CG;
	}
	else if (x > CH_BUTTON_X_LEFT&&x<CH_BUTTON_X_RIGHT&&y>CH_BUTTON_Y_UP&&y < CH_BUTTON_Y_DOWN) {
		setPenColor(CH);
		setBrushColor(CH);
		m_CurrentColor = CH;
	}
	else if (x > CI_BUTTON_X_LEFT&&x<CI_BUTTON_X_RIGHT&&y>CI_BUTTON_Y_UP&&y < CI_BUTTON_Y_DOWN) {
		setPenColor(CI);
		setBrushColor(CI);
		m_CurrentColor = CI;
	}
	else if (x > CJ_BUTTON_X_LEFT&&x<CJ_BUTTON_X_RIGHT&&y>CJ_BUTTON_Y_UP&&y < CJ_BUTTON_Y_DOWN) {
		setPenColor(CJ);
		setBrushColor(CJ);
		m_CurrentColor = CJ;
	}
	else if (x > CK_BUTTON_X_LEFT&&x<CK_BUTTON_X_RIGHT&&y>CK_BUTTON_Y_UP&&y < CK_BUTTON_Y_DOWN) {
		setPenColor(CK);
		setBrushColor(CK);
		m_CurrentColor = CK;
	}
	else if (x > CL_BUTTON_X_LEFT&&x<CL_BUTTON_X_RIGHT&&y>CL_BUTTON_Y_UP&&y < CL_BUTTON_Y_DOWN) {
		setPenColor(CL);
		setBrushColor(CL);
		m_CurrentColor = CL;
	}
	else if (x > CM_BUTTON_X_LEFT&&x<CM_BUTTON_X_RIGHT&&y>CM_BUTTON_Y_UP&&y < CM_BUTTON_Y_DOWN) {
		setPenColor(CM);
		setBrushColor(CM);
		m_CurrentColor = CM;
	}
	else if (x > CN_BUTTON_X_LEFT&&x<CN_BUTTON_X_RIGHT&&y>CN_BUTTON_Y_UP&&y < CN_BUTTON_Y_DOWN) {
		setPenColor(CN);
		setBrushColor(CN);
		m_CurrentColor = CN;
	}
	else if (x > CO_BUTTON_X_LEFT&&x<CO_BUTTON_X_RIGHT&&y>CO_BUTTON_Y_UP&&y < CO_BUTTON_Y_DOWN) {
		setPenColor(CO);
		setBrushColor(CO);
		m_CurrentColor = CO;
	}
	else if (x > CP_BUTTON_X_LEFT&&x<CP_BUTTON_X_RIGHT&&y>CP_BUTTON_Y_UP&&y < CP_BUTTON_Y_DOWN) {
		setPenColor(CP);
		setBrushColor(CP);
		m_CurrentColor = CP;
	}
	else if (x > CQ_BUTTON_X_LEFT&&x<CQ_BUTTON_X_RIGHT&&y>CQ_BUTTON_Y_UP&&y < CQ_BUTTON_Y_DOWN) {
		setPenColor(CQ);
		setBrushColor(CQ);
		m_CurrentColor = CQ;
	}
	else if (x > CR_BUTTON_X_LEFT&&x<CR_BUTTON_X_RIGHT&&y>CR_BUTTON_Y_UP&&y < CR_BUTTON_Y_DOWN) {
		setPenColor(CR);
		setBrushColor(CR);
		m_CurrentColor = CR;
	}
	else if (x > CS_BUTTON_X_LEFT&&x<CS_BUTTON_X_RIGHT&&y>CS_BUTTON_Y_UP&&y < CS_BUTTON_Y_DOWN) {
		setPenColor(CS);
		setBrushColor(CS);
		m_CurrentColor = CS;
	}
	else if (x > CT_BUTTON_X_LEFT&&x<CT_BUTTON_X_RIGHT&&y>CT_BUTTON_Y_UP&&y < CT_BUTTON_Y_DOWN) {
		setPenColor(CT);
		setBrushColor(CT);
		m_CurrentColor = CT;
	}
	endPaint();
	return 0;
}