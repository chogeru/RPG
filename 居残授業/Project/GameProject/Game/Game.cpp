#include "Game.h"
#include"../h.h"
Game::Game() :Base(eType_Scene)
{
	Base::Add(new kamano(CVector2D(2 * 32, 2 * 32), false));
	Base::Add(new Map(1, CVector2D(16 * 20, 16 * 23)));
}

Game::~Game()
{
	

		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());
	
}

void Game::Update()
{
	if (!Base::FindObject(eType_Goal)) {
		
		if (PUSH(CInput::eButton1))
			SetKill();
	}
	


	

}

