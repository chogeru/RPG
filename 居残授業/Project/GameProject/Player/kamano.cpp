#include"kamano.h"
#include"../h.h"

kamano::kamano(const CVector2D& p, bool flip):
	Base(eType_kamano) {
	//画像複製
	Chara1 = 0;
	m_img[0] = COPY_RESOURCE("kamano", CImage);
	
	//再生アニメーション設定
	m_img[0].ChangeAnimation(0);
	m_img[0].SetCenter(31, 31);
	
	m_img[1] = COPY_RESOURCE("hayashi", CImage);
	//再生アニメーション設定
	m_img[1].ChangeAnimation(0);
	m_img[1].SetCenter(31, 31);
    
	m_img[2] = COPY_RESOURCE("itihara", CImage);
	//再生アニメーション設定
	m_img[2].ChangeAnimation(0);
	m_img[2].SetCenter(31, 31);
	
	//座標設定
	m_pos_old = m_pos =p;
    m_rect = CRect(-25, -25, 25, 25);
	
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
	//移動量/ 
	const float move_speed = 10;
	//移動フラグ

	bool move_flag = false;
	//ジャンプ力
	
	
	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		m_img[Chara1].ChangeAnimation(1);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.x += -move_speed * 0.8f;
			move_flag = true;
		}
	}
	if (HOLD(CInput::eUp)) {
		//移動量を設定
		m_pos.y += -move_speed;
		m_img[Chara1].ChangeAnimation(2);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.y += -move_speed * 0.8f;
			move_flag = true;
		}
	}
	if (HOLD(CInput::eDown)) {
		//移動量を設定
		m_pos.y -= -move_speed;
		m_img[Chara1].ChangeAnimation(3);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.y -= -move_speed * 0.8f;
			move_flag = true;
		}
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		m_img[Chara1].ChangeAnimation(0);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.x += move_speed * 0.8f;
			move_flag = true;
		}
	}
	
	//動いているアニメーション
	if (move_flag)
	{
		m_img[Chara1].m_animSpeed = 1;
	}
	//止まっているアニメーション
	else
	{
		m_img[Chara1].m_animSpeed = 0;
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

	//アニメーション更新
	m_img[Chara1].UpdateAnimation();

	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;

}

void kamano::Draw() {
	//位置設定
	// 
	m_img[Chara1].SetSize(64, 64);
	m_img[Chara1].SetPos(GetScreenPos(m_pos));
	//描画
	m_img[Chara1].Draw();
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

