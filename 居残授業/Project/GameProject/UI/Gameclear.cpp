#include "Gameclear.h"
#include"../Game/Game.h"

Gameclear::Gameclear():Base(eType_Scene)
{
	m_img = COPY_RESOURCE("Gameclear", CImage);
}

Gameclear::~Gameclear()
{
}

void Gameclear::Update()
{
}

void Gameclear::Draw()
{
	m_img.Draw();
}
