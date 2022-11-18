#include "Game.h"
#include"../h.h"
Game::Game() :Base(eType_Scene)
{
	
}

Game::~Game()
{
	int game_state = 0;
	switch (game_state) {
	case 0:
		//ポーズ中の更新処理
		if (PUSH(CInput::eButton1))
			game_state = 1;
		break;
	case 1:
		//ゲーム中の更新処理
		break;

		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
	}
}

void Game::Update()
{
	if (!Base::FindObject(eType_Goal)) {
		Base::Add(new Title());
		if (PUSH(CInput::eButton1))
			SetKill();
	}


	if (!Base::FindObject(eType_Goal)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());

	}
	if (!Base::FindObject(eType_Scene))
	{
		Base::Add(new Map());
	}
}

