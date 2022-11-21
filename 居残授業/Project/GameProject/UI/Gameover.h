#pragma once

#include "../Base/Base.h"

class Gameover : public Base {
private:
	enum {
		eState_Gameover
	};
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_Gameover_text;
public:
	Gameover();
	~Gameover();
	void Update();
	void Draw();
};
