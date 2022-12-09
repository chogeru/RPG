#include"kamano.h"
#include"../h.h"

kamano::kamano(const CVector2D& p, bool flip):
	Base(eType_kamano) {
	//�摜����
	Chara1 = 0;
	m_img[0] = COPY_RESOURCE("kamano", CImage);
	
	//�Đ��A�j���[�V�����ݒ�
	m_img[0].ChangeAnimation(0);
	m_img[0].SetCenter(31, 31);
	
	m_img[1] = COPY_RESOURCE("hayashi", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img[1].ChangeAnimation(0);
	m_img[1].SetCenter(31, 31);
    
	m_img[2] = COPY_RESOURCE("itihara", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img[2].ChangeAnimation(0);
	m_img[2].SetCenter(31, 31);
	
	//���W�ݒ�
	m_pos_old = m_pos =p;
    m_rect = CRect(-25, -25, 25, 25);
	
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = true;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//
	m_hp = 500;
	m_hp = 1;
	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2;
	m_enable_area_change = true;
	m_hit_area_change = false;


}void kamano::StateIdle()
{
	//�ړ���/ 
	const float move_speed = 10;
	//�ړ��t���O

	bool move_flag = false;
	//�W�����v��
	
	
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		m_img[Chara1].ChangeAnimation(1);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.x += -move_speed * 0.8f;
			move_flag = true;
		}
	}
	if (HOLD(CInput::eUp)) {
		//�ړ��ʂ�ݒ�
		m_pos.y += -move_speed;
		m_img[Chara1].ChangeAnimation(2);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.y += -move_speed * 0.8f;
			move_flag = true;
		}
	}
	if (HOLD(CInput::eDown)) {
		//�ړ��ʂ�ݒ�
		m_pos.y -= -move_speed;
		m_img[Chara1].ChangeAnimation(3);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.y -= -move_speed * 0.8f;
			move_flag = true;
		}
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		m_img[Chara1].ChangeAnimation(0);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.x += move_speed * 0.8f;
			move_flag = true;
		}
	}
	
	//�����Ă���A�j���[�V����
	if (move_flag)
	{
		m_img[Chara1].m_animSpeed = 1;
	}
	//�~�܂��Ă���A�j���[�V����
	else
	{
		m_img[Chara1].m_animSpeed = 0;
	}
	
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;
	//��x�G���A�`�F���W�͈͂��痣��Ȃ��ƍēx�G���A�`�F���W���Ȃ�
	//�A���G���A�`�F���W�h�~
	if (!m_enable_area_change && !m_hit_area_change)
		m_enable_area_change = true;
	m_hit_area_change = false;
}


void kamano::Update() {
	m_pos_old = m_pos;

		if (HOLD(CInput::eButton2)) {
			Chara1 = 0;
		}

		if (HOLD(CInput::eButton3)) {
			Chara1 = 1;
		}
		if (HOLD(CInput::eButton4)) {
			Chara1 = 2;
		}
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	/*if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	*/

	//�A�j���[�V�����X�V
	m_img[Chara1].UpdateAnimation();

	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2;

}

void kamano::Draw() {
	//�ʒu�ݒ�
	// 
	m_img[Chara1].SetSize(64, 64);
	m_img[Chara1].SetPos(GetScreenPos(m_pos));
	//�`��
	m_img[Chara1].Draw();
	DrawRect();
}
void kamano::Collision(Base* b)
{

	switch (b->m_type) {

	case eType_AreaChange:
		if (Base::CollisionRect(this, b)) {
			//�G���A�`�F���W�ɐG��Ă���
			m_hit_area_change = true;
			//�G���A�`�F���W�\�Ȃ�
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//�}�b�v�ƃG���A�`�F���W�I�u�W�F�N�g���폜
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					//���̃}�b�v�𐶐�
					Base::Add(new Map(a->m_nextArea, a->m_nextplayerpos));
					//�G���A�`�F���W�ꎞ�s����
					m_enable_area_change = false;
				}
			}
		}

		break;
	case eType_Field:
		//�}�b�v�Ƃ̔���
		if (Map* m = dynamic_cast<Map*>(b)) {
			CVector2D pos;
			//�}�b�v�`�b�v�̔���i���j
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, &pos);
			//�ǂȂ��
			if (t != NULL_TIP) {
				//�Ǎۂ܂Ŗ߂�
				m_pos.x = pos.x;
			}
			//�}�b�v�`�b�v�̔���i�c�j
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, &pos);
			//�ǂȂ��
			if (t != NULL_TIP) {
				//�Ǎۂ܂Ŗ߂�
				m_pos.y = pos.y;
			}
		}
		break;
	}
}

/*	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			SetKill();
			Base::Add(new Gameover());
		}
		break;
		
	}

}*/

