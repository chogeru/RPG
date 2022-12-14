#pragma once
#include "../Base/Base.h"
/// <summary>
/// 画面解像度を元に戻すクラス
/// </summary>
class Canvas :public Base {
private:
	CVector2D m_screen_size;
public:
	Canvas(const CVector2D& screen_size);
	void Draw();
};