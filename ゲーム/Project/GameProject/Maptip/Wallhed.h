#pragma once
#include "../Base/Base.h"
class Wallhed :public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;

public:
	Wallhed(const CVector2D& pos);
	void Draw();
};
