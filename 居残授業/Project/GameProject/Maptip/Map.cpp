
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
		//廊下↑

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
		//廊下　右上へ
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
		break;

	case 3:
		Open("Map/3階メインホール.fmf");
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
		break;

	case 4:
		Open("Map/4階メインホール.fmf");
		//左上
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
		break;

	case 5:
		Open("Map/5階メインホール.fmf");
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
		break;
		
		
	case 6:
		Open("Map/6階メインホール.fmf");

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
		break;

	case 10:
		Open("Map/教室.fmf");
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
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	

	case 15:
		Open("Map/図書室.fmf");
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
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
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