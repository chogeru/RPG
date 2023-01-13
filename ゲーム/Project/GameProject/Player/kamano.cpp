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
    m_rect = CRect(-24, -22, 24, 24);
	
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
	Base::Add(m_gauge = new Gauge(0));
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//
	m_hp = 3;
	m_rad=1;
	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;
	m_enable_area_change = true;
	m_hit_area_change = false;

}void kamano::StateIdle()
{
	//移動量/ 
	const float move_speed = 7;
	//移動フラグ

	bool move_flag = false;
	if (m_gauge)
		m_gauge->SetKill();
	
	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		m_img[Chara1].ChangeAnimation(1);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.x += -move_speed * 0.5f;
			move_flag = true;
		}
	}
	if (HOLD(CInput::eUp)) {
		//移動量を設定
		m_pos.y += -move_speed;
		m_img[Chara1].ChangeAnimation(2);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.y += -move_speed * 0.5f;
			move_flag = true;
		}
	}
	if (HOLD(CInput::eDown)) {
		//移動量を設定
		m_pos.y -= -move_speed;
		m_img[Chara1].ChangeAnimation(3);
		move_flag = true;
		if (HOLD(CInput::eButton9)) {
			m_pos.y -= -move_speed * 0.5f;
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
			m_pos.x += move_speed * 0.5f;
			move_flag = true;
		}
	}
	if (Chara1 == 0) {
		move_speed * 0.9f;
	}
	if (Chara1 == 1) {
		move_speed * 0.1f;
	}
	if (Chara1 == 2) {
		move_speed * 1.4f;
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
	//DrawRect();
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
					KillByType(eType_Fuda);
					KillByType(eType_AreaChange);
					KillByType(eType_Enemy);
					KillByType(eType_EnemyManager);
					//次のマップを生成
					Base::Add(new Map(a->m_nextArea, a->m_nextplayerpos));
					Base::Add(new EnemyManager());

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


	case eType_Fuda:
		if (m_type == eType_kamano && Base::CollisionRect(this, b)) {
			if (Base::CollisionRect(this, b)) {
				//お札に触れるとカウント1される
				m_cut += 1;
				KillByType(eType_Fuda);
				//お札が12回カウントされたらシーン切り替え
				//確認しやすいように２回に変更しております
				if (m_cut == 12) {
					KillAll();
					Base::Add(new Gameclear());//ゲームクリア画面がないのでいったんタイトルにもどします
				}
			}

		}
		break;
		//敵に３回当たったら死ぬ処理
	case eType_Enemy:
		if (m_type == eType_kamano && Base::CollisionRect(this, b)) {
			if (Base::CollisionRect(this, b)) {
				m_hp -= 1;
				//敵の削除
				KillByType(eType_Enemy);
				if (m_hp == 0) {
				//	SOUND("BGM_EnemyDestroy")->Play();
					SetKill();
					b->SetKill();
				}
			}
			break;
		}
	}
	
}




