#pragma once
#include "../Base/Base.h"
class Gauge :public Base {
private:
	CVector2D pos;
	CImage m_img;
public:
	
	Gauge(const CVector2D& p);
	void Update();
	void Draw();
	
};