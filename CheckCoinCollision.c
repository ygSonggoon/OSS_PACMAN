/*
[Description]
코인과 플레이어가 충돌했는지 체크해주는 함수.
*/

#include "Header.h"

void CheckCoinCollision(Game* game, int y_position, int x_position)
{
	int current_coins_index; // 현재 검색중인 코인의 index값 받을 변수.
	current_coins_index = HasCoinInPosition(game, y_position, x_position);

	if (current_coins_index >= 0)
	{
		game->coins[current_coins_index].i = -1;
		game->coins[current_coins_index].j = -1;

		game->score += 10;
		game->total_coins_number--;
	}
}
