#include "Enemy.h"
#include"../h.h"
#include "../Utility.cpp"

Enemy::Enemy(const CVector2D& p)
	:Base(eType_Enemy)
{
		m_img = COPY_RESOURCE("Enemy", CImage);
		m_img.ChangeAnimation(0);
		m_img.SetCenter(32, 32);
		m_img.SetSize(64, 64);
		m_rect = CRect(-2,-2, 2, 2);
		m_state = eState_Idle;
		m_pos_old = m_pos =p;
}
void Enemy::StateIdle()
{
	const float movespeed = 2;
	bool move_flag = false;

	auto list = Base::FindObjects(eType_kamano);
	if (list.size() > 0) {
		Base* target = nullptr;
		float dist = FLT_MAX;
		Base* player = Base::FindObject(eType_kamano);
		if (player) {
			//→
			if (player->m_pos.x < m_pos.x - 0) {
				m_pos.x += -movespeed;
				m_flip = false;
				m_img.ChangeAnimation(0);
				move_flag = true;
				
			}
			//←
			if (player->m_pos.x > m_pos.x + 0) {
				m_pos.x += movespeed;
				m_flip = false;
				m_img.ChangeAnimation(1);
				move_flag = true;
				
			}
			//↑
			if (player->m_pos.y > m_pos.y - 0) {
				m_pos.y += movespeed;
				m_flip = false;
				m_img.ChangeAnimation(3);
				move_flag = true;
				
			}
			//↓
			if (player->m_pos.y < m_pos.y + 0) {
				m_pos.y -= movespeed;
				m_flip = false;
				m_img.ChangeAnimation(2);
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

	//動いているアニメーション
	if (move_flag)
	{
		m_img.m_animSpeed = 1;
	}
	//止まっているアニメーション
	else
	{
		m_img.m_animSpeed = 0;
	}


}

void Enemy::Update()
{
	m_pos_old = m_pos;
	
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
	}
}

void Enemy::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();

	DrawRect();

	float alpha = 0.5f;
	// 視野範囲の色（追跡していない場合は緑色）
	CVector4D color(0.0f, 1.0f, 1.0f, alpha);
	// 追跡中であれば赤色
	if (m_isChase)
	{
		color = CVector4D(1.0f, 1.0f, 0.0f, alpha);
	}

	// 移動ベクトルからatan2で角度を求める
	float angle = atan2f(m_moveDir.y, m_moveDir.x);
	// 視野範囲を描画
	MyUtility::DrawSector(m_pos, angle - m_viewAngle, angle + m_viewAngle, m_viewLength, color);


}

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {

	case eType_Field:
		//マップとの判定
		if (Map* m = dynamic_cast<Map*>(b)) {
			CVector2D pos;
			//マップチップの判定（横）
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, &pos);
			//壁ならば
			if (t != NULL_TIP) {
				//壁際まで戻る
				m_pos.x = pos.x;
			}
			//マップチップの判定（縦）
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, &pos);
			//壁ならば
			if (t != NULL_TIP) {
				//壁際まで戻る
				m_pos.y = pos.y;
			}
		}
		break;


	}

}
