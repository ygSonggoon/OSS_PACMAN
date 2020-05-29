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
} Player; // 플레이어 구조체

typedef struct enemy
{
	int i, j; // 좌표값
	char direction; // 방향
} Enemy; // 적 구조체

typedef struct coin
{
	int i, j; // 좌표값
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


void CheckCoinCollision(Game* game, int y_position, int x_position);
void CheckEnemyCollision(Game* game, int y_position, int x_position);



int HasCoinInPosition(Game *game, int x_position, int y_position);
int HasEnemyInPosition(Game *game,int x_position, int y_position);

void DrawScene(Game* game);
