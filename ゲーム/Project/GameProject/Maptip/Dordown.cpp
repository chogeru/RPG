#include "Dordown.h"
Dordown::Dordown(const CVector2D& pos) :Base(eType_Dordown) {
	m_img = COPY_RESOURCE("Dordown", CImage);
	m_img.SetCenter(0, 0);
	m_pos = pos;
	m_rect = CRect(-32, -32, 32, 0);
	m_img.SetSize(64, 64);
}

void Dordown::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	
}