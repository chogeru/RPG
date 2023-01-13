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
	m_img = COPY_RESOURCE("Gameover", CImage);
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
	m_img.Draw();

	m_img.SetSize(1920, 1080);
	//文字表示だお
	//m_Gameover_text.Draw(64, 256, 0, 0, 0, "GAMEOVER");
	//m_Gameover_text.Draw(64, 512, 0, 0, 0, "復活 Z");
}