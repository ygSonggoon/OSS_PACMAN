#include "Header.h"

//변수 스타일: 언더바 사용, 구조체 바꾸고[대문자 시작], 축약없이.
//함수 스타일: 대문자 동사시작 목적은 명사.

void InitGame(Game* game) // 게임 Initialize
{
    InitScene();

	srand((unsigned int)time(NULL));
	int total_enemies = 4; // 적 갯수
	int e = 0;
	int x = 0, y = 0;
	char ch;

	game->pacman.i = MAPSIZE / 2;
	game->pacman.j = MAPSIZE / 2;
	//플레이어 정 중앙에 생성
	game->pacman.direction = DEACTIVE;
	//플레이어 생성 후 움직임 X 인 상태로 세팅

	//맵 데이터 파일 읽어오기
	FILE *archive;
	archive = fopen("map.txt", "r");

	//맵 데이터 txt 파일이 없을 때
	if (archive == NULL)
	{
		printf("ERROR! PLEASE CHECK MAP DATAFILE\n");
		exit(1);
	}
	else
	{
		while ((ch = fgetc(archive)) != EOF)
		{
			if (ch != '\n')
			{
				game->map.mapData[x][y] = ch;
				y++;
			}
			else
			{
				y = 0;
				x++;
			}
		}
		fclose(archive);
	}

	int rdm, e2 = 0;
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if ((game->pacman.i != i || game->pacman.j != j) && game->map.mapData[i][j] != WALL)
			{
				game->map.mapData[i][j] = ROAD;
				game->coins[e].i = i;
				game->coins[e].j = j;
				e++;
			}
			if ((rdm = rand() % 15) < 1 && ((game->pacman.i != i || game->pacman.j != j) && game->map.mapData[i][j] != WALL) && e2 < total_enemies)
			{
				game->map.mapData[i][j] = ROAD;
				game->enemies[e2].i = i;
				game->enemies[e2].j = j;
				e2++;
			}
		}
	}

	//inicializa entidades
	for (int i = e + 1; i < MAPSIZE*MAPSIZE; i++)
	{
		game->coins[i].i = -1;
		game->coins[i].j = -1;
	}
	for (int i = e2 + 1; i < MAPSIZE*MAPSIZE; i++)
	{
		game->enemies[i].i = -1;
		game->enemies[i].j = -1;
		game->enemies[i].direction = DEACTIVE;
	}
	//inicializa score
	game->score = 0;
	game->total_coins_number = e;
	game->life = 3;
	game->enemyMovement = DEACTIVE;
}

void InitEnemy(Game *game)
{
    game->enemyMovement = ACTIVE;
}

int CollisionWallCheck(Game* game, int i, int j)
{
	if (i < 0 || i > MAPSIZE - 1 || j < 0 || j > MAPSIZE - 1)
		return 0;
	if (game->map.mapData[i][j] == WALL)
		return 1;
	return 0;
}

void MoveEnemy(Game* game)
{
	int rdm;
	if (game->enemyMovement != DEACTIVE)
	{
		for (int k = 0; k < MAPSIZE*MAPSIZE; k++)
		{
			rdm = (rand() % 3) - 1;
			if (game->enemies[k].i >= 0)
			{
				if (!CollisionWallCheck(game, game->enemies[k].i + rdm, game->enemies[k].j))
				{
					game->enemies[k].i += rdm;
					if (game->enemies[k].i < 0)
						game->enemies[k].i = MAPSIZE - 1;
					if (game->enemies[k].i > MAPSIZE - 1)
						game->enemies[k].i = 0;
				}
			}

			if (rdm == 0)
			{
				rdm = (rand() % 3) - 1;
				if (game->enemies[k].j >= 0)
				{
					if (!CollisionWallCheck(game, game->enemies[k].i, game->enemies[k].j + rdm))
					{
						game->enemies[k].j += rdm;
						if (game->enemies[k].j < 0)
							game->enemies[k].j = MAPSIZE - 1;
						if (game->enemies[k].j > MAPSIZE - 1)
							game->enemies[k].j = 0;
					}
				}
			}
		}
	}
}

void MovePacman(Game* game)
{
	if (game->pacman.direction == UP && !CollisionWallCheck(game, game->pacman.i - 1, game->pacman.j))
	{
		game->pacman.i--;
		if (game->pacman.i < 0)
			game->pacman.i = MAPSIZE - 1;
	}
	else if (game->pacman.direction == DOWN && !CollisionWallCheck(game, game->pacman.i + 1, game->pacman.j))
	{
		game->pacman.i++;
		if (game->pacman.i > MAPSIZE - 1)
			game->pacman.i = 0;
	}
	else if (game->pacman.direction == RIGHT && !CollisionWallCheck(game, game->pacman.i, game->pacman.j + 1))
	{
		game->pacman.j++;
		if (game->pacman.j > MAPSIZE - 1)
			game->pacman.j = 0;
	}
	else if (game->pacman.direction == LEFT && !CollisionWallCheck(game, game->pacman.i, game->pacman.j - 1))
	{
		game->pacman.j--;
		if (game->pacman.j < 0)
			game->pacman.j = MAPSIZE - 1;
	}
}

void ChangeDirection(Game* game, char c)
{
	if (c == UP)
		game->pacman.direction = UP;
	else if (c == DOWN)
		game->pacman.direction = DOWN;
	else if (c == RIGHT)
		game->pacman.direction = RIGHT;
	else if (c == LEFT)
		game->pacman.direction = LEFT;
}

int main()
{
	Game game;
	InitGame(&game);

	int running = 1;
	char c = 'v';

	while (running)
	{
        delay(150);
		if (kbhit())
		{
			c = getch();
			ChangeDirection(&game, c);
			InitEnemy(&game);
		}
		MovePacman(&game);
		CheckCoinCollision(&game, game.pacman.i, game.pacman.j);
		CheckEnemyCollision(&game, game.pacman.i, game.pacman.j);

        RenderingPipeline(&game);

		MoveEnemy(&game);



		if (game.total_coins_number == 0 || game.life == 0)
			running = 0;
	}

	printf("Game over.");

	ReleaseScene();

	return 0;
}
