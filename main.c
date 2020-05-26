#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>

#define MAPSIZE 13
#define WALL 'X'
#define ROAD ' '
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define PAUSE 'p'
#define MOVEMENT 'm'
#define enemyNummberSet 4

typedef struct map
{
    char mapData[MAPSIZE][MAPSIZE];
} Mapa;

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

typedef struct game
{
    Mapa map;
    Player pacman;
    unsigned int score;
    Coin coins[MAPSIZE*MAPSIZE];
    Enemy enemies[MAPSIZE*MAPSIZE];
    unsigned int totalCoinNummber;
    unsigned short int life;
    short int enemyMovement;
} Game;

void init_game(Game* gamedata)
{
    srand(time(NULL));

    int ingameCoinNummber = 0;
    int mapLength = 0, mapBreadth=0;
    int enemySetRndValue, ingameEnemyNummber = 0;
    char readMapTxtChar;

    gamedata->score = -10;
    gamedata->life = 3;

    gamedata->pacman.i = MAPSIZE/2;
    gamedata->pacman.j = MAPSIZE/2;
    gamedata->pacman.direction = PAUSE;
    
    FILE *MapFile;
    MapFile = fopen("mapa.txt", "r");

    if(MapFile == NULL)
    {
        printf("경고: 맵 텍스트 파일이 없습니다!(mapa.txt)\n");
        exit(1);
    }
    else
    {
        while( (readMapTxtChar = fgetc(MapFile))!= EOF)
        {
            if(readMapTxtChar != '\n')
            {
                gamedata->map.mapData[mapBreadth][mapLength] = readMapTxtChar;
                mapLength++;
            }
            else
            {
                mapLength=0;
                mapBreadth++;
            }
        }
        fclose(MapFile);
    }

    for(mapBreadth =0; mapBreadth < MAPSIZE; mapBreadth++)
    {
        for(mapLength =0; mapLength < MAPSIZE; mapLength++)
        {
            if((gamedata->pacman.i != i || gamedata->pacman.j != j) && gamedata->map.mapData[i][j] != WALL)
            {
                gamedata->map.mapData[i][j] = ROAD;
                gamedata->coins[ingameCoinNummber].i = i;
                gamedata->coins[ingameCoinNummber].j = j;
                ingameCoinNummber++;
            }
            if((enemySetRndValue = rand()%15) < 1 && ((gamedata->pacman.i != i || gamedata->pacman.j != j) && gamedata->map.mapData[i][j] != WALL) && ingameEnemyNummber < total_enemies)
            {
                gamedata->map.mapData[i][j] = ROAD;
                gamedata->enemies[ingameEnemyNummber].i = i;
                gamedata->enemies[ingameEnemyNummber].j = j;
                ingameEnemyNummber++;
            }
        }
    }

    for(int i = ingameCoinNummber+1; i < MAPSIZE*MAPSIZE; i++)
    {
        gamedata->coins[i].i = -1;
        gamedata->coins[i].j = -1;
    }
    for(int i = ingameEnemyNummber+1; i < MAPSIZE*MAPSIZE; i++)
    {
        gamedata->enemies[i].i = -1;
        gamedata->enemies[i].j = -1;
        gamedata->enemies[i].direction = PAUSE;
    }
    
    
    gamedata->totalCoinNummber = ingameCoinNummber;
    gamedata->enemyMovement = PAUSE;
}

int has_coin_in_pos(Game* g, int i, int j)
{
    for(int k=0; k < MAPSIZE*MAPSIZE; k++)
    {
        if(g->coins[k].i == i && g->coins[k].j == j)
            return k;
    }
    return -1;
}

int has_enemy_in_pos(Game* g, int i, int j)
{
    for(int k=0; k < MAPSIZE*MAPSIZE; k++)
    {
        if(g->enemies[k].i == i && g->enemies[k].j == j)
            return k;
    }
    return -1;
}

void init_enemies(Game* g)
{
    g->enemyMovement = MOVEMENT;
}

void collision_coin_check(Game* g, int i, int j)
{
    int k;
    k = has_coin_in_pos(g, i, j);
    if(k >= 0)
    {
        g->coins[k].i = -1;
        g->coins[k].j = -1;
        g->score += 10;
        g->totalCoinNummber--;
    }
}

void collision_enemy_check(Game* g, int i, int j)
{
    int k;
    k = has_enemy_in_pos(g, i, j);
    if(k >= 0)
    {
        g->coins[k].i = -99;
        g->coins[k].j = -99;
        g->life--;
        g->pacman.i = MAPSIZE/2;
        g->pacman.j = MAPSIZE/2;
        g->pacman.direction = PAUSE;
        g->enemyMovement = PAUSE;
    }
}

void draw_scene(Game* g)
{
    int k, l;
    for(int i=0; i< MAPSIZE; i++)
    {
        for(int j=0; j < MAPSIZE; j++)
        {
            k = has_coin_in_pos(g, i, j);
            l = has_enemy_in_pos(g, i, j);
            if(g->map.mapData[i][j] == WALL)
            {
                textbackground(RED);
                printf("  ");
                textbackground(BLACK);
            }
            else if(l >= 0)
            {
                textbackground(BLACK);
                textcolor(LIGHTBLUE);
                printf("o ");
                textcolor(WHITE);
                textbackground(BLACK);
            }
            else if(k >= 0)
            {
                textbackground(BLACK);
                textcolor(YELLOW);
                printf(". ");
                textcolor(WHITE);
                textbackground(BLACK);
            }
            else if(g->pacman.i == i && g->pacman.j == j)
            {
                textbackground(BLACK);
                textcolor(WHITE);
                printf("o ");
                textcolor(WHITE);
                textbackground(BLACK);
            }
            else
            {
                textbackground(BLACK);
                textcolor(WHITE);
                printf("  ");
                textcolor(WHITE);
                textbackground(BLACK);
            }
        }
        printf("\n");
    }
}

int collision_wall_check(Game* g, int i, int j)
{
    if(i < 0 || i > MAPSIZE-1 || j < 0 || j > MAPSIZE-1)
        return 0;
    if(g->map.mapData[i][j] == WALL)
        return 1;
    return 0;
}

void move_enemies(Game* g)
{

    int rdm;
    if(g->enemyMovement != PAUSE)
    {
        for(int k=0; k < MAPSIZE*MAPSIZE; k++)
        {
            rdm = (rand()%3)-1;
            if(g->enemies[k].i >= 0)
            {
                if(!collision_wall_check(g, g->enemies[k].i + rdm, g->enemies[k].j)){
                    g->enemies[k].i += rdm;
                    if(g->enemies[k].i < 0)
                        g->enemies[k].i = MAPSIZE-1;
                    if(g->enemies[k].i > MAPSIZE-1)
                        g->enemies[k].i = 0;
                }
            }

            if(rdm == 0)
            {
                rdm = (rand()%3)-1;
                if(g->enemies[k].j >= 0)
                {
                    if(!collision_wall_check(g, g->enemies[k].i, g->enemies[k].j + rdm)){
                        g->enemies[k].j += rdm;
                        if(g->enemies[k].j < 0)
                            g->enemies[k].j = MAPSIZE-1;
                        if(g->enemies[k].j > MAPSIZE-1)
                            g->enemies[k].j = 0;
                    }
                }
            }
        }
    }
}

void move_pacman(Game* g)
{
    if(g->pacman.direction == UP && !collision_wall_check(g, g->pacman.i-1, g->pacman.j))
    {
        g->pacman.i--;
        if(g->pacman.i < 0)
            g->pacman.i = MAPSIZE-1;
    }
    else if(g->pacman.direction == DOWN && !collision_wall_check(g, g->pacman.i+1, g->pacman.j))
    {
        g->pacman.i++;
        if(g->pacman.i > MAPSIZE-1)
            g->pacman.i = 0;
    }
    else if(g->pacman.direction == RIGHT && !collision_wall_check(g, g->pacman.i, g->pacman.j+1))
    {
        g->pacman.j++;
        if(g->pacman.j > MAPSIZE-1)
            g->pacman.j = 0;
    }
    else if(g->pacman.direction == LEFT && !collision_wall_check(g, g->pacman.i, g->pacman.j-1))
    {
        g->pacman.j--;
        if(g->pacman.j < 0)
            g->pacman.j = MAPSIZE-1;
    }
}

void change_direction(Game* g, char c)
{
    if(c == UP)
        g->pacman.direction = UP;
    else if(c == DOWN)
        g->pacman.direction = DOWN;
    else if(c == RIGHT)
        g->pacman.direction = RIGHT;
    else if(c == LEFT)
        g->pacman.direction = LEFT;
}

int main()
{
    Game j;
    init_game(&j);
    int jogando = 1;
    char c = 'v';

    while(jogando)
    {
        delay(150);
        clrscr();
        if(kbhit())
        {
            c = getch();
            change_direction(&j, c);
            init_enemies(&j);
        }
        move_pacman(&j);
        collision_coin_check(&j, j.pacman.i, j.pacman.j);
        collision_enemy_check(&j, j.pacman.i, j.pacman.j);
        draw_scene(&j);
        move_enemies(&j);
        printf("Score: %d\nLifes: %d\n", j.score, j.life);
        if(j.totalCoinNummber == 0 || j.life == 0) jogando = 0;

    }

    printf("Game over.");

    return 0;
}
