#pragma once
#include "../Base/Base.h"

class kaiga : public Base {
	enum {
		eState_Idle,
	};
	CImage m_img;
	int m_cnt;
	int m_state;


	bool m_flip;
	bool m_is_ground;

	int m_attack_no;
	int m_damage_no;
	int m_hp;
	void StateIdle();
	//エリアチェンジフラグ
	bool m_enable_area_change;
	//エリアチェンジオブジェクトに触れているフラグ
	bool m_hit_area_change;
public:
	kaiga(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
