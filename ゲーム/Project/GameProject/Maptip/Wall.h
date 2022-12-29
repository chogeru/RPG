#pragma once
#include "../Base/Base.h"
class Wall :public Base {
private:
	//画像オブジェクト
	CImage m_img;

public:
	Wall(const CVector2D& pos);
	void Draw();
};
