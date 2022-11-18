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
		//�|�[�Y���̍X�V����
		if (PUSH(CInput::eButton1))
			game_state = 1;
		break;
	case 1:
		//�Q�[�����̍X�V����
		break;

		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
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
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());

	}
	if (!Base::FindObject(eType_Scene))
	{
		Base::Add(new Map());
	}
}

