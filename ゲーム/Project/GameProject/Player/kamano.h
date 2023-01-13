#pragma once
#include"../Base/Base.h"
class Gauge;
class kamano : public Base {
private:
	//状態
	enum {
		eState_Idle,
	};
	//状態変数
	int m_state;
	CImage m_img[3];
	CImage m_img2[3];
	Gauge* m_gauge;
	int Chara1;
	int hp;
	bool	m_flip;
	//着地フラグ
	bool	m_is_ground;
	//攻撃番号
	int m_cnt;
	int m_attack_no;
	//ダメージ番号
	int m_cut;
	bool m_hit_fuda;
	int m_damage_no;
	int m_rad;
	//int m_hp;
	//エリアチェンジフラグ
	CVector2D PlayerPos;
	bool m_enable_area_change;
	//エリアチェンジオブジェクトに触れているフラグ
	bool m_hit_area_change;
	//矩形
	//CRect	m_rect;
	//各状態での挙動
	void StateIdle();

public:
	kamano(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
