#pragma once
#include"../Base/Base.h"
class kamano : public Base {
private:
	//���
	enum {
		eState_Idle,
	};
	//��ԕϐ�
	int m_state;
	int Chenge;
	CImage m_img;
	bool	m_flip;
	//���n�t���O
	bool	m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;

	int m_hp;
	//�G���A�`�F���W�t���O
	bool m_enable_area_change;
	//�G���A�`�F���W�I�u�W�F�N�g�ɐG��Ă���t���O
	bool m_hit_area_change;
	//��`
	//CRect	m_rect;
	//�e��Ԃł̋���
	void StateIdle();
	void StateDown();

public:
	kamano(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
