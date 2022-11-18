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
	//�Q�[���I�[�o�[�I����Q�[����ʂɈȍ~���܂�
	Base::Add(new Map());

}

void Gameover::Update()
{
	//�{�^���P�ŃV�[�����I���
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

void Gameover::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	//�����\������
	m_Gameover_text.Draw(64, 256, 0, 0, 0, "GAMEOVER");
	m_Gameover_text.Draw(64, 512, 0, 0, 0, "���� Z");
}