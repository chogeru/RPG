#include"kamano.h"
#include"../h.h"

kamano::kamano(const CVector2D& p, bool flip):
	Base(eType_kamano) {
	//画像複製
	m_img = COPY_RESOURCE("kamano", CImage);
	switch (Chenge) {

	case eType_kamano:
		if (HOLD(CInput::eChangeK)) {
			m_img = COPY_RESOURCE("kamano", CImage);
		}
		break;

	case eType_hayashi:
			if (HOLD(CInput::eChangeH)) {
				m_img = COPY_RESOURCE("hayashi", CImage);
			}
			break;
	case eType_itihara:
		if (HOLD(CInput::eChangeI)) {
			m_img = COPY_RESOURCE("itihara", CImage);
		}
		break;
	}
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = CVector2D();
	//中心位置設定
	m_img.SetCenter(31, 31);
    m_rect = CRect(-31, -31, 31, 31);
	
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//
	m_hp = 500;
	m_hp = 1;
	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;
	m_enable_area_change = true;
	m_hit_area_change = false;


}void kamano::StateIdle()
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
		m_img.ChangeAnimation(1);
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
		m_img.ChangeAnimation(0);
		move_flag = true;
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

	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;
	//一度エリアチェンジ範囲から離れないと再度エリアチェンジしない
	//連続エリアチェンジ防止
	if (!m_enable_area_change && !m_hit_area_change)
		m_enable_area_change = true;
	m_hit_area_change = false;
}


void kamano::Update() {
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
	}
	//落ちていたら落下中状態へ移行
	/*if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	*/
	m_pos_old = m_pos;

	//アニメーション更新
	m_img.UpdateAnimation();

	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;

}

void kamano::Draw() {
	//位置設定
	// 
	m_img.SetSize(64, 64);
	m_img.SetPos(GetScreenPos(m_pos));
	//描画
	m_img.Draw();
	DrawRect();
}
void kamano::Collision(Base* b)
{

	switch (b->m_type) {

	case eType_AreaChange:
		if (Base::CollisionRect(this, b)) {
			//エリアチェンジに触れている
			m_hit_area_change = true;
			//エリアチェンジ可能なら
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//マップとエリアチェンジオブジェクトを削除
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					//次のマップを生成
					Base::Add(new Map(a->m_nextArea, a->m_nextplayerpos));
					//エリアチェンジ一時不許可
					m_enable_area_change = false;
				}
			}
		}

		break;
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

/*	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			SetKill();
			Base::Add(new Gameover());
		}
		break;
		
	}

}*/

