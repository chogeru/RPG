#pragma once
#include <GLLibrary.h>
//���Ƃ��ăQ�[�����ɂ͏o�����Ȃ��̂ŁA
//Base�̌p���͂��Ă��Ȃ�
class SaveLoad {
public:
	//�Z�[�u�f�[�^�\����
	struct SaveData {
		int cnt;		//�e�X�g�J�E���^�[�P
		int cnt2;		//�e�X�g�J�E���^�[�Q
	};
	//�Z�[�u�f�[�^
	static SaveData s_save_data;
public:
	/// <summary>
	/// �f�[�^�ǂݍ���
	/// </summary>
	/// <param name="file">�Z�[�u�f�[�^�t�@�C����</param>
	static void Load(const char* file);
	/// <summary>
	/// �f�[�^��������
	/// </summary>
	/// <param name="file">�Z�[�u�f�[�^�t�@�C����</param>
	static void Save(const char* file);

};