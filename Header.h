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


void CheckCoinCollision(Game* game, int y_position, int x_position);
void CheckEnemyCollision(Game* game, int y_position, int x_position);



int HasCoinInPosition(Game *game, int x_position, int y_position);
int HasEnemyInPosition(Game *game,int x_position, int y_position);

void DrawScene(Game* game);
