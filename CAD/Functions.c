#include"Functions.h"
int32_t Erase(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = TRUE;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			//Rectangle erase
			beginPaint();
			setBrushColor(WHITE);
			setPenColor(WHITE);
			rectangle(x0, y0, x0 + size, y0 + size);
			setBrushColor(m_CurrentColor);
			setPenColor(m_CurrentColor);
			endPaint();
			break;
		case 2:
			//Round erase
			beginPaint();
			setBrushColor(WHITE);
			setPenColor(WHITE);
			ellipse(x0, y0, x0 + size, y0 + size);
			setBrushColor(m_CurrentColor);
			setPenColor(m_CurrentColor);
			endPaint();
			break;
		default:
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
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
			//rectangle
			beginPaint();
			rectangle(x0, y0, x0 + size, y0 + size);
			endPaint();
			break;
		case 2:
			//round
			beginPaint();
			ellipse(x0, y0, x0 + size, y0 + size);
			endPaint();
			break;
		default:
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;
}
MsgQueue* NewMsgQueue() {
	MsgQueue *p_Temp = (MsgQueue*)malloc(sizeof(MsgQueue));
	p_Temp->pNext = NULL;
	return p_Temp;
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
	if (Pre_x < TOOLS_RIGHT_X) {
		Pre_x = x0;
		Pre_y = y0;
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
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
		//Becaseuse it is seperated by enter, so we have 3 switch to cope with it.
	}
	if (Pen_Times == TRUE) {//To avoid the color always change.
		beginPaint();
		setPenColor(m_CurrentColor);
		Pen_Times = OFF;
		endPaint();
	}
	Pre_x = x0;
	Pre_y = y0;
	return 0;
}
int32_t Words(int x0, int y0, int size, int style) {
	beginPaint();
	SetCaretPos(x0, y0);
	// let the careT show.
	showCaret();
	endPaint();
	m_Text_Postion_x = x0;
	m_Text_Postion_y = y0;
	//Set the position
	return 0;
}
//Draw the geometry figure.
int32_t DrawRectangle(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;
}
int32_t	Regular_Triangle(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;
}
int32_t Right_Triangle(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 3", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;

}
int32_t DrawPentagon(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;

}
int32_t Hexagon(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;

}
int32_t Rhombus(int x0, int y0, int size, int style)
{
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;

}
int32_t Five_Star(int x0, int y0, int size, int style)
{
	int s;
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;

}
int32_t Six_Star(int x0, int y0, int size, int style)
{
	int s;
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;

}
int32_t Arc_Rectangle(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;
}

int32_t ForeStar(int x0, int y0, int size, int style) {

	int s;
	static int32_t Alert_Flag = TRUE;
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
			msgBox("Style out of range", "Please input style range from 1 to 1", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	return 0;
}
int32_t Pen(int x0, int y0, int size, int style) {
	static int32_t Pen_Times = 0;
	static int32_t Alert_Flag = TRUE;
	static int32_t Pre_x = 0, Pre_y = 0;
	if (x0 > PANEL_BUNDARY_LEFT && x0 < PANEL_BUNDARY_RIGHT && y0 < PANEL_BUNDARY_DOWN && abs(x0 - Pre_x) < 20 && abs(y0 - Pre_y) < 20) {
		//Encapulse the conditon to a bool lean function in the future.
		//If-statement to avoid paint the panel.
		switch (style)//0 by default
		{
		case 1:
			beginPaint();
			setPenWidth(size);
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
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}
	if (Pen_Times == TRUE) {
		beginPaint();
		setPenColor(m_CurrentColor);
		Pen_Times = OFF;
		endPaint();
	}
	Pre_x = x0;
	Pre_y = y0;
	return END_WITHOUT_ERROR;
}
int32_t DrawCurve(int x0, int y0, int size, int style) {
	static int32_t Alert_Flag = TRUE;
	static int32_t Pre_x = 0, Pre_y = 0;

	if (Pre_x < TOOLS_RIGHT_X) {
		Pre_x = x0;
		Pre_y = y0;
	}
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
			msgBox("Style out of range", "Please input style range from 1 to 2", Alert_Flag);
			Alert_Flag = OFF;
			break;
		}
	}

	Pre_x = x0;
	Pre_y = y0;
	return 0;
}
int32_t Cancle(int x0, int y0, int size, int style) {
	beginPaint();
	clearDevice();
	ACL_Image Pallet, DashBoard;
	loadImage(".//pallet.bmp", &Pallet);
	putImage(&Pallet, PALLETX, PALLETY);
	loadImage(".//DashBoard.bmp", &DashBoard);
	putImage(&Pallet, PALLETX, PALLETY);
	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
	return END_WITHOUT_ERROR;
}