#include "Gauge.h"
Gauge::Gauge(const CVector2D& p):Base(eType_UI) {
	m_img = COPY_RESOURCE("hp", CImage);
	

	m_pos_old = m_pos = p;
	m_img.SetCenter(32, 32);
	m_img.SetSize(256, 64);
}

void Gauge::Update()
{
	m_pos_old = m_pos;

}


void Gauge::Draw() {


	//˜g‚Ì•\Ž¦
	//m_img.SetRect(0,0,256,64);
	m_img.SetSize(256, 64);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();

}

