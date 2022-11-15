#include "Save.h"


SaveLoad::SaveData SaveLoad::s_save_data;

void SaveLoad::Load(const char* file)
{
	//�t�@�C���|�C���^
	FILE* fp;
	//�t�@�C�����J�� �o�C�i���ǂݍ���
	fopen_s(&fp, file, "rb");
	//�J���Ȃ������i�t�@�C���������j
	if (!fp) return;
	//�Z�[�u�f�[�^���܂�܂�ۑ�
	fread(&s_save_data, sizeof(s_save_data), 1, fp);
	//�t�@�C�������
	fclose(fp);
}

void SaveLoad::Save(const char* file)
{
	//�t�@�C���|�C���^
	FILE* fp;
	//�t�@�C�����J�� �o�C�i����������
	fopen_s(&fp, file, "wb");
	//�J���Ȃ������i���̃A�v�����J���Ă���H�j
	if (!fp) return;
	//�Z�[�u�f�[�^���܂�܂�ۑ�
	fwrite(&s_save_data, sizeof(s_save_data), 1, fp);
	//�t�@�C�������
	fclose(fp);
}
