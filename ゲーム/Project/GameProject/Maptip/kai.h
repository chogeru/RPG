#pragma once
#pragma once
#include "../Base/Base.h"
class kai :public Base {
private:
	CVector2D pos;
	CImage m_img;
	int m_hit[3];

public:

	kai(const CVector2D& p);
	void Update();
	void Draw();

};
