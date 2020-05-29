/*
[Description]
현재 좌표에 코인이 존재하는지 확인하는 함수.

*/
#include "Header.h"

int HasCoinInPosition(Game *game, int x_position, int y_position)
{
	for (int index = 0; index < MAPSIZE*MAPSIZE; index++)
	{
		if (game->coins[index].i == x_position && game->coins[index].j == y_position)
			return index;
	}
	return -1;
}
