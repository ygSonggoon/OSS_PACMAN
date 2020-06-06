/*
[Description]
���� �÷��̾ �浹�ߴ��� üũ���ִ� �Լ�.
*/

#include "Header.h"

void check_enemy_collision(Game* game, int y_position, int x_position)
{
	int current_enemies_index; // 현재 적이 존재하는지 체크 해줄 변수.

	current_enemies_index = has_enemy_in_position(game, y_position, x_position); // 현재 위치에 적이 존재하는지 HasEnemyInPosition 함수로 확인.

	if (current_enemies_index >= 0)
	{
		game->coins[current_enemies_index].i = REMOVED; // 혼용 되는 값 정리
		game->coins[current_enemies_index].j = REMOVED; // 혼용 되는 값 정리

		game->lifes--;  //생명값 - 1

		game->pacman.pacman_horizontal = CELL_SIZE / 2;
		game->pacman.pacman_vertical = CELL_SIZE / 2;
		//플레이어의 좌표값 초기화


		game->pacman.direction = PAUSE;
		game->enemies_movement = PAUSE;
		//플레이어 및 적 움직임 비활성화.
	}
}
