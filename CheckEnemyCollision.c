/*
[Description]
���� �÷��̾ �浹�ߴ��� üũ���ִ� �Լ�.
*/

#include "Header.h"

void check_enemy_collision(Game* game, int y_position, int x_position)
{
	int current_enemies_index; // ���� ���� �����ϴ��� üũ ���� ����.

	current_enemies_index = has_enemy_in_position(game, y_position, x_position); // ���� ��ġ�� ���� �����ϴ��� HasEnemyInPosition �Լ��� Ȯ��.

	if (current_enemies_index >= 0)
	{
		game->coins[current_enemies_index].i = REMOVED; // ȥ�� �Ǵ� �� ����
		game->coins[current_enemies_index].j = REMOVED; // ȥ�� �Ǵ� �� ����

		game->life--; //���� - 1

		game->pacman.i = MAPSIZE / 2;
		game->pacman.j = MAPSIZE / 2;
		//�÷��̾��� ��ǥ�� �ʱ�ȭ

		game->pacman.direction = DEACTIVE;
		game->enemyMovement = DEACTIVE;
		//�÷��̾� �� �� ������ ��Ȱ��ȭ.
	}
}
