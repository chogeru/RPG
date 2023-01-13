#include "AnimData.h"

static TexAnim(kamanoLeft)[] = {
	{ 1,8 },
	{ 5,8 },
	{ 9,8 },
	
};
static TexAnim(kamanoRight)[] = {

	{ 2,8 },
	{ 6,8 },
	{ 10,8 },
	
};
static TexAnim kamanoUp[] = {
	{3,8},
	{7,8},
	{11,8},
	};
static TexAnim kamanoDown[] = {



		{0,8},
		{4,8},
		{8,8},


	};

TexAnimData kamano_anim_data[] = {
	//ANIMDATA(kamanoIdle),
	
	ANIMDATA(kamanoLeft),
	ANIMDATA(kamanoRight),
	ANIMDATA(kamanoUp),
	ANIMDATA(kamanoDown),
	//ANIMDATA(kamanoStep),

};
static TexAnim EnemyLeft[] = {
	{2,2},
	{6,2},
};
static TexAnim EnemyRight[] = {

	{1,2},
	{5,2},
};
static TexAnim EnemyUp[] = {
	{3,2},
	{7,2},
};
static TexAnim EnemyDown[] = {

	{0,2},
	{4,2},

		
	


};
TexAnimData Enemy_anim_data[] = {
	

	ANIMDATA(EnemyLeft),
	ANIMDATA(EnemyRight),
	ANIMDATA(EnemyUp),
	ANIMDATA(EnemyDown),
	//ANIMDATA(kamanoStep),

};
static TexAnim Title[] = {
	{3,8},
};
TexAnimData Title_anim_data[] = {

	ANIMDATA(Title)

};
static TexAnim _Gameover[] = {
	{0,2},
	{1,2},
	{2,2},
	{3,2},
	{4,2},
	{5,8},
};
TexAnimData  Gameover_anim_data[] = {
    ANIMDATA(_Gameover),
};