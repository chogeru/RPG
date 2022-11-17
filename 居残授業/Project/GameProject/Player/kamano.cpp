#include "kamano.h"
#include"../Base/Base.h"
#include"../h.h"
kamano::kamano(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("kamano", CImage);
	
	//座標設定
	m_pos = p;
	//中心位置設定
	//m_img.SetCenter(128, 224);
	m_img.SetCenter(0, 0);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;

	m_scroll.x = m_pos.x - 1280 / 2;


}
void kamano::Update()
{
}
void kamano::StateIdle()
{
	//移動量
	const float move_speed = 20;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;

	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		m_img.ChangeAnimation(0);
		move_flag = true;
	}
	if (HOLD(CInput::eUp)) {
		//移動量を設定
		m_pos.y += -move_speed;
		m_img.ChangeAnimation(2);
		move_flag = true;
	}
	if (HOLD(CInput::eDown)) {
		//移動量を設定
		m_pos.y -= -move_speed;
		m_img.ChangeAnimation(3);
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		m_img.ChangeAnimation(1);
		move_flag = true;
	}
	//ジャンプ
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
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
}

void kamano::Collision(Base* b)
{
}

