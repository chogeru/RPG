#pragma once
#include "../Base/Base.h"

class Enemy : public Base {
	CImage m_img;
	int m_cnt;
	bool m_flip;
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
