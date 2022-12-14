#pragma once
#include "../Base/Base.h"

class Enemy : public Base {
	enum {
		eState_Idle,
	};
	CImage m_img;
	int m_cnt;
	int m_state;


	bool m_flip;
	bool m_is_ground;

	int m_attack;
	int m_damage;
	int m_hp;
	void StateIdle();
	//エリアチェンジフラグ
	bool m_enable_area_change;
	//エリアチェンジオブジェクトに触れているフラグ
	bool m_hit_area_change;
public:
	Enemy(const CVector2D& p);
	void Update();
	void Draw();
	void Collision(Base* b);
};
