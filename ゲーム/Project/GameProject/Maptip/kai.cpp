#include "kai.h"
kai::kai(const CVector2D& p) :Base(eType_UI) {
	m_img = COPY_RESOURCE("1ŠK", CImage);

	m_pos_old = m_pos = p;
	m_img.SetCenter(32, 32);
	m_img.SetSize(64, 64);
}

void kai::Update()
{
	m_pos_old = m_pos;

}


void kai::Draw() {


	m_img.SetRect(0,0,256,64);
	m_img.SetSize(64, 64);
	m_img.SetPos(m_pos);
	m_img.Draw();
	
}

