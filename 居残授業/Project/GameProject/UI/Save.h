#pragma once
#include <GLLibrary.h>
//物としてゲーム内には出現しないので、
//Baseの継承はしていない
class SaveLoad {
public:
	//セーブデータ構造体
	struct SaveData {
		int MapData;		//マップのデータ
		int PlayerData;		//プレイヤーのデータ
	};
	//セーブデータ
	static SaveData s_save_data;
public:
	/// データ読み込み
	/// <param name="file">セーブデータファイル名</param>
	static void Load(const char* file);
	/// データ書き込み
	/// <param name="file">セーブデータファイル名</param>
	static void Save(const char* file);

};
