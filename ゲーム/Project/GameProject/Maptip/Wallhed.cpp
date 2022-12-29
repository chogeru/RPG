#include "Wallhed.h"
Wallhed::Wallhed(const CVector2D& pos) :Base(eType_Wall) {

	m_img = COPY_RESOURCE("Wallhed", CImage);
	m_pos = pos;
	m_rect = CRect(-64, -64, 64, 64);
}

void Wallhed::Draw() {
	m_img.SetSize(64, 64);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
