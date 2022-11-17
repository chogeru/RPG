#include "kamano.h"
#include"../Base/Base.h"
#include"../h.h"
kamano::kamano(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("kamano", CImage);
	
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	//m_img.SetCenter(128, 224);
	m_img.SetCenter(0, 0);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;

	m_scroll.x = m_pos.x - 1280 / 2;


}
void kamano::Update()
{
}
void kamano::StateIdle()
{
	//�ړ���
	const float move_speed = 20;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;

	//���ړ�
	if (HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		m_img.ChangeAnimation(0);
		move_flag = true;
	}
	if (HOLD(CInput::eUp)) {
		//�ړ��ʂ�ݒ�
		m_pos.y += -move_speed;
		m_img.ChangeAnimation(2);
		move_flag = true;
	}
	if (HOLD(CInput::eDown)) {
		//�ړ��ʂ�ݒ�
		m_pos.y -= -move_speed;
		m_img.ChangeAnimation(3);
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		m_img.ChangeAnimation(1);
		move_flag = true;
	}
	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	
	
	
	if (move_flag)
	{
		m_img.m_animSpeed = 1;
	}
	else
	{
		m_img.m_animSpeed = 0;
	}
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;

}





void kamano::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
}

void kamano::Collision(Base* b)
{
}

