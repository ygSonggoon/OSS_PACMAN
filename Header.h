#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include <windows.h>
#include <time.h>

#define MAPSIZE 13 
#define WALL 'X'
#define ROAD ' '

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define DEACTIVE 'p'
#define ACTIVE 'm'

#define REMOVED -1 

typedef struct map
{
	char mapData[MAPSIZE][MAPSIZE];
} Map; 

typedef struct pacman
{
	int i, j; 
	char direction; 
} Player; 

typedef struct enemy
{
	int i, j; 
	char direction;
} Enemy; 

typedef struct coin
{
	int i, j; 
} Coin; 

typedef struct Game
{
	Map map; 
	Player pacman; 
	unsigned int score; 
	Coin coins[MAPSIZE*MAPSIZE];
	Enemy enemies[MAPSIZE*MAPSIZE]; 
	unsigned int total_coins_number; 
	unsigned short int life; 
	short int enemyMovement; 
} Game; r 


void check_coin_collision(Game* game, int y_position, int x_position);
void check_enemy_collision(Game* game, int y_position, int x_position);

int has_coin_in_position(Game *game, int x_position, int y_position);
int has_enemy_in_position(Game *game,int x_position, int y_position);

void rendering_pipeline(Game *game);

void init_scene(); 
void flip_scene(); 
void clear_scene(); 
void release_scene(); 
void print_scene(int y_position, int x_position, char* print_data);
void set_color(unsigned short color);

void draw_scene(Game* game);

void init_game(Game* game);

int collision_wall_check(Game* g, int i, int j);
void move_enemies(Game* g);
void move_pacman(Game* g);
void change_direction(Game* g, char c);
