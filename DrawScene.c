/*
[Description]
���� ������ �׷����� ��Ҹ� ȭ�鿡 ������ִ� �Լ�.
*/

#include "Header.h"

void DrawScene(Game* game)
{
	int current_coin_number; //���� ������ ������ �˷��ִ� ����.
	int current_enemy_number; //���� ���� ������ �˷��ִ� ����.

	char print_data[2]; //�ܼ� ȭ�鿡 ����� ���� �������� �����̳�.

	char print_score_life_data[100]; //

	for (int y_position = 0; y_position < MAPSIZE; y_position++)
	{
		for (int x_position = 0; x_position < MAPSIZE; x_position++)
		{
			current_coin_number = HasCoinInPosition(game, y_position, x_position);
			current_enemy_number = HasEnemyInPosition(game, y_position, x_position);

			if (game->map.mapData[y_position][x_position] == WALL)
			{
				// ���� ����ϴ� ��Ʈ.
                SetColor(RED); //Red �÷��� ��� ���� ����.
                strcpy(print_data, "X "); //����� �� ���ڿ��� ����.
				PrintScene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else if (current_enemy_number >= 0)
			{
                // ���� ����ϴ� ��Ʈ.
				SetColor(LIGHTBLUE); //LightBlue �÷��� ����.
                strcpy(print_data, "o "); //����� �� ���ڿ��� ����.
				PrintScene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else if (current_coin_number >= 0)
			{
				// ������ ����ϴ� ��Ʈ.
                SetColor(YELLOW); //Yellow �÷��� ����.
                strcpy(print_data, ". "); //����� ���� ���ڿ��� ����.
				PrintScene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else if (game->pacman.i ==y_position && game->pacman.j == x_position)
			{
				// �÷��̾ ����ϴ� ��Ʈ.
                SetColor(WHITE); //White �÷��� ����.
                strcpy(print_data, "o "); //����� �÷��̾� ���ڿ��� ����.
				PrintScene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else
			{
				// ���� ����ϴ� ��Ʈ.
                strcpy(print_data, "  "); // ���鰪 ����.
				PrintScene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
		}
		printf("\n"); // �� �ٲ�.
	}

    SetColor(WHITE); //White �÷��� ����.
    sprintf(print_score_life_data, "Score: %d\nLifes: %d\n", game->score, game->life); //���� �� ���� ���
    PrintScene(0, 15, print_score_life_data); //15��° ��, 0��° ��ǥ�� �����ϴ� ���� �� ���� ���, ���� �ܼ� ���ۿ� ����.
}
