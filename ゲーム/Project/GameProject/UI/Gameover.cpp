#include "Gameover.h"
#include "../Game/Game.h"
#include"../Maptip/Map.h"
#include"../h.h"
Gameover::Gameover() :Base(eType_Scene),
m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	SOUND("BGM_ura")->Stop();
	SOUND("BGM_Title")->Stop();
	SOUND("BGM_GameOver")->Play();
	m_img[0] = COPY_RESOURCE("Gameover", CImage);
	m_img[1] = COPY_RESOURCE("gameover_itihara", CImage);
	m_img[2] = COPY_RESOURCE("hayasi_over", CImage);
	//m_img.ChangeAnimation(eState_Gameover);
	//m_img.UpdateAnimation();
	//m_img.CheckAnimationEnd();
}

Gameover::~Gameover()
{
	
	//全てのオブジェクトを破棄
	Base::KillAll();
	//ゲームシーンへ
	Base::Add(new Title());

}

void Gameover::Update()
{
	m_gcnt++;
	if (m_gcnt > 30000) {
		Chara1 = 0;

		m_gcnt = 0;
	}
	if (m_gcnt <30000>50100) {
		Chara1 = 1;

		m_gcnt = 0;
	}
	if (m_gcnt  <50100) {
		Chara1 = 2;

		m_gcnt = 0;
	}
	/*if (m_hp == 3) {
		Chara1 = 0;
	}
	if (m_hp == 2)
	{
		Chara1 = 1;
	}
	if (m_hp == 1)
	{
		Chara1 = 2;
	}*/
	/*if (HOLD(CInput::eButton2)) {
		Chara1 = 0;
	}
	if (HOLD(CInput::eButton3)) {
		Chara1 = 1;
	}
	if (HOLD(CInput::eButton4)) {
		Chara1 = 2;
	}*/
	//m_img.ChangeAnimation(eState_Gameover);
	//アニメーション更新
	//m_img.UpdateAnimation();
	//ボタン１でシーンが終わる
	if (PUSH(CInput::eButton1)) {
		SetKill();
		SOUND("BGM_GameOver")->Stop();	
	}
	//アニメーション終了チェック
	//if (m_img.CheckAnimationEnd());
	//{

	//}
}

void Gameover::Draw()
{
	m_img[0].Draw();

	m_img[0].SetSize(1920, 1080);
	m_img[1].Draw();

	m_img[1].SetSize(1920, 1080);
	m_img[2].Draw();

	m_img[2].SetSize(1920, 1080);
	//文字表示だお
	//m_Gameover_text.Draw(64, 256, 0, 0, 0, "GAMEOVER");
	//m_Gameover_text.Draw(64, 512, 0, 0, 0, "復活 Z");
}