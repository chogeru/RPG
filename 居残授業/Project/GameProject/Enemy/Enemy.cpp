#include "Enemy.h"

Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{

		m_img = COPY_RESOURCE("Enemy", CImage);
		m_img.ChangeAnimation(0);
		m_img.SetCenter(0, 0);
		m_img.SetSize(64, 64);
		m_rect = CRect(0, 0, 0, 0);
		m_damage_no = -10000;
		m_hp = 50;
}

void Enemy::Update()
{
	const float movespeed = 10;
	bool move_flag = false;

	auto list = Base::FindObjects(eType_Player);
	if (list.size() > 0) {
		//ˆê”Ô‹ß‚¢ƒvƒŒƒCƒ„[‚ð’T‚·
		Base* target = nullptr;
		float dist = FLT_MAX;
		Base* player = Base::FindObject(eType_Player);
		if (player) {
			if (player->m_pos.x < m_pos.x - 0) {
				m_pos.x += -movespeed;
				m_flip = true;
				move_flag = true;
			}
			else if(player->m_pos.x > m_pos.x + 0) {
					m_pos.x += movespeed;
					m_flip = false;
					move_flag = true;
				}
			else if (player->m_pos.y > m_pos.y + 0) {
				m_pos.y += movespeed;
				m_flip = false;
			move_flag = true;
			}
			else if (player->m_pos.y < m_pos.y - 0) {
				m_pos.y += movespeed;
				m_flip = false;
				move_flag = true;
			}
			for (auto& b : list) {
				CVector2D v = b->m_pos - m_pos;
				if (v.LengthSq() < dist) {
					target = b;
					dist = v.LengthSq();
				}
			}
			
		}
	}
}

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy::Collision(Base* b)
{
}

