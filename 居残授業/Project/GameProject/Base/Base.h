#pragma once
#include <GLLibrary.h>
enum {
	eType_Field,
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Goal,
	eType_Player_Attack,
	eType_Enemy_Attack,
	eType_Effect,
	eType_UI,
	eType_Scene,
	eType_kamano,
	eType_hayashi,
	eType_Wall,
	eType_itihara,
	eType_Dorup,
	eType_Dordown,
	eType_kaiga,
	eType_Player_Bullet,
	eType_Enemy_Bullet,
	eTyppe_trapbullet,
	eType_EnemyManager,
	eType_hondana,
	eType_AreaChange,
};


#define GRAVITY (9.8f/20)
class Base {
public:

	//オブジェクトの種類
	int m_type;
	//座標データ
	CVector2D m_pos;
	//半径
	float m_rad;
	//移動ベクトル
	CVector2D m_vec;
	//削除フラグ
	bool m_kill;
	//移動前の座標
	CVector2D m_pos_old;
	//オブジェクトのリスト
	static std::list<Base*> m_list;
	//矩形
	CRect	m_rect;	
	//回転値
	float m_ang;
	//スクロール値
	static CVector2D m_scroll;
	//ヒットID
	int	m_hit_id;
	
public:
	static CVector2D GetScreenPos(const CVector2D& pos);
	//type オブジェクトの種類
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	//削除フラグON
	void SetKill() { m_kill = true; }
	//全てのオブジェクトの更新
	static void UpdateAll();
	//全てのオブジェクトの描画
	static void DrawAll();
	//全てのオブジェクトの当たり判定検証
	static void CollisionAll();
	//削除チェック
	static void CheckKillAll();
	//オブジェクトの追加
	static void Add(Base* b);
	static void KillAll();
	//円同士の衝突
	static bool CollisionCircle(Base* b1, Base* b2);
	//矩形同士の判定
	static bool CollisionRect(Base* b1, Base* b2);
	/// 矩形の表示
	void DrawRect();

	static Base* FindObject(int type);
	static std::list<Base*> FindObjects(int type);
	void ResetPos(const CVector2D& pos) {
		m_pos = m_pos_old = pos;
	}
};

