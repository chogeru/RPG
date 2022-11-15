#pragma once

#include "../Base/Base.h"
class Select : public Base {
	enum {
		eSave,
		eLoad,
	};
	int m_select;
	CVector2D m_mouse_old;

	int m_MapData;
	int m_PlayerData;

public:
	Select();
	void Update();
	void Draw();
};