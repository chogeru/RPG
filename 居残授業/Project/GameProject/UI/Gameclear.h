#pragma once
#include "../Base/Base.h"
#include"../h.h"

class Gameclear :public Base {
private:
	CImage m_img;
public:
	Gameclear();
	Gameclear::~Gameclear();

	void Update();
	void Draw();
};