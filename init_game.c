#include "Header.h"

void init_game(Game* game_data)
{
    srand(time(NULL));

    //���� �ʱ�ȭ�� ���� ���� ���� �κ��Դϴ�
    int ingame_coin_numbers = 0, ingame_enemy_numbers = 0;
    int map_vertical = 0, map_horizontal = 0;

    char map_file_cell_value;

    //�Ѹ� ��ġ �� �߾����� �ʱ�ȭ �ϴ� �κ��Դϴ�
    game_data->pacman.pacman_vertical = CELL_SIZE / 2;
    game_data->pacman.pacman_horizontal = CELL_SIZE / 2;
    game_data->pacman.direction = PAUSE;

    //��Ÿ ���� ���� �ʱ�ȭ�Դϴ�
    game_data->score = 0;
    game_data->lifes = 3;
    game_data->enemies_movement = PAUSE;

    //�ܺ� �� ������ �о���� ���� ���� �����Դϴ�
    FILE* map_file;
    map_file = fopen("mapa.txt", "r");

    //�� ������ �о���� �Լ� �κ��Դϴ�
    if (map_file == NULL)
    {
        printf("���! �� ���� ����!\n");
        exit(1);
    }
    else
    {
        while ((map_file_cell_value = fgetc(map_file)) != EOF)
        {
            if (map_file_cell_value != '\n')
            {
                //���⼭ �� ������ �о�� �� �ʿ� ���� ���� ������ �̸� �˴ϴ�
                game_data->map.MAP[map_vertical][map_horizontal] = map_file_cell_value;
                map_horizontal++;
            }
            else
            {
                map_horizontal = 0;
                map_vertical++;
            }
        }
        fclose(map_file);
    }

    //�� ���� �о���� �� �� ������ �������� �ʿ� �Է����ִ� �ݺ��� �κ��Դϴ�
    for (map_vertical = 0; map_vertical < CELL_SIZE; map_vertical++)
    {
        for (map_horizontal = 0; map_horizontal < CELL_SIZE; map_horizontal++)
        {
            if ((game_data->pacman.pacman_vertical != map_vertical || game_data->pacman.pacman_horizontal != map_horizontal) && game_data->map.MAP[map_vertical][map_horizontal] != WALL)
            {
                game_data->map.MAP[map_vertical][map_horizontal] = BLANK;

                if (((map_vertical == 1 || map_vertical == CELL_SIZE - 2) && (map_horizontal == 1 || map_horizontal == CELL_SIZE - 2)) && ingame_enemy_numbers < ENEMY_NUMBERS)
                {
                    game_data->enemies[ingame_enemy_numbers].i = map_vertical;
                    game_data->enemies[ingame_enemy_numbers].j = map_horizontal;
                    ingame_enemy_numbers++;

                }
                game_data->coins[ingame_coin_numbers].i = map_vertical;
                game_data->coins[ingame_coin_numbers].j = map_horizontal;
                ingame_coin_numbers++;
            }
        }
    }

    //���ΰ� �� �迭 �ʰ��� �κ� �ʱ�ȭ �ϴ� �κ��Դϴ�
    for (int i = ingame_coin_numbers + 1; i < CELL_SIZE * CELL_SIZE; i++)
    {
        game_data->coins[i].i = -1;
        game_data->coins[i].j = -1;
    }

    for (int i = ingame_enemy_numbers + 1; i < CELL_SIZE * CELL_SIZE; i++)
    {
        game_data->enemies[i].i = -1;
        game_data->enemies[i].j = -1;
        game_data->enemies[i].direction = PAUSE;
    }

    //���������� �� ���� ��ü ���� ������ ���� �����Ϳ� �Է����ݴϴ�
    game_data->total_coin_number = ingame_coin_numbers;
}
