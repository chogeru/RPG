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

	CImage m_img;
	bool	m_flip;
	//���n�t���O
	bool	m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;

	int m_hp;

	//��`
	CRect	m_rect;
	//�e��Ԃł̋���
	void StateIdle();
	
public:
	kamano(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};

