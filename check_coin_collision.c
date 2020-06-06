/*
[Description]
���ΰ� �÷��̾ �浹�ߴ��� üũ���ִ� �Լ�.
*/

#include "Header.h"

void check_coin_collision(Game* g, int y_position, int x_position)
{
	int current_coins_index; // ���� �˻����� ������ index�� ���� ����.

	current_coins_index = has_coin_in_position(g, y_position, x_position);
    // ���� ������ ��ǥ�� �����ϴ��� Ȯ���� ����.
	if (current_coins_index >= 0)
	{
		g->coins[current_coins_index].i = REMOVED; // ���� �Ϸ�
		g->coins[current_coins_index].j = REMOVED; // ���� �Ϸ�

		g->score += 10; // ���� �߰�.
		g->total_coin_number--; // �� ������ ���� ���̱�.
	}
}
