#pragma once

#include "../Base/Base.h"

class Game : public Base {
	bool m_is_load;
	bool GameOver_flag = 0;
public:
	Game();
	~Game();
	void Update();
};