#include "K.h"
#include"../Game/Game.h"
#include"../h.h"
K::K(const CVector2D& p)
	:Base(eType_K) {
	m_img = COPY_RESOURCE("Map1", CImage);
	m_img.SetCenter(32, 32);
	m_img.SetSize(64, 64);
	m_rect = CRect(-30, -30, 30, 30);
	m_pos_old = m_pos = p;
	int m_kcut = 0;
}

void K::Update()
{
	m_pos_old = m_pos;
	//Base::Add(new Fuda());
}


void K::Draw()
{
	m_img.SetSize(64, 64);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//DrawRect();

}
void K::Collision(Base* b)
{

}