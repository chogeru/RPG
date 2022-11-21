#include "Game.h"
#include"../h.h"
Game::Game() :Base(eType_Scene)
{
	
}

Game::~Game()
{
	

		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
	
}

void Game::Update()
{
	if (!Base::FindObject(eType_Goal)) {
		
		if (PUSH(CInput::eButton1))
			SetKill();
	}
	


	

}

