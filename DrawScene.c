/*
[Description]
현재 게임의 그래픽적 요소를 화면에 출력해주는 함수.
*/

#include "Header.h"

void DrawScene(Game* game)
{
	int current_coin_number; //현재 코인의 갯수를 알려주는 변수.
	int current_enemy_number; //현재 적의 갯수를 알려주는 변수.

	char print_data[2];

	char print_score_life_data[100];

	for (int y_position = 0; y_position < MAPSIZE; y_position++)
	{
		for (int x_position = 0; x_position < MAPSIZE; x_position++)
		{
			current_coin_number = HasCoinInPosition(game, y_position, x_position);
			current_enemy_number = HasEnemyInPosition(game, y_position, x_position);

			if (game->map.mapData[y_position][x_position] == WALL)
			{
				// 길 출력
                //SetTextColors(0x000e,RED);
                SetColor(RED);
                strcpy(print_data, "X ");
				PrintScene(x_position, y_position, print_data);
			}
			else if (current_enemy_number >= 0)
			{
				// 적 출력
				SetColor(LIGHTBLUE);
                //SetTextColors(LIGHTBLUE,BLACK);
//                sprintf(print_data, "%s", "◎");
                strcpy(print_data, "o ");
				PrintScene(x_position, y_position, print_data);
                //printf("o ");
                //PrintScene(x_position, y_position, "o ");
			}
			else if (current_coin_number >= 0)
			{
				// 코인 출력
                //SetTextColors(YELLOW,BLACK);
                SetColor(YELLOW);
                strcpy(print_data, ". ");
 //               sprintf(print_data, "%s", ". ");
				PrintScene(x_position, y_position, print_data);
                /*textbackground(BLACK);
                textcolor(YELLOW);
                PrintScene(x_position, y_position, ". ");
                textcolor(WHITE);
                textbackground(BLACK);*/
			}
			else if (game->pacman.i ==y_position && game->pacman.j == x_position)
			{
				//플레이어 출력
                //SetTextColors(WHITE,BLACK);
                SetColor(WHITE);
                strcpy(print_data, "o ");
                //sprintf(print_data, "%s", "○");
				PrintScene(x_position, y_position, print_data);
                /*textbackground(BLACK);
                textcolor(WHITE);
                PrintScene(x_position, y_position, "o ");
                textcolor(WHITE);
                textbackground(BLACK);*/
			}
			else
			{
				// 길 출력
                SetColor(WHITE);
                strcpy(print_data, "  ");
                //sprintf(print_data, "%s","  ");
				PrintScene(x_position, y_position, print_data);

                /*textbackground(BLACK);
                textcolor(WHITE);
				PrintScene(x_position, y_position, "  ");
                textcolor(WHITE);
                textbackground(BLACK);*/
			}
		}
		printf("\n");
	}

    SetColor(WHITE);
    sprintf(print_score_life_data, "Score: %d\nLifes: %d\n", game->score, game->life);
    PrintScene(0, 15, print_score_life_data);
}
