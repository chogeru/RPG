#pragma once
#include "../Base/Base.h"
class Wallhed :public Base {
private:
	//画像オブジェクト
	CImage m_img;

public:
	Wallhed(const CVector2D& pos);
	void Draw();
};
