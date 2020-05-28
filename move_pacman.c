#include "header.h"

void move_pacman(Game* g)
{

    //w키 조정시.
    if(g->pacman.direction == UP_MOVE && !collision_wall_check(g, g->pacman.i-1, g->pacman.j))
    {
        g->pacman.i--;
        //벽의 뚫린 부분으로 넘어감. 이하 내용 동일.
        if(g->pacman.i < 0)
            g->pacman.i = CELL_SIZE-1;
    }

    //s키 조정시
    else if(g->pacman.direction == DOWN_MOVE && !collision_wall_check(g, g->pacman.i+1, g->pacman.j))
    {
        g->pacman.i++;
        if(g->pacman.i > CELL_SIZE-1)
            g->pacman.i = 0;
    }

    //d키 조정시
    else if(g->pacman.direction == RIGHT_MOVE && !collision_wall_check(g, g->pacman.i, g->pacman.j+1))
    {
        g->pacman.j++;
        if(g->pacman.j > CELL_SIZE-1)
            g->pacman.j = 0;
    }

    //a키 조정시
    else if(g->pacman.direction == LEFT_MOVE && !collision_wall_check(g, g->pacman.i, g->pacman.j-1))
    {
        g->pacman.j--;
        if(g->pacman.j < 0)
            g->pacman.j = CELL_SIZE-1;
    }
}



