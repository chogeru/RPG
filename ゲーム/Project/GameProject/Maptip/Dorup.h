#pragma once
#include "../Base/Base.h"
class Dorup :public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;

public:
	Dorup(const CVector2D& pos);
	void Draw();
};