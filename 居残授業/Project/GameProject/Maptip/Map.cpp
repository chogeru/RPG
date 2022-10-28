#include "Map.h"
#include"../Base/Base.h"
#include"../Player/Player.h"
#include"../Enemy/Enemy.h"
#include"../Player/kamano.h"
#include"../Player/hayashi.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},



};


Map::Map() : Base(eType_Field)
{



	m_ground_y = 500;


	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (stage1data[i][j] < 2)continue;
			int x;
			int y;
			x = j * MAP_TIP_SIZE;
			y = i * MAP_TIP_SIZE;
			int& t = stage1data[i][j];
			switch (t) {
			case 2:
				Base::Add(new kamano(CVector2D(x, y), true));
				break;
			case 3:
				Base::Add(new hayashi(CVector2D(x, y), true));
				break;
			case 6:
				Base::Add(new Player(CVector2D(x, y), true));
				break;

			}
			t = 0;
		}
	}



	//�摜����
	m_img = COPY_RESOURCE("Map1", CImage);


}

void Map::Draw()
{


	int x1 = m_scroll.x / MAP_TIP_SIZE;
	if (x1 < 0) x1 = 0;
	int	x2 = x1 + 31;
	if (x2 > MAP_WIDTH - 1) x2 = MAP_WIDTH - 1;

	//�}�b�v�`�b�v�ɂ��\���̌J��Ԃ�ac

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = x1; j < x2; j++) {
			if (stage1data[i][j] == 0)continue;
			int& t = stage1data[i][j];

			m_img.SetRect(32, 0, 32 + 32, 32);
			//�\���T�C�Y�ݒ�
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//�\���ʒu�ݒ�
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);

			//�`��
			m_img.Draw();


		}
	}
}
void Map::Update()
{
	m_scroll.x = m_pos.x - 1280 / 2;

}
; int Map::GetTip(const CVector2D& pos)
{
	//����v�Z
	int col = pos.x / MAP_TIP_SIZE;
	//��̐���(0�`MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > MAP_WIDTH - 1) col = MAP_WIDTH - 1;
	//�s���v�Z
	int raw = pos.y / MAP_TIP_SIZE;
	//�s�̐���(0�`MAP_HEIGHT-1)
	if (raw < 0) raw = 0;
	if (raw > MAP_HEIGHT - 1) raw = MAP_HEIGHT - 1;
	//�`�b�v�f�[�^��ԋp
	return GetTip(col, raw);
}
int Map::GetTip(int col, int raw)
{
	return stage1data[raw][col];
}

int Map::CollisionMap(const CVector2D& pos)
{
	//1�_�̂݌���
	int t = GetTip(pos);
	if (t != 0) return t;

	return 0;
}
int Map::CollisionMap(const CVector2D& pos, const CRect& rect)
{
	//����
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 0) return t;
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 0) return t;
	//����
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
	if (t != 0) return t;
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 0) return t;
	return 0;
}
