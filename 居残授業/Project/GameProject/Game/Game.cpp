#include "Game.h"
#include"../h.h"
Game::Game() :Base(eType_Scene)
{
	
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

