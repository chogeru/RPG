#include "Gameover.h"
#include "../Game/Game.h"
#include"../Maptip/Map.h"
Gameover::Gameover() :Base(eType_Scene),
m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Gameover", CImage);
}

Gameover::~Gameover()
{
	//ゲームオーバー終了後ゲーム画面に以降します
	Base::Add(new Map());

}

void Gameover::Update()
{
	//ボタン１でシーンが終わる
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

void Gameover::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	//文字表示だお
	m_Gameover_text.Draw(64, 256, 0, 0, 0, "GAMEOVER");
	m_Gameover_text.Draw(64, 512, 0, 0, 0, "復活 Z");
}