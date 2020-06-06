/*
[Description]
현재 좌표에 적이 존재하는지 확인하는 함수.

*/
#include "Header.h"

int has_enemy_in_position(Game* game, int x_position, int y_position)
{
	for (int index = 0; index < MAPSIZE*MAPSIZE; index++)
	{
		if (game->enemies[index].i == x_position && game->enemies[index].j == y_position)
			return index; //코인을 찾으면 index값을 반환.
	}

	return -1; //못 찾으면 -1 반환.
}
