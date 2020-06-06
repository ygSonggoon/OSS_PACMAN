/*
[Description]
���� �÷��̾ �浹�ߴ��� üũ���ִ� �Լ�.
*/

#include "Header.h"

void collision_enemy_check(Game* g, int y_position, int x_position, int* flag)
{
	int current_enemies_index; // 현재 적이 존재하는지 체크 해줄 변수.

	current_enemies_index = has_enemy_in_position(g, y_position, x_position); // 현재 위치에 적이 존재하는지 HasEnemyInPosition 함수로 확인.

	if (current_enemies_index >= 0)
	{
		g->coins[current_enemies_index].i = REMOVED; // 혼용 되는 값 정리
		g->coins[current_enemies_index].j = REMOVED; // 혼용 되는 값 정리

		g->lifes--;  //생명값 - 1

		g->pacman.pacman_horizontal = CELL_SIZE / 2;
		g->pacman.pacman_vertical = CELL_SIZE / 2;
		//플레이어의 좌표값 초기화


		g->pacman.direction = PAUSE;
		g->enemies_movement = PAUSE;
		//플레이어 및 적 움직임 비활성화.

        //진행상태에서 종료상태로 바꾸기 위한 포인터변수값 초기화.
        *flag = 0;
	}
}
