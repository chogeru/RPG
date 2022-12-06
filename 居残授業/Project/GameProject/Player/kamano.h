#pragma once
#include"../Base/Base.h"
class kamano : public Base {
private:
	//状態
	enum {
		eState_Idle,
	};
	//状態変数
	int m_state;
	CImage m_img[3];
	int Chara1;
	bool	m_flip;
	//着地フラグ
	bool	m_is_ground;
	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;

	int m_hp;
	//エリアチェンジフラグ
	bool m_enable_area_change;
	//エリアチェンジオブジェクトに触れているフラグ
	bool m_hit_area_change;
	//矩形
	//CRect	m_rect;
	//各状態での挙動
	void StateIdle();
	void StateDown();

public:
	kamano(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
