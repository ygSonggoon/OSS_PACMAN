/*
[Description]
���� ������ �׷����� ��Ҹ� ȭ�鿡 ������ִ� �Լ�.
*/

#include "Header.h"

void DrawScene(Game* game)
{
	int current_coin_number; //���� ������ ������ �˷��ִ� ����.
	int current_enemy_number; //���� ���� ������ �˷��ִ� ����.

	for (int y_position = 0; y_position < MAPSIZE; y_position++)
	{
		for (int x_position = 0; x_position < MAPSIZE; x_position++)
		{
			current_coin_number = HasCoinInPosition(game, y_position, x_position);
			current_enemy_number = HasEnemyInPosition(game, y_position, x_position);

			if (game->map.mapData[y_position][x_position] == WALL)
			{
				// �� ���
                textbackground(RED);
				printf("  ");
                textbackground(BLACK);
			}
			else if (current_enemy_number >= 0)
			{
				// �� ���
                textbackground(BLACK);
                textcolor(LIGHTBLUE);
				printf("o ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
			else if (current_coin_number >= 0)
			{
				// ���� ���
                textbackground(BLACK);
                textcolor(YELLOW);
				printf(". ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
			else if (game->pacman.i ==y_position && game->pacman.j == x_position)
			{
				//�÷��̾� ���
                textbackground(BLACK);
                textcolor(WHITE);
				printf("o ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
			else
			{
				// �� ���
                textbackground(BLACK);
                textcolor(WHITE);
				printf("  ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
		}
		printf("\n");
	}
}
