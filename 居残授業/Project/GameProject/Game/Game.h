#pragma once

#include "../Base/Base.h"

class Game : public Base {
	bool m_is_load;
public:
	Game();
	~Game();
	void Update();
};