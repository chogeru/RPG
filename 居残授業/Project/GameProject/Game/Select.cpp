#include "Select.h"
#include "SaveLoad.h"
Select::Select():Base(eType_UI)
{
	m_select = eSave;
	m_cnt = 0;
	m_cnt2 = 0;
}

void Select::Update()
{
	m_cnt++;
	//選択
	if (PUSH(CInput::eUp)) {
		m_select--;
		if (m_select < 0) m_select = 0;
	}
	if (PUSH(CInput::eDown)) {
		m_select++;
		if (m_select > 1) m_select = 1;
	}
	if (PUSH(CInput::eButton1)) {
		switch (m_select) {
		case eSave:
			m_cnt2++;
			//保存データを更新
			SaveLoad::s_save_data.cnt = m_cnt;
			SaveLoad::s_save_data.cnt2 = m_cnt2;
			SaveLoad::Save("save_data.dat");
			break;
		case eLoad:
			SaveLoad::Load("save_data.dat");
			//読み込んだデータを受け取る
			m_cnt=SaveLoad::s_save_data.cnt;
			m_cnt2=SaveLoad::s_save_data.cnt2;
			break;
		}
	}
}
void Select::Draw()
{
	//SaveLoad選択表示
	CVector2D pos[2] = {
		CVector2D(100,200),
		CVector2D(100,300),
	};
	const char* text[2] = {
		"Save",
		"Load"
	};
	for (int i = 0; i < 2; i++) {
		FONT_T()->Draw(pos[i].x, pos[i].y, 1, 1, 1, text[i]);
	}
	//カーソル
	FONT_T()->Draw(pos[m_select].x-64, pos[m_select].y, 1, 1, 1, ">");
	//テストデータの表示
	FONT_T()->Draw(0, 128, 1, 0, 0, "m_cnt[%d] m_cnt2[%d]",m_cnt,m_cnt2);
}
