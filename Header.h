#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include <windows.h>
#include <time.h>

#define MAPSIZE 13 //�� ũ��
#define WALL 'X'
#define ROAD ' '

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define DEACTIVE 'p'
#define ACTIVE 'm'

#define REMOVED -1 // ���� �迭�� ������ �� �� ��.

typedef struct map
{
	char mapData[MAPSIZE][MAPSIZE];
} Map; // �� ����ü

typedef struct pacman
{
	int i, j; // ��ǥ��
	char direction; //�Է� ����
} Player; // �÷��̾� ����ü

typedef struct enemy
{
	int i, j; // ��ǥ��
	char direction; // ����
} Enemy; // �� ����ü

typedef struct coin
{
	int i, j; // ��ǥ��
} Coin; //���� ������ ����ü

typedef struct Game
{
	Map map; // ����
	Player pacman; // �÷��̾�
	unsigned int score; // ����
	Coin coins[MAPSIZE*MAPSIZE]; // ���� ������ (�ִ� ��ǥ 13*13 ���� �����ؾ� �ϱ� ������ �ִ� ũ��� ���� ������ ����)
	Enemy enemies[MAPSIZE*MAPSIZE]; // �� (�ִ� ��ǥ 13*13 ���� �����ؾ� �ϱ� ������ �ִ� ũ��� ���� ������ ����)
	unsigned int total_coins_number; // ���� ������ ����?
	unsigned short int life; //������ ��
	short int enemyMovement; //�� ������ ����
} Game; // Game Manager ����ü�� ������

// �浹 ó�� �Լ�
void check_coin_collision(Game* game, int y_position, int x_position);
void check_enemy_collision(Game* game, int y_position, int x_position);
// ���� ��ǥ�� ������Ʈ ���� �Լ�
int has_coin_in_position(Game *game, int x_position, int y_position);
int has_enemy_in_position(Game *game,int x_position, int y_position);
// ȭ�� ���� �Լ�
void rendering_pipeline(Game *game); //������ �ϴ� ������ �Ѱ��ϴ� �Լ�.

void init_scene(); //ȭ�� �ʱ�ȭ �Լ�.
void flip_scene(); //ȭ�� �ٲپ� �� �Լ�.
void clear_scene(); //ȭ���� ������ �Լ�.
void release_scene(); //���α׷� ���� �� ȭ���� �����ϴ� �Լ�.
void print_scene(int y_position, int x_position, char* print_data); //ȭ���� ����� �� �Լ�.
void set_color(unsigned short color); //������ ������ ������ �� �Լ�.

void draw_scene(Game* game); //���� ������ �Լ�.
