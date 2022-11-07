#pragma once
#include <GLLibrary.h>
//物としてゲーム内には出現しないので、
//Baseの継承はしていない
class SaveLoad {
public:
	//セーブデータ構造体
	struct SaveData {
		int cnt;		//テストカウンター１
		int cnt2;		//テストカウンター２
	};
	//セーブデータ
	static SaveData s_save_data;
public:
	/// <summary>
	/// データ読み込み
	/// </summary>
	/// <param name="file">セーブデータファイル名</param>
	static void Load(const char* file);
	/// <summary>
	/// データ書き込み
	/// </summary>
	/// <param name="file">セーブデータファイル名</param>
	static void Save(const char* file);

};