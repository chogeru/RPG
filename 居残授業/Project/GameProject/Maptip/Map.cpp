#include "Map.h"
#include"../h.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	/*	switch (eType_Player == eType_Dordown) {
			
		case eType_Dor 1:
			if 
			{
			*/
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,10,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,7,7,7,7,5,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,5,7,7,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,7,7,7,7,6,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,6,7,7,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },

		/*}
break;*/







	/*{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},
	*//*
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0},
	{ 0,0,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,0,0,0,0,0,0},
	{ 0,0,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,0,0,0,0,0,0},
	{ 0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,8.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,8,1,1,1,1,8,8,8,8,8,8,8,8,1,1,1,1,1,8,8,8,8,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,8,1,1,1,8,7,7,7,7,7,7,7,8,1,1,1,1,1,8,7,7,8,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,8,1,1,1,8,7,7,7,7,7,7,7,8,1,1,1,1,1,8,7,7,8,1,1,1,1,8,8,8,8,8,8,0},
	{ 0,0,8,1,1,1,7,8,8,8,8,8,8,0,8,1,1,1,1,1,8,0,0,8,1,1,1,1,7,7,5,7,7,8,0},
	{ 0,0,8,1,1,1,7,7,7,5,7,7,8,0,8,1,1,1,1,1,8,0,0,8,1,1,1,1,7,7,6,7,7,8,0},
	{ 0,0,8,1,1,1,1,7,7,6,7,7,8,0,8,1,1,1,1,1,8,0,0,8,1,1,1,1,1,1,1,1,1,8,0},
	{ 0,0,8,1,1,1,1,1,1,1,1,1,8,0,8,1,1,1,1,1,8,0,0,8,1,1,1,1,1,1,1,1,1,8,0},
	{ 0,0,8,1,1,1,1,1,1,1,1,1,8,0,8,1,1,1,1,1,8,0,0,8,1,1,1,1,1,1,1,1,1,8,0},
	{ 0,0,8,1,1,1,1,1,1,1,1,1,8,0,8,1,1,1,1,1,8,0,0,8,8,8,8,8,8,8,8,8,8,8,0},
	{ 0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,1,3,2,4,1,8,0,0,7,7,7,7,7,7,7,7,7,7,7,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,0,0,7,7,7,7,7,7,7,7,7,7,7,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	*/
};
/*
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,7,7,7,7,5,7,7,7,7,7,7,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},



    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,18,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,18,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,18,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,18,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,18,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,18,0,0,0,0,0,0},
	
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,0,0,0,0,0,0},

	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},


	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},


	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
	{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},

	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,},

}*/

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
			case 4:
				Base::Add(new itihara(CVector2D(x, y), true));
				break;
			case 5:
				Base::Add(new Dorup(CVector2D(x, y)));
				break;
			case 6:
				Base::Add(new Dordown(CVector2D(x, y)));
				break;
			case 7:
				Base::Add(new Wall(CVector2D(x, y)));
				break;
			case 8:
				Base::Add(new Wallhed(CVector2D(x, y)));
				break;

			case 9:
				Base::Add(new kaiga(CVector2D(x, y),true));
				break;
			case 10:
				Base::Add(new Enemy(CVector2D(x, y)));
				break;
			}
			t = 0;
		}
	}


	
		//画像複製
		m_img = COPY_RESOURCE("Map1", CImage);
	
		
	
}

void Map::Draw()
{


	int x1 = m_scroll.x / MAP_TIP_SIZE;
	if (x1 < 0) x1 = 0;
	int	x2 = x1 + 32;
	if (x2 > MAP_WIDTH - 1) x2 = MAP_WIDTH - 1;

	int y1 = m_scroll.y / MAP_TIP_SIZE;
	if (y1 < 0) y1 = 0;
	int	y2 = y1 + 32;
	if (y2 > MAP_HEIGHT - 1) y2 = MAP_HEIGHT - 1;
	//マップチップによる表示の繰り返しac

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = x1; j < x2; j++) {
			if (stage1data[i][j] == 0)continue;
			int& t = stage1data[i][j];
			if (stage1data[i][j] == 0)continue;
			
			m_img.SetRect(32, 0, 32 + 32, 32);
			//表示サイズ設定
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//表示位置設定
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
		

			//描画
			m_img.Draw();


		}
	}
}
void Map::Update()
{
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y + 1280 / 2;
}
; int Map::GetTip(const CVector2D& pos)
{
	//列を計算
	int col = pos.x / MAP_TIP_SIZE;
	//列の制限(0〜MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > MAP_WIDTH - 1) col = MAP_WIDTH - 1;
	//行を計算
	int raw = pos.y / MAP_TIP_SIZE;
	//行の制限(0〜MAP_HEIGHT-1)
	if (raw < 0) raw = 0;
	if (raw > MAP_HEIGHT - 1) raw = MAP_HEIGHT - 1;
	//チップデータを返却
	return GetTip(col, raw);
}
int Map::GetTip(int col, int raw)
{
	return stage1data[raw][col];
}

int Map::CollisionMap(const CVector2D& pos)
{
	//1点のみ検証
	int t = GetTip(pos);
	if (t != 0) return t;

	return 0;
}
int Map::CollisionMap(const CVector2D& pos, const CRect& rect)
{
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 0) return t;
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 0) return t;
	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
	if (t != 0) return t;
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 0) return t;
	return 0;
}
