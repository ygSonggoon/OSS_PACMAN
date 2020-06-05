/*
[Description]
현재 게임의 그래픽적 요소를 화면에 출력해주는 함수.
*/

#include "Header.h"

void DrawScene(Game* game)
{
	int current_coin_number; //현재 코인의 갯수를 알려주는 변수.
	int current_enemy_number; //현재 적의 갯수를 알려주는 변수.

	char print_data[2]; //콘솔 화면에 출력할 값을 저장해줄 컨테이너.

	char print_score_life_data[100]; //

	for (int y_position = 0; y_position < MAPSIZE; y_position++)
	{
		for (int x_position = 0; x_position < MAPSIZE; x_position++)
		{
			current_coin_number = HasCoinInPosition(game, y_position, x_position);
			current_enemy_number = HasEnemyInPosition(game, y_position, x_position);

			if (game->map.mapData[y_position][x_position] == WALL)
			{
				// 벽을 출력하는 파트.
                SetColor(RED); //Red 컬러로 출력 색상값 지정.
                strcpy(print_data, "X "); //출력할 벽 문자열을 저장.
				PrintScene(x_position, y_position, print_data); //화면에 출력 및 다음 콘솔 버퍼에 저장.
			}
			else if (current_enemy_number >= 0)
			{
                // 적을 출력하는 파트.
				SetColor(LIGHTBLUE); //LightBlue 컬러로 지정.
                strcpy(print_data, "o "); //출력할 적 문자열을 저장.
				PrintScene(x_position, y_position, print_data); //화면에 출력 및 다음 콘솔 버퍼에 저장.
			}
			else if (current_coin_number >= 0)
			{
				// 코인을 출력하는 파트.
                SetColor(YELLOW); //Yellow 컬러로 지정.
                strcpy(print_data, ". "); //출력할 코인 문자열을 저장.
				PrintScene(x_position, y_position, print_data); //화면에 출력 및 다음 콘솔 버퍼에 저장.
			}
			else if (game->pacman.i ==y_position && game->pacman.j == x_position)
			{
				// 플레이어를 출력하는 파트.
                SetColor(WHITE); //White 컬러로 지정.
                strcpy(print_data, "o "); //출력할 플레이어 문자열을 저장.
				PrintScene(x_position, y_position, print_data); //화면에 출력 및 다음 콘솔 버퍼에 저장.
			}
			else
			{
				// 길을 출력하는 파트.
                strcpy(print_data, "  "); // 공백값 저장.
				PrintScene(x_position, y_position, print_data); //화면에 출력 및 다음 콘솔 버퍼에 저장.
			}
		}
		printf("\n"); // 줄 바꿈.
	}

    SetColor(WHITE); //White 컬러로 지정.
    sprintf(print_score_life_data, "Score: %d\nLifes: %d\n", game->score, game->life); //점수 및 생명값 출력
    PrintScene(0, 15, print_score_life_data); //15번째 줄, 0번째 좌표에 시작하는 점수 및 생명값 출력, 다음 콘솔 버퍼에 저장.
}
