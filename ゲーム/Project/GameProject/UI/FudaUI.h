#pragma once
#include "../Base/Base.h"
class FudaUI :public Base {
private:
	CVector2D pos;
	CImage m_img;
	

public:

	FudaUI(const CVector2D& p);
	void Update();
	void Draw();

};
