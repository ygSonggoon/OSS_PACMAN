/*
[Description]
���� ������ �׷����� ��Ҹ� ȭ�鿡 ������ִ� �Լ�.
*/

#include "Header.h"

void draw_scene(Game* g)
{
	int current_coin_number; //���� ������ ������ �˷��ִ� ����.
	int current_enemy_number; //���� ���� ������ �˷��ִ� ����.

	char print_data[2];  //�ܼ� ȭ�鿡 ����� ���� �������� �����̳�.


	char print_score_life_data[100];

	for (int y_position = 0; y_position < CELL_SIZE; y_position++)
	{
		for (int x_position = 0; x_position < CELL_SIZE; x_position++)
		{
			current_coin_number = has_coin_in_position(g, y_position, x_position);
			current_enemy_number = has_enemy_in_position(g, y_position, x_position);

			if (g->map.MAP[y_position][x_position] == WALL)
			{
                // ���� ����ϴ� ��Ʈ.
                set_color(RED);//Red �÷��� ��� ���� ����.
                strcpy(print_data, "X "); //����� �� ���ڿ��� ����.
								print_scene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else if (current_enemy_number >= 0)
			{
                // ���� ����ϴ� ��Ʈ.
								set_color(LIGHTBLUE); //LightBlue �÷��� ����.
                    strcpy(print_data, "o ");//����� �� ���ڿ��� ����.
								print_scene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else if (current_coin_number >= 0)
			{
				// ������ ����ϴ� ��Ʈ.
                set_color(YELLOW); //Yellow �÷��� ����
                strcpy(print_data, ". ");//����� ���� ���ڿ��� ����.
								print_scene(x_position, y_position, print_data); //ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else if (g->pacman.pacman_vertical ==y_position && g->pacman.pacman_horizontal == x_position)
			{
				// �÷��̾ ����ϴ� ��Ʈ.
                set_color(WHITE);//White �÷��� ����.
                strcpy(print_data, "o "); //����� �÷��̾� ���ڿ��� ����.
								print_scene(x_position, y_position, print_data);//ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
			else
			{
				// ���� ����ϴ� ��Ʈ.
                strcpy(print_data, "  "); // ���鰪 ����.
								print_scene(x_position, y_position, print_data);//ȭ�鿡 ��� �� ���� �ܼ� ���ۿ� ����.
			}
		}
		printf("\n"); // �� �ٲ�.
	}

    set_color(WHITE);  //White �÷��� ����.
    sprintf(print_score_life_data, "Score: %d\nLifes: %d\n", g->score, g->lifes); //���� �� ���� ���
    print_scene(0, 15, print_score_life_data);//15��° ��, 0��° ��ǥ�� �����ϴ� ���� �� ���� ���, ���� �ܼ� ���ۿ� ����.
}
