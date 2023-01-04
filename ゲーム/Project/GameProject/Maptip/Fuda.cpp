#include "Fuda.h"
#include"../Game/Game.h"
#include"../h.h"
Fuda::Fuda(const CVector2D& p)
	:Base(eType_Fuda) {
		m_img = COPY_RESOURCE("Fuda", CImage);
		m_img.SetCenter(32, 32);
		m_img.SetSize(64, 64);
		m_rect = CRect(-30, -30, 30, 30);
		m_pos_old = m_pos = p;
		int m_cut = 0;
}

void Fuda::Update()
{
	m_pos_old = m_pos;
	//Base::Add(new Fuda());
}


void Fuda::Draw()
{
	m_img.SetSize(64, 64);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//DrawRect();

}
void Fuda::Collision(Base* b)
{

}