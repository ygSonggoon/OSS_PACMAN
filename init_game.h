#include "Header.h"

void init_game(Game* game_data)
{
    srand(time(NULL));

    //게임 초기화를 위한 변수 선언 부분입니다
    int ingame_coin_numbers = 0, ingame_enemy_numbers = 0;
    int map_vertical = 0, map_horizontal = 0;

    char map_file_cell_value;

    //팩맨 위치 맵 중앙으로 초기화 하는 부분입니다
    game_data->pacman.pacman_vertical = CELL_SIZE / 2;
    game_data->pacman.pacman_horizontal = CELL_SIZE / 2;
    game_data->pacman.direction = PAUSE;

    //기타 게임 변수 초기화입니다
    game_data->score = 0;
    game_data->lifes = 3;
    game_data->enemies_movement = PAUSE;

    //외부 맵 파일을 읽어오기 위한 변수 선언입니다
    FILE* map_file;
    map_file = fopen("mapa.txt", "r");

    //맵 파일을 읽어오는 함수 부분입니다
    if (map_file == NULL)
    {
        printf("경고! 맵 파일 없음!\n");
        exit(1);
    }
    else
    {
        while ((map_file_cell_value = fgetc(map_file)) != EOF)
        {
            if (map_file_cell_value != '\n')
            {
                //여기서 맵 파일을 읽어올 때 맵에 벽과 길이 설정이 미리 됩니다
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

    //맵 파일 읽어오고 난 후 나머지 정보들을 맵에 입력해주는 반복문 부분입니다
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

    //코인과 적 배열 초과된 부분 초기화 하는 부분입니다
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

    //마지막으로 맵 내부 전체 동전 갯수를 게임 데이터에 입력해줍니다
    game_data->total_coin_number = ingame_coin_numbers;
}
