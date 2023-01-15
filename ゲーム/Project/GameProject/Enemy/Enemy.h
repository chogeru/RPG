#pragma once
#include "../Base/Base.h"
#include"../h.h"
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
private:
	float m_viewLength;		// 視野距離 
	float m_viewAngle;		// 視野角度
	bool m_isChase;			// 追跡中かどうか
	CVector2D m_moveDir;	// 移動ベクトル
public:
	Enemy(const CVector2D& p);
	void Update();
	void Draw();
	void Collision(Base* b);
};
