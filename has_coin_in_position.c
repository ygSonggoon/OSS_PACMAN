/*
[Description]
���� ��ǥ�� ������ �����ϴ��� Ȯ���ϴ� �Լ�.

*/
#include "Header.h"

int has_coin_in_position(Game *g, int x_position, int y_position)
{
	for (int index = 0; index < CELL_SIZE*CELL_SIZE; index++)
	{
		if (g->coins[index].i == x_position && g->coins[index].j == y_position)
			return index;//������ ã���� index���� ��ȯ.
	}
	return -1;//�� ã���� -1 ��ȯ.
}
