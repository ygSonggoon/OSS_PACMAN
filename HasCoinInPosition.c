/*
[Description]
���� ��ǥ�� ������ �����ϴ��� Ȯ���ϴ� �Լ�.

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
