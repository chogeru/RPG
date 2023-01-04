#pragma once
#include "../Base/Base.h"
class kaisou :public Base {
private:
	//画像オブジェクト
	CImage m_img;
	CVector2D pos;
	int m_cut;
	bool m_hit_fuda;
public:
	kaisou(const CVector2D& p);
	void Update();
	void Draw();

};

