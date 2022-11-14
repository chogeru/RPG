#include "Enemy.h"
#include"Bullet.h"

Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	m_img.SetCenter(32, 32);
	m_rad = 32;
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
			if (player->m_pos.x < m_pos.x - 32) {
				m_pos.x += -movespeed;
				m_flip = true;
				move_flag = true;
			}
			else if (player->m_pos.x > m_pos.x + 32) {
					m_pos.x += movespeed;
					m_flip = false;
					move_flag = true;
				}
			else if (player->m_pos.y > m_pos.y + 32) {
				m_pos.y += movespeed;
				m_flip = false;
				move_flag = true;
			}
			else if (player->m_pos.y > m_pos.y - 32) {
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
			if (target) {
				CVector2D vec = target->m_pos - m_pos;
				m_ang = atan2(vec.x, vec.y);
				if (m_cnt >= 120) {
					Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
					m_cnt = 0;
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

