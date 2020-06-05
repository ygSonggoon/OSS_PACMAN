#include "Header.h"

//방향키 조정방법.
void change_direction(Game* g, char c)
{
    //swtich문을 사용해서 간단하게  정리.
    if(c == UP_MOVE)
        g->pacman.direction = UP_MOVE;
    else if(c == DOWN_MOVE)
        g->pacman.direction = DOWN_MOVE;
    else if(c == RIGHT_MOVE)
        g->pacman.direction = RIGHT_MOVE;
    else if(c == LEFT_MOVE)
        g->pacman.direction = LEFT_MOVE;
}

