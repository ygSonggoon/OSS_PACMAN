#include "pacman_header.h"

void init_game(Game* game_data)
{
    srand(time(NULL));

    //°ÔÀÓ ÃÊ±âÈ­žŠ À§ÇÑ º¯Œö Œ±Ÿð ºÎºÐÀÔŽÏŽÙ
    int ingame_coin_numbers = 0;
    int map_vertical = 0, map_horizontal = 0;
    int random_setting_value;
    char map_file_cell_value;

    //ÆÑžÇ À§Ä¡ žÊ ÁßŸÓÀž·Î ÃÊ±âÈ­ ÇÏŽÂ ºÎºÐÀÔŽÏŽÙ
    game_data->pacman.pacman_vertical = CELL_SIZE/2;
    game_data->pacman.pacman_horizontal = CELL_SIZE/2;
    game_data->pacman.direction = PAUSE;

    //±âÅž °ÔÀÓ º¯Œö ÃÊ±âÈ­ÀÔŽÏŽÙ
    game_data->score = 0;
    game_data->lifes = 3;
    game_data->enemies_movement = PAUSE;

    //¿ÜºÎ žÊ ÆÄÀÏÀ» ÀÐŸî¿À±â À§ÇÑ º¯Œö Œ±ŸðÀÔŽÏŽÙ
    FILE *map_file;
    map_file = fopen("mapa.txt", "r");

    //žÊ ÆÄÀÏÀ» ÀÐŸî¿ÀŽÂ ÇÔŒö ºÎºÐÀÔŽÏŽÙ, read_map.c ÆÄÀÏ·Î ºÐ·ù ÇÒ Œö ÀÖÀ» °Í °°œÀŽÏŽÙ
    if(map_file == NULL)
    {
        printf("°æ°í! žÊ ÆÄÀÏ ŸøÀœ!\n");
        exit(1);
    }
    else
    {
        while( (map_file_cell_value = fgetc(map_file))!= EOF )
        {
            if(map_file_cell_value != '\n')
            {
                //¿©±âŒ­ žÊ ÆÄÀÏÀ» ÀÐŸî¿Ã ¶§ žÊ¿¡ º®°ú ±æÀÌ Œ³Á€ÀÌ ¹Ìž® µËŽÏŽÙ
                game_data->map.MAP[map_vertical][map_horizontal] = map_file_cell_value;
                map_horizontal++;
            }
            else
            {
                map_horizontal = 0;
                map_vertical++;
            }
        }
        fclose(map_file);
    }

    //žÊ ÆÄÀÏ ÀÐŸî¿À°í ³­ ÈÄ ³ªžÓÁö Á€ºžµéÀ» žÊ¿¡ ÀÔ·ÂÇØÁÖŽÂ ¹Ýº¹¹® ºÎºÐÀÔŽÏŽÙ, ÀÌ°÷µµ map_setting.c ÆÄÀÏ·Î ºÐ·ù ÇÒ Œö ÀÖÀ» °Í °°œÀŽÏŽÙ
    for (map_vertical = 0; map_vertical < CELL_SIZE; map_vertical++)
    {
        for (map_horizontal = 0; map_horizontal < CELL_SIZE; map_horizontal++)
        {
            if ((game_data->pacman.pacman_vertical != map_vertical || game_data->pacman.pacman_horizontal != map_horizontal) && game_data->map.MAP[map_vertical][map_horizontal] != WALL)
            {
                game_data->map.MAP[map_vertical][map_horizontal] = BLANK;

                game_data->coins[ingame_coin_numbers].i = map_vertical;
                game_data->coins[ingame_coin_numbers].j = map_horizontal;
                ingame_coin_numbers++;
            }
        }
    }

    //ÄÚÀÎ°ú Àû ¹è¿­ ÃÊ°úµÈ ºÎºÐ ÃÊ±âÈ­ ÇÏŽÂ ºÎºÐÀÔŽÏŽÙ, ³¶ºñµÇŽÂ ºÎºÐÀÌ¹Ç·Î ÇØ°áÇØŸß ÇÕŽÏŽÙ
    for(int i = ingame_coin_numbers+1; i < CELL_SIZE*CELL_SIZE; i++)
    {
        game_data->coins[i].i = -1;
        game_data->coins[i].j = -1;
    }
    
    for(int i = 0; i < ENEMY_NUMBERS; i++)
    {
	switch (i)
	{
	case 0:
	    game_data->enemies[i].i = 1;
	    game_data->enemies[i].j = 1;
	    break;
	case 1:
	    game_data->enemies[i].i = CELL_SIZE - 1;
	    game_data->enemies[i].j = 1;
	    break;
	case 2:
	    game_data->enemies[i].i = 1;
	    game_data->enemies[i].j = CELL_SIZE - 1;
	    break;
	case 3:
	    game_data->enemies[i].i = CELL_SIZE - 1;
	    game_data->enemies[i].j = CELL_SIZE - 1;
	    break;
	default:
	    break;
	}
    }

    //ž¶Áöž·Àž·Î žÊ ³»ºÎ ÀüÃŒ µ¿Àü °¹ŒöžŠ °ÔÀÓ µ¥ÀÌÅÍ¿¡ ÀÔ·ÂÇØÁÝŽÏŽÙ
    game_data->total_coin_number = ingame_coin_numbers;
}

int has_coin_in_pos(Game* g, int i, int j)
{
    for(int k=0; k < CELL_SIZE*CELL_SIZE; k++)
    {
        if(g->coins[k].i == i && g->coins[k].j == j)
            return k;
    }
    return -1;
}

int has_enemy_in_pos(Game* g, int i, int j)
{
    for(int k=0; k < CELL_SIZE*CELL_SIZE; k++)
    {
        if(g->enemies[k].i == i && g->enemies[k].j == j)
            return k;
    }
    return -1;
}

void init_enemies(Game* g)
{
    g->enemies_movement = MOVE_STATUS;
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
        g->total_coin_number--;
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
        g->lifes--;
        g->pacman.pacman_vertical = CELL_SIZE/2;
        g->pacman.pacman_horizontal = CELL_SIZE/2;
        g->pacman.direction = PAUSE;
        g->enemies_movement = PAUSE;
    }
}

void draw_scene(Game* g)
{
    int k, l;
    for(int i=0; i< CELL_SIZE; i++)
    {
        for(int j=0; j < CELL_SIZE; j++)
        {
            k = has_coin_in_pos(g, i, j);
            l = has_enemy_in_pos(g, i, j);
            if(g->map.MAP[i][j] == WALL)
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
            else if(g->pacman.pacman_vertical == i && g->pacman.pacman_horizontal == j)
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
    if(i < 0 || i > CELL_SIZE-1 || j < 0 || j > CELL_SIZE-1)
        return 0;
    if(g->map.MAP[i][j] == WALL)
        return 1;
    return 0;
}

void move_enemies(Game* g)
{

    int rdm;
    if(g->enemies_movement != PAUSE)
    {
        for(int k=0; k < CELL_SIZE*CELL_SIZE; k++)
        {
            rdm = (rand()%3)-1;
            if(g->enemies[k].i >= 0)
            {
                if(!collision_wall_check(g, g->enemies[k].i + rdm, g->enemies[k].j)){
                    g->enemies[k].i += rdm;
                    if(g->enemies[k].i < 0)
                        g->enemies[k].i = CELL_SIZE-1;
                    if(g->enemies[k].i > CELL_SIZE-1)
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
                            g->enemies[k].j = CELL_SIZE-1;
                        if(g->enemies[k].j > CELL_SIZE-1)
                            g->enemies[k].j = 0;
                    }
                }
            }
        }
    }
}

void move_pacman(Game* g)
{
    if(g->pacman.direction == UP_MOVE && !collision_wall_check(g, g->pacman.pacman_vertical-1, g->pacman.pacman_horizontal))
    {
        g->pacman.pacman_vertical--;
        if(g->pacman.pacman_vertical < 0)
            g->pacman.pacman_vertical = CELL_SIZE-1;
    }
    else if(g->pacman.direction == DOWN_MOVE && !collision_wall_check(g, g->pacman.pacman_vertical+1, g->pacman.pacman_horizontal))
    {
        g->pacman.pacman_vertical++;
        if(g->pacman.pacman_vertical > CELL_SIZE-1)
            g->pacman.pacman_vertical = 0;
    }
    else if(g->pacman.direction == RIGHT_MOVE && !collision_wall_check(g, g->pacman.pacman_vertical, g->pacman.pacman_horizontal+1))
    {
        g->pacman.pacman_horizontal++;
        if(g->pacman.pacman_horizontal > CELL_SIZE-1)
            g->pacman.pacman_horizontal = 0;
    }
    else if(g->pacman.direction == LEFT_MOVE && !collision_wall_check(g, g->pacman.pacman_vertical, g->pacman.pacman_horizontal-1))
    {
        g->pacman.pacman_horizontal--;
        if(g->pacman.pacman_horizontal < 0)
            g->pacman.pacman_horizontal = CELL_SIZE-1;
    }
}

void change_direction(Game* g, char c)
{
    if(c == UP_MOVE)
        g->pacman.direction = UP_MOVE;
    else if(c == DOWN_MOVE)
        g->pacman.direction = DOWN_MOVE;
    else if(c == RIGHT_MOVE)
        g->pacman.direction = RIGHT_MOVE;
    else if(c == LEFT_MOVE)
        g->pacman.direction = LEFT_MOVE;
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
        collision_coin_check(&j, j.pacman.pacman_vertical, j.pacman.pacman_horizontal);
        collision_enemy_check(&j, j.pacman.pacman_vertical, j.pacman.pacman_horizontal);
        draw_scene(&j);
        move_enemies(&j);
        printf("Score: %d\nLifes: %d\n", j.score, j.lifes);
        if(j.total_coin_number == 0 || j.lifes == 0) jogando = 0;

    }

    printf("Game over.");

    return 0;
}
