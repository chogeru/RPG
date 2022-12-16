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
	
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�Q�[���V�[����
	Base::Add(new Title());

}

void Gameover::Update()
{
	//m_img.ChangeAnimation(eState_Gameover);
	//�A�j���[�V�����X�V
	//m_img.UpdateAnimation();
	//�{�^���P�ŃV�[�����I���
	if (PUSH(CInput::eButton1)) {
		SetKill();
		SOUND("BGM_GameOver")->Stop();	
	}
	//�A�j���[�V�����I���`�F�b�N
	//if (m_img.CheckAnimationEnd());
	//{

	//}
}

void Gameover::Draw()
{
	m_img.Draw();

	m_img.SetSize(1920, 1080);
	//�����\������
	//m_Gameover_text.Draw(64, 256, 0, 0, 0, "GAMEOVER");
	//m_Gameover_text.Draw(64, 512, 0, 0, 0, "���� Z");
}