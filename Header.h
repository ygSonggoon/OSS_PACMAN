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

#define REMOVED -1 // 코인 배열을 삭제할 때 쓸 값.

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

// 충돌 처리 함수
void check_coin_collision(Game* game, int y_position, int x_position);
void check_enemy_collision(Game* game, int y_position, int x_position);
// 현재 좌표의 오브젝트 구분 함수
int has_coin_in_position(Game *game, int x_position, int y_position);
int has_enemy_in_position(Game *game,int x_position, int y_position);
// 화면 관련 함수
void rendering_pipeline(Game *game); //렌더링 하는 과정을 총괄하는 함수.

void init_scene(); //화면 초기화 함수.
void flip_scene(); //화면 바꾸어 줄 함수.
void clear_scene(); //화면을 지워줄 함수.
void release_scene(); //프로그램 종료 시 화면을 삭제하는 함수.
void print_scene(int y_position, int x_position, char* print_data); //화면을 출력해 줄 함수.
void set_color(unsigned short color); //문자의 색상을 지정해 줄 함수.

void draw_scene(Game* game); //실제 렌더링 함수.
