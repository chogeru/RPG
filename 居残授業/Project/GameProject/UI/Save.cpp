#include "Save.h"


SaveLoad::SaveData SaveLoad::s_save_data;

void SaveLoad::Load(const char* file)
{
	//ファイルポインタ
	FILE* fp;
	//ファイルを開く バイナリ読み込み
	fopen_s(&fp, file, "rb");
	//開けなかった（ファイルが無い）
	if (!fp) return;
	//セーブデータをまるまる保存
	fread(&s_save_data, sizeof(s_save_data), 1, fp);
	//ファイルを閉じる
	fclose(fp);
}

void SaveLoad::Save(const char* file)
{
	//ファイルポインタ
	FILE* fp;
	//ファイルを開く バイナリ書き込み
	fopen_s(&fp, file, "wb");
	//開けなかった（他のアプリが開いている？）
	if (!fp) return;
	//セーブデータをまるまる保存
	fwrite(&s_save_data, sizeof(s_save_data), 1, fp);
	//ファイルを閉じる
	fclose(fp);
}
