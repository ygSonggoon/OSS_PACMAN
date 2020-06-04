#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include <windows.h>
#include <time.h>

#define MAPSIZE 13 //맵 크기
#define WALL 'X'
#define ROAD ' '

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define DEACTIVE 'p'
#define ACTIVE 'm'

typedef struct map
{
	char mapData[MAPSIZE][MAPSIZE];
} Map; // 맵 구조체

typedef struct pacman
{
	int i, j; // 좌표값
	char direction; //입력 방향

    char *player_graphic;
    int player_graphic_length;
} Player; // 플레이어 구조체

typedef struct enemy
{
	int i, j; // 좌표값
	char direction; // 방향

    char *enemy_graphic;
    int enemy_graphic_length;
} Enemy; // 적 구조체

typedef struct coin
{
	int i, j; // 좌표값

	char *coin_graphic;
	int coin_graphic_length;
} Coin; //코인 아이템 구조체

typedef struct Game
{
	Map map; // 지도
	Player pacman; // 플레이어
	unsigned int score; // 점수
	Coin coins[MAPSIZE*MAPSIZE]; // 코인 아이템 (최대 좌표 13*13 내에 생성해야 하기 때문에 최대 크기로 받은 것으로 추정)
	Enemy enemies[MAPSIZE*MAPSIZE]; // 적 (최대 좌표 13*13 내에 생성해야 하기 때문에 최대 크기로 받은 것으로 추정)
	unsigned int total_coins_number; // 코인 아이템 갯수?
	unsigned short int life; //라이프 값
	short int enemyMovement; //적 움직임 변수
} Game; // Game Manager 구조체라 생각됨

// 충돌 처리 함수
void CheckCoinCollision(Game* game, int y_position, int x_position);
void CheckEnemyCollision(Game* game, int y_position, int x_position);
// 현재 좌표의 오브젝트 구분 함수
int HasCoinInPosition(Game *game, int x_position, int y_position);
int HasEnemyInPosition(Game *game,int x_position, int y_position);
// 화면 관련 함수
void RenderingPipeline(Game *game); //렌더링 하는 과정을 총괄하는 함수.

void InitScene(); //화면 초기화 함수.
void FlipScene(); //화면 바꾸어 줄 함수.
void ClearScene(); //화면을 지워줄 함수.
void ReleaseScene(); //프로그램 종료 시 화면을 삭제하는 함수.
void PrintScene(int y_position, int x_position, char* print_data);
void SetColor(unsigned short color);
void SetTextColors(unsigned short text_color, unsigned short background_color);

void DrawScene(Game* game); //실제 렌더링 함수.
