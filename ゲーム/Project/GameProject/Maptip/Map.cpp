
#include"Map.h"
#include"AreaChange.h"
#include"../h.h"

Map::Map(int nextArea,const CVector2D& nextplayerpos) : Base(eType_Field) {
	//レイヤー0
	m_map_tip[0] = COPY_RESOURCE("mmm", CImage);
	//レイヤー1
	m_map_tip[1] = COPY_RESOURCE("mmm", CImage);
	SaveLoad::s_save_data.MapData = nextArea;
	Base* player = Base::FindObject(eType_kamano);
	if (player) {
		player->m_pos = nextplayerpos;
	}
	switch (nextArea) {
	case 1:
		//fmfからマップデータを読み込む
		Open("Map/1階メインホール裏.fmf");
		SOUND("BGM_TTT")->Stop();
		SOUND("BGM_ura")->Play(true);
	//	Base::Add(new kaisou(CVector2D(100, 100)));
		//廊下↑                   //左が横移動数値、右が縦移動数値
		m_Map_text.Draw(64, 500, 1, 0, 0, "1階");
		Base::Add(new Fuda(CVector2D(580, 380)));
		//Base::Add(new Enemy(CVector2D(700, 680)));
		
		Base::Add(new AreaChange(2,					//次のマップの番号
			CRect(m_fmfHeader.byChipWidth * 48,		//横（数値が高いほど右に行く）
				m_fmfHeader.byChipHeight * 7,		//高さ（数値が低いほど上に行く）
				m_fmfHeader.byChipWidth * 5,		//横サイズ（当たり判定）
				m_fmfHeader.byChipHeight * 6),		//縦サイズ（当たり判定）
			CVector2D(m_fmfHeader.byChipWidth * 47,	//次のマップの最初のプレイヤーの場所
				m_fmfHeader.byChipHeight * 7)));
		
		//廊下↓
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 45,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 8),
			CVector2D(m_fmfHeader.byChipWidth * 43,
				m_fmfHeader.byChipHeight * 41)));

		Base::Add(new AreaChange(10,
			CRect(m_fmfHeader.byChipWidth * 22,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(11,
			CRect(m_fmfHeader.byChipWidth * 7,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(12,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(13,
			CRect(m_fmfHeader.byChipWidth * 37,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(14,
			CRect(m_fmfHeader.byChipWidth * 32,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));
	

	/*	Base::Add(new AreaChange(99,
			CRect(m_fmfHeader.byChipWidth * 19,
				m_fmfHeader.byChipHeight * 49,
				m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 49)));*/
		break;

	case 2:
		Open("Map/2階メインホール.fmf");
		SOUND("BGM_TTT")->Stop();
		SOUND("BGM_ura")->Play(true);
		//廊下　右上へ
		Base::Add(new Enemy(CVector2D(1400, 680)));
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 7)));
		//玄関へ
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 8),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 41)));
		

		Base::Add(new AreaChange(15,
			CRect(m_fmfHeader.byChipWidth * 7,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(16,
			CRect(m_fmfHeader.byChipWidth * 22,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(17,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(18,
			CRect(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(19,
			CRect(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));
		break;
	case 3:
		Open("Map/3階メインホール.fmf");
		SOUND("BGM_TTT")->Stop();
		SOUND("BGM_ura")->Play(true);
		Base::Add(new Enemy(CVector2D(1400, 680)));
		//廊下　右へ
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 7)));

		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 8),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 41)));

		Base::Add(new AreaChange(20,
			CRect(m_fmfHeader.byChipWidth * 7,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(21,
			CRect(m_fmfHeader.byChipWidth * 22,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(22,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(23,
			CRect(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(24,
			CRect(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));
		break;

	case 4:
		Open("Map/4階メインホール.fmf");
		SOUND("BGM_TTT")->Stop();
		SOUND("BGM_ura")->Play(true);
		//左上
		Base::Add(new Enemy(CVector2D(1400, 680)));
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 7)));

		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 8),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 41)));
		

		Base::Add(new AreaChange(25,
			CRect(m_fmfHeader.byChipWidth * 7,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(26,
			CRect(m_fmfHeader.byChipWidth * 22,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(27,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(27,
			CRect(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(29,
			CRect(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));

		break;
	case 5:
		Open("Map/5階メインホール.fmf");
		SOUND("BGM_TTT")->Stop();
		SOUND("BGM_ura")->Play(true);
		Base::Add(new Enemy(CVector2D(1400, 680)));
		//左へ
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 7)));
		
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 8),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 41)));

		Base::Add(new AreaChange(30,
			CRect(m_fmfHeader.byChipWidth * 7,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(31,
			CRect(m_fmfHeader.byChipWidth * 22,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));
		Base::Add(new AreaChange(32,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(33,
			CRect(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(34,
			CRect(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));

		break;
		
		
	case 6:
		Open("Map/6階メインホール.fmf");
		SOUND("BGM_TTT")->Stop();
		SOUND("BGM_ura")->Play(true);
		Base::Add(new Enemy(CVector2D(1400, 680)));

		/*Base::Add(new AreaChange(7,
			CRect(m_fmfHeader.byChipWidth * 49,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 4,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 7)));*/

		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 8),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 41)));
		Base::Add(new AreaChange(35,
			CRect(m_fmfHeader.byChipWidth * 7,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(36,
			CRect(m_fmfHeader.byChipWidth * 22,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(37,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(38,
			CRect(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 41,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28)));

		Base::Add(new AreaChange(39,
			CRect(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 2,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 28)));

		break;

	case 10:
		Open("Map/教室.fmf");
		Base::Add(new Fuda(CVector2D(600, 380)));
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;

	

	case 11:
		Open("Map/教室.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 12:
		Open("Map/教室.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 43)));
		break;

	case 13:
		Open("Map/教室.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 37,
				m_fmfHeader.byChipHeight * 43)));
		break;
	case 14:
		Open("Map/トイレ.fmf");
		SOUND("BGM_ura")->Stop();
		SOUND("BGM_TTT")->Play(true);
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 25,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 32,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 15:
		Open("Map/図書室.fmf");
		Base::Add(new Fuda(CVector2D(300, 450)));
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 16:
		Open("Map/図書室.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 17:
		Open("Map/図書室.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 43)));
		break;
	case 18:
		Open("Map/部屋.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new Enemy(CVector2D(240, 680)));
		Base::Add(new Enemy(CVector2D(740, 580)));
		Base::Add(new Enemy(CVector2D(540, 580)));
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 43)));
		break;

	case 19:
		Open("Map/トイレ.fmf");
		SOUND("BGM_ura")->Stop();
		SOUND("BGM_TTT")->Play(true);
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 25,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 20:
		Open("Map/地部屋.fmf");
		Base::Add(new Fuda(CVector2D(700, 380)));
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 21:
		Open("Map/地部屋.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 22:
		Open("Map/地部屋.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 43)));
		break;
	case 23:
		Open("Map/地部屋.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(640, 580)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 43)));
		break;
	case 24:
		Open("Map/トイレ2.fmf");
		SOUND("BGM_ura")->Stop();
		SOUND("BGM_TTT")->Play(true);
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 25,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 32,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 25:
		Open("Map/椅子部屋.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 26:
		Open("Map/椅子部屋.fmf");
		Base::Add(new Fuda(CVector2D(600, 380)));
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 27:
		Open("Map/大教室.fmf");
	//	Base::Add(new Enemy(CVector2D(340, 680)));
	//	Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 43)));

		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 46,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 43)));
		break;
	
	case 29:
		Open("Map/トイレ2.fmf");
		SOUND("BGM_ura")->Stop();
		SOUND("BGM_TTT")->Play(true);
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 25,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 32,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 30:
		Open("Map/教室死体あり.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new Enemy(CVector2D(340, 380)));
		Base::Add(new Enemy(CVector2D(840, 280)));
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 31:
		Open("Map/椅子部屋２.fmf");
	
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));

	
		break;
	case 32:
		Open("Map/左教室.fmf");
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 43)));
		break;
	case 33:
		Open("Map/倉庫.fmf");
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 43)));
		break;

	case 34:
		Open("Map/トイレ2.fmf");
		SOUND("BGM_ura")->Stop();
		SOUND("BGM_TTT")->Play(true);
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 25,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 32,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 35:
		Open("Map/？？？.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new Fuda(CVector2D(950, 280)));
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 36:
		Open("Map/？？？.fmf");
	
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 37:
		Open("Map/？？？.fmf");
		Base::Add(new Enemy(CVector2D(340, 680)));
		Base::Add(new Enemy(CVector2D(840, 580)));
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 43)));
		break;
	case 38:
		Open("Map/落とし部屋.fmf");
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 43)));
		break;

	case 39:
		Open("Map/トイレ3.fmf");
		SOUND("BGM_ura")->Stop();
		SOUND("BGM_TTT")->Play(true);
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 25,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 32,
				m_fmfHeader.byChipHeight * 7)));
		break;

	}

	
}


Map::~Map() {
	//fmfを閉じる
	Close();
}


void Map::Draw() {
	if (m_kill) return;

	//1Fのズレをなくすため、描画の直前でスクロール値確定
	if (Base* p = Base::FindObject(eType_kamano)) {
		//スクロール設定
		m_scroll.x = p->m_pos.x - 600;
		m_scroll.y = p->m_pos.y - 500;
	}
	//8

	//チップの数　一行１６列か　１行２５６列か
	int s = pow(16, (GetLayerBitCount() / 8));

	//表示範囲を限定　画面に移る範囲だけ描画
	int col = CCamera::GetCurrent()->GetWhidth() / GetChipWidth()+1;
	int row = CCamera::GetCurrent()->GetHeight() / GetChipHeight()+1;
	
	int sx = m_scroll.x / GetChipWidth();
	if (sx < 0) sx = 0;
	int ex = sx + col;
	if (ex > GetMapWidth())ex = GetMapWidth();

	int sy = m_scroll.y / GetChipHeight();
	if (sy < 0) sy = 0;
	int ey = sy + row;
	if (ey > GetMapHeight())ey = GetMapHeight();
	

	//レイヤー数だけ繰り返す k=1から始めると判定用の壁だけ表示される
	for (int k = 0; k < GetLayerCount();k++) {
		//行と列の繰り返し
		for (int j = sy; j < ey; j++) {
			for (int i = sx; i < ex; i++) {
				//チップの番号を取得する
				int t = GetValue(k, i, j);
				//透過番号なら表示しない
				if (t == NULL_TIP) continue;
				//チップ番号から使用する画像の場所を計算
				int x = t % s;
				int y = t / s;
				//表示位置設定
				m_map_tip[k].SetPos(CVector2D(m_fmfHeader.byChipWidth*i, m_fmfHeader.byChipHeight*j)-m_scroll);
				//表示矩形設定
				m_map_tip[k].SetRect(x * m_fmfHeader.byChipWidth, y * m_fmfHeader.byChipHeight, (x + 1) * m_fmfHeader.byChipWidth, (y + 1) * m_fmfHeader.byChipHeight);
				//サイズ設定
				m_map_tip[k].SetSize(m_fmfHeader.byChipWidth, m_fmfHeader.byChipHeight);
				//表示
				m_map_tip[k].Draw();
			}
		}
	}
	
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//列を計算
	int x = pos.x / GetChipWidth();
	//列の制限
	if (x < 0) x = 0;
	if (x > GetMapWidth() - 1) x = GetMapWidth() - 1;
	//行を計算
	int y = pos.y / GetChipHeight();
	//行の制限
	if (y < 0) y = 0;
	if (y > GetMapHeight() - 1) y = GetMapHeight() - 1;
	//行と列の出力
	if (ty) *ty = y;
	if (tx) *tx = x;
	//チップデータを返却　壁の番号を返す
	return GetValue(1, x, y);
}

int Map::GetTip(int x, int y)
{
	return GetValue(1, x, y);
}


int Map::CollisionMap(const CVector2D& pos)
{
	return GetTip(pos);
}
int Map::CollisionMap(const CVector2D& pos, const CRect& rect, CVector2D* rev_pos)
{
	//マップチップのサイズが16ドットと小さいので、壁抜けしないよう6点で判定
	int tx, ty;
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//修正後位置
		rev_pos->x = (tx + 1) * GetChipWidth() - rect.m_left + 1;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//修正後位置
		rev_pos->x = tx * GetChipWidth() - rect.m_right - 1;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}

	//真ん中上
	t = GetTip(CVector2D(pos.x + (rect.m_right+ rect.m_left)/2, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//修正後位置
		rev_pos->x = pos.x;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}

	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//修正後位置
		rev_pos->x = (tx + 1) * GetChipWidth() - rect.m_left + 1;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//修正後位置
		rev_pos->x = tx * GetChipWidth() - rect.m_right - 1;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	//中央下
	t = GetTip(CVector2D(pos.x + (rect.m_right+ rect.m_left)/2, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//修正後位置
		rev_pos->x = pos.x;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	return NULL_TIP;
}