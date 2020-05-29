/*
[Description]
���� ��ǥ�� ���� �����ϴ��� Ȯ���ϴ� �Լ�.

*/
#include "Header.h"

int HasEnemyInPosition(Game* game, int x_position, int y_position)
{
	for (int index = 0; index < MAPSIZE*MAPSIZE; index++)
	{
		if (game->enemies[index].i == x_position && game->enemies[index].j == y_position)
			return index;
	}

	return -1;
}
