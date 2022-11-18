#pragma once
#include "../Base/Base.h"

class Enemy : public Base {
	CImage m_img;
	int m_cnt;
	int m_state;


	bool m_flip;
	bool m_is_ground;

	int m_attack_no;
	int m_damage_no;
	int m_hp;
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
