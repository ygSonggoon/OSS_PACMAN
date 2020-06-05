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

int has_coin_in_pos(Game* g, int i, int j);
int has_enemy_in_pos(Game* g, int i, int j);
void init_enemies(Game* g);
void collision_coin_check(Game* g, int i, int j);
void collision_enemy_check(Game* g, int i, int j);
void draw_scene(Game* g);
int collision_wall_check(Game* g, int i, int j);
void move_enemies(Game* g);
void move_pacman(Game* g);
void change_direction(Game* g, char c);

