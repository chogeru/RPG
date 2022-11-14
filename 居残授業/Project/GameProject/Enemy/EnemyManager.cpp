#include "EnemyManager.h"
#include "Enemy.h"

//敵の出現データまとめ
EnemyManager::EnemyData _stage1[] = {
	{0,CVector2D(2000,10000),120},
	

};
//敵の出現データまとめ
EnemyManager::EnemyDataArray _enemy_data[] = {
	{_stage1,sizeof(_stage1) / sizeof(_stage1[0])},
};

EnemyManager::EnemyManager():Base(eType_EnemyManager)
{
	m_cnt = 0;
	m_idx = 0;
	mp_data = &_enemy_data[0];

}

void EnemyManager::Update()
{
	//全ての敵が出ていない
	if (m_idx < mp_data->size) {
		//時間経過
		m_cnt++;

		EnemyData* d = &mp_data->data[m_idx];
		//指定時間を超えると敵が出現
		if (m_cnt >= d->cnt) {
			//敵生成
			Base::Add(new Enemy(d->pos));
			//次の出現データを参照
			m_idx++;
			m_cnt = 0;
		}
	}
}
bool EnemyManager::isEnd() {
	//全ての敵が出現済みならtrueを返す
	return (m_idx >= mp_data->size) ? true : false;
}
