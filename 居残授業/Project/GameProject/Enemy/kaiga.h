#pragma once
#include"../Base/Base.h"
#include"../h.h"


class kaiga : public Base {
	CImage m_img;
	int m_cnt;
	bool m_flip;
public:
	kaiga(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};