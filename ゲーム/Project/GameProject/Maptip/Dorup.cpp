#include "Dorup.h"
Dorup::Dorup(const CVector2D& pos) :Base(eType_Dorup) {
	m_img = COPY_RESOURCE("Dorup", CImage);
	m_img.SetCenter(0, 0);
	m_pos = pos;
	m_rect = CRect(-32, -32, 32, 0);
	m_img.SetSize(64, 64);
}

void Dorup::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();

}