#pragma once
#include "../Base/Base.h"
class Dordown :public Base {
private:
	//画像オブジェクト
	CImage m_img;

public:
	Dordown(const CVector2D& pos);
	void Draw();
};
