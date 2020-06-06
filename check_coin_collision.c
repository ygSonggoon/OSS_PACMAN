/*
[Description]
코인과 플레이어가 충돌했는지 체크해주는 함수.
*/

#include "Header.h"

void check_coin_collision(Game* g, int y_position, int x_position)
{
	int current_coins_index; // 현재 검색중인 코인의 index값 받을 변수.

	current_coins_index = has_coin_in_position(g, y_position, x_position);
    // 현재 코인이 좌표에 존재하는지 확인할 변수.
	if (current_coins_index >= 0)
	{
		g->coins[current_coins_index].i = REMOVED; // 삭제 완료
		g->coins[current_coins_index].j = REMOVED; // 삭제 완료

		g->score += 10; // 점수 추가.
		g->total_coin_number--; // 총 코인의 개수 줄이기.
	}
}
