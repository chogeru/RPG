
#include"Map.h"
#include"AreaChange.h"
#include"../h.h"

Map::Map(int nextArea,const CVector2D& nextplayerpos) : Base(eType_Field) {
	//���C���[0
	m_map_tip[0] = COPY_RESOURCE("mmm", CImage);
	//���C���[1
	m_map_tip[1] = COPY_RESOURCE("mmm", CImage);
	SaveLoad::s_save_data.MapData = nextArea;
	Base* player = Base::FindObject(eType_kamano);
	if (player) {
		player->m_pos = nextplayerpos;
	}

	switch (nextArea) {
	case 1:
		//fmf����}�b�v�f�[�^��ǂݍ���
		Open("Map/1�K���C���z�[����.fmf");
		//�L����

		Base::Add(new AreaChange(2,					//���̃}�b�v�̔ԍ�
			CRect(m_fmfHeader.byChipWidth * 48,		//���i���l�������قǉE�ɍs���j
				m_fmfHeader.byChipHeight * 7,		//�����i���l���Ⴂ�قǏ�ɍs���j
				m_fmfHeader.byChipWidth * 5,		//���T�C�Y�i�����蔻��j
				m_fmfHeader.byChipHeight * 6),		//�c�T�C�Y�i�����蔻��j
			CVector2D(m_fmfHeader.byChipWidth * 47,	//���̃}�b�v�̍ŏ��̃v���C���[�̏ꏊ
				m_fmfHeader.byChipHeight * 7)));
		
		//�L����
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
		Open("Map/2�K���C���z�[��.fmf");
		//�L���@�E���
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 48,
				m_fmfHeader.byChipHeight * 7,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 47,
				m_fmfHeader.byChipHeight * 7)));
		//���ւ�
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
		Open("Map/3�K���C���z�[��.fmf");
		//�L���@�E��
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
		break;

	case 4:
		Open("Map/4�K���C���z�[��.fmf");
		//����
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
		Open("Map/5�K���C���z�[��.fmf");
		//����
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
		Open("Map/6�K���C���z�[��.fmf");

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
		Open("Map/����.fmf");
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 11:
		Open("Map/����.fmf");
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	

	case 15:
		Open("Map/�}����.fmf");
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 16:
		Open("Map/�}����.fmf");
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 23,
				m_fmfHeader.byChipHeight * 7)));
		break;

	case 20:
		Open("Map/�n����.fmf");
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 6,
				m_fmfHeader.byChipHeight * 4),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 7)));
		break;
	case 21:
		Open("Map/�n����.fmf");
		Base::Add(new AreaChange(3,
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
	//fmf�����
	Close();
}


void Map::Draw() {
	if (m_kill) return;

	//1F�̃Y�����Ȃ������߁A�`��̒��O�ŃX�N���[���l�m��
	if (Base* p = Base::FindObject(eType_kamano)) {
		//�X�N���[���ݒ�
		m_scroll.x = p->m_pos.x - 600;
		m_scroll.y = p->m_pos.y - 500;
	}


	//�`�b�v�̐��@��s�P�U�񂩁@�P�s�Q�T�U��
	int s = pow(16, (GetLayerBitCount() / 8));

	//�\���͈͂�����@��ʂɈڂ�͈͂����`��
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
	

	//���C���[�������J��Ԃ� k=1����n�߂�Ɣ���p�̕ǂ����\�������
	for (int k = 0; k < GetLayerCount();k++) {
		//�s�Ɨ�̌J��Ԃ�
		for (int j = sy; j < ey; j++) {
			for (int i = sx; i < ex; i++) {
				//�`�b�v�̔ԍ����擾����
				int t = GetValue(k, i, j);
				//���ߔԍ��Ȃ�\�����Ȃ�
				if (t == NULL_TIP) continue;
				//�`�b�v�ԍ�����g�p����摜�̏ꏊ���v�Z
				int x = t % s;
				int y = t / s;
				//�\���ʒu�ݒ�
				m_map_tip[k].SetPos(CVector2D(m_fmfHeader.byChipWidth*i, m_fmfHeader.byChipHeight*j)-m_scroll);
				//�\����`�ݒ�
				m_map_tip[k].SetRect(x * m_fmfHeader.byChipWidth, y * m_fmfHeader.byChipHeight, (x + 1) * m_fmfHeader.byChipWidth, (y + 1) * m_fmfHeader.byChipHeight);
				//�T�C�Y�ݒ�
				m_map_tip[k].SetSize(m_fmfHeader.byChipWidth, m_fmfHeader.byChipHeight);
				//�\��
				m_map_tip[k].Draw();
			}
		}
	}
	
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//����v�Z
	int x = pos.x / GetChipWidth();
	//��̐���
	if (x < 0) x = 0;
	if (x > GetMapWidth() - 1) x = GetMapWidth() - 1;
	//�s���v�Z
	int y = pos.y / GetChipHeight();
	//�s�̐���
	if (y < 0) y = 0;
	if (y > GetMapHeight() - 1) y = GetMapHeight() - 1;
	//�s�Ɨ�̏o��
	if (ty) *ty = y;
	if (tx) *tx = x;
	//�`�b�v�f�[�^��ԋp�@�ǂ̔ԍ���Ԃ�
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
	//�}�b�v�`�b�v�̃T�C�Y��16�h�b�g�Ə������̂ŁA�ǔ������Ȃ��悤6�_�Ŕ���
	int tx, ty;
	//����
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = (tx + 1) * GetChipWidth() - rect.m_left + 1;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = tx * GetChipWidth() - rect.m_right - 1;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}

	//�^�񒆏�
	t = GetTip(CVector2D(pos.x + (rect.m_right+ rect.m_left)/2, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = pos.x;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}

	//����
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = (tx + 1) * GetChipWidth() - rect.m_left + 1;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = tx * GetChipWidth() - rect.m_right - 1;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	//������
	t = GetTip(CVector2D(pos.x + (rect.m_right+ rect.m_left)/2, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = pos.x;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	return NULL_TIP;
}