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

    char *player_graphic;
    int player_graphic_length;
} Player; // �÷��̾� ����ü

typedef struct enemy
{
	int i, j; // ��ǥ��
	char direction; // ����

    char *enemy_graphic;
    int enemy_graphic_length;
} Enemy; // �� ����ü

typedef struct coin
{
	int i, j; // ��ǥ��

	char *coin_graphic;
	int coin_graphic_length;
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
void CheckCoinCollision(Game* game, int y_position, int x_position);
void CheckEnemyCollision(Game* game, int y_position, int x_position);
// ���� ��ǥ�� ������Ʈ ���� �Լ�
int HasCoinInPosition(Game *game, int x_position, int y_position);
int HasEnemyInPosition(Game *game,int x_position, int y_position);
// ȭ�� ���� �Լ�
void RenderingPipeline(Game *game); //������ �ϴ� ������ �Ѱ��ϴ� �Լ�.

void InitScene(); //ȭ�� �ʱ�ȭ �Լ�.
void FlipScene(); //ȭ�� �ٲپ� �� �Լ�.
void ClearScene(); //ȭ���� ������ �Լ�.
void ReleaseScene(); //���α׷� ���� �� ȭ���� �����ϴ� �Լ�.
void PrintScene(int y_position, int x_position, char* print_data);
void SetColor(unsigned short color);
void SetTextColors(unsigned short text_color, unsigned short background_color);

void DrawScene(Game* game); //���� ������ �Լ�.
