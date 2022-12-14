#include "Game.h"
#include"../h.h"
#include"../UI/Save.h"
#include"../UI/Gameover.h"
Game::Game() :Base(eType_Scene)
{
	SOUND("BGM_Title")->Stop();
	SOUND("BGM_Game")->Play(true);
	Base::Add(new kamano(SaveLoad::s_save_data.PlayerPos, false));
	Base::Add(new Map(SaveLoad::s_save_data.MapData, CVector2D(16 * 20, 16 * 23)));
	m_is_load = false;
}

Game::~Game()
{
	
	if (m_is_load) {

		SaveLoad::Load("save_data7.dat");
		Base::KillAll();
		Base::Add(new Game());
		printf("%d\n", SaveLoad::s_save_data.MapData);
	}
	else {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
	///	Base::Add(new Gameover());
	}
		


	
}

void Game::Update()
{
	if (!Base::FindObject(eType_Goal)) {
		
		if (PUSH(CInput::eButton1))
			SetKill();
	}
	
	if (PUSH(CInput::eButton7)) {
		Base* b = Base::FindObject(eType_kamano);
		SaveLoad::s_save_data.PlayerPos = b->m_pos;
		SaveLoad::Save("save_data7.dat");
	}
	if (PUSH(CInput::eButton8)) {
		SetKill();
		m_is_load = true;
	}
	

}

