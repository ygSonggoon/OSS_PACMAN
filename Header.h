#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include <windows.h>
#include <time.h>

#define CELL_SIZE 13
#define WALL 'X'
#define BLANK ' '
#define UP_MOVE 'w'
#define DOWN_MOVE 's'
#define LEFT_MOVE 'a'
#define RIGHT_MOVE 'd'
#define PAUSE 'p'
#define MOVE_STATUS 'm'
#define ENEMY_NUMBERS 4
#define REMOVED -1

typedef struct Map
{
    char MAP[CELL_SIZE][CELL_SIZE];
} Map;

typedef struct Pacman
{
    int pacman_vertical, pacman_horizontal;
    char direction;
} Pacman;

typedef struct Enemy
{
    int i, j;
    char direction;
} Enemy;

typedef struct Coin
{
    int i, j;
} Coin;

typedef struct Game
{
    Map map;
    Pacman pacman;
    Coin coins[CELL_SIZE*CELL_SIZE];
    Enemy enemies[CELL_SIZE*CELL_SIZE];

    unsigned int score;
    unsigned int total_coin_number;
    unsigned short int lifes;
    short int enemies_movement;
} Game;

void init_game(Game* g);
int has_coin_in_position(Game *g, int x_position, int y_position);
int has_enemy_in_position(Game* g, int x_position, int y_position);
void init_enemies(Game* g);
void collision_coin_check(Game* g, int y_position, int x_position);
void collision_enemy_check(Game* g, int y_position, int x_position, int* flag);
int collision_wall_check(Game* g, int i, int j);
void move_enemies(Game* g);
void move_pacman(Game* g);
void change_direction(Game* g, char c);

// 추가된 항목
void renderling_pipeline(Game *g); //렌더링 하는 과정을 총괄하는 함수.

void init_scene(); //화면 초기화 함수.
void flip_scene(); //화면 바꾸어 줄 함수.
void clear_scene(); //화면을 지워줄 함수.
void release_scene(); //프로그램 종료 시 화면을 삭제하는 함수.
void print_scene(int y_position, int x_position, char* print_data); //화면을 출력해 줄 함수.
void set_color(unsigned short color); //문자의 색상을 지정해 줄 함수.

void draw_scene(Game* g); //실제 렌더링 함수.

