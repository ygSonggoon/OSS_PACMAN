/*
[Description]
현재 게임의 그래픽적 요소를 화면에 출력해주는 함수.
*/

#include "Header.h"

void DrawScene(Game* game)
{
	int current_coin_number; //현재 코인의 갯수를 알려주는 변수.
	int current_enemy_number; //현재 적의 갯수를 알려주는 변수.

	for (int y_position = 0; y_position < MAPSIZE; y_position++)
	{
		for (int x_position = 0; x_position < MAPSIZE; x_position++)
		{
			current_coin_number = HasCoinInPosition(game, y_position, x_position);
			current_enemy_number = HasEnemyInPosition(game, y_position, x_position);

			if (game->map.mapData[y_position][x_position] == WALL)
			{
				// 길 출력
                textbackground(RED);
				PrintScene(y_position, x_position, "  ");
                textbackground(BLACK);
			}
			else if (current_enemy_number >= 0)
			{
				// 적 출력
                textbackground(BLACK);
                textcolor(LIGHTBLUE);
                PrintScene(y_position, x_position, "o ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
			else if (current_coin_number >= 0)
			{
				// 코인 출력
                textbackground(BLACK);
                textcolor(YELLOW);
                PrintScene(y_position, x_position, ". ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
			else if (game->pacman.i ==y_position && game->pacman.j == x_position)
			{
				//플레이어 출력
                textbackground(BLACK);
                textcolor(WHITE);
                PrintScene(y_position, x_position, "o ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
			else
			{
				// 벽 출력
                textbackground(BLACK);
                textcolor(WHITE);
				PrintScene(y_position, x_position, "  ");
                textcolor(WHITE);
                textbackground(BLACK);
			}
		}
		printf("\n");
	}

}
