#include "hondana.h"
hondana::hondana(const CVector2D& pos) :Base(eType_hondana) {
	m_img = COPY_RESOURCE("hondana", CImage);
	m_img.SetCenter(0, 0);
	m_pos = pos;
	m_rect = CRect(-32, -32, 32, 0);
	m_img.SetSize(64, 64);
}

void hondana::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();

}