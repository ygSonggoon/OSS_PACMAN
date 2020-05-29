/*
[Description]
���� �÷��̾ �浹�ߴ��� üũ���ִ� �Լ�.
*/

#include "Header.h"

void CheckEnemyCollision(Game* game, int y_position, int x_position)
{
	int current_enemies_index;
	current_enemies_index = HasEnemyInPosition(game, y_position, x_position);

	if (current_enemies_index >= 0)
	{
		game->coins[current_enemies_index].i = -99;
		game->coins[current_enemies_index].j = -99;

		game->life--;

		game->pacman.i = MAPSIZE / 2;
		game->pacman.j = MAPSIZE / 2;

		game->pacman.direction = DEACTIVE;
		game->enemyMovement = DEACTIVE;
	}
}
