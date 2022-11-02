#pragma once
#include "../Base/Base.h"
class Dorup :public Base {
private:
	//画像オブジェクト
	CImage m_img;

public:
	Dorup(const CVector2D& pos);
	void Draw();
};