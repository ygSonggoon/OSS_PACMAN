//팩맨 움직임.
void move_pacman(Game* g)
{
    //switch문을 사용해서 더 간결히 정리하고 싶음.
    //w키 조정시.
    if(g->pacman.direction == UP_MOVE && !collision_wall_check(g, g->pacman.i-1, g->pacman.j))
    {
        g->pacman.i--;
        //벽의 뚫린 부분으로 넘어감. 이하 내용 동일.
C        if(g->pacman.i < 0)
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

    //a 조정시
    else if(g->pacman.direction == LEFT_MOVE && !collision_wall_check(g, g->pacman.i, g->pacman.j-1))
    {
        g->pacman.j--;
        if(g->pacman.j < 0)
            g->pacman.j = CELL_SIZE-1;
    }
}


