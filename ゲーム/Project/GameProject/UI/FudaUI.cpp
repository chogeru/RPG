#include "FudaUI.h"
FudaUI::FudaUI(const CVector2D& p) :Base(eType_UI) {
	m_img = COPY_RESOURCE("FudaUI", CImage);

	m_pos_old = m_pos = p;
	m_img.SetCenter(32, 32);
	m_img.SetSize(256, 128);
}

void FudaUI::Update()
{
	m_pos_old = m_pos;

}


void FudaUI::Draw() {

	if (Base* b = Base::FindObject(eType_kamano)) {
		if (b->m_cut == 3) {
			m_img.SetRect(0, 0, 192, 64);
			m_img.SetSize(192, 64);
			m_img.SetPos(m_pos);
			m_img.Draw();

		}
		else if (b->m_cut == 2) {
			m_img.SetRect(0, 0, 128, 64);
			m_img.SetSize(128, 64);
			m_img.SetPos(m_pos);
			m_img.Draw();

		}
		else if (b->m_cut == 1) {
			m_img.SetRect(0, 0, 64, 64);
			m_img.SetSize(64, 64);
			m_img.SetPos(64,64);
			m_img.Draw();

		}

	}

	
}

