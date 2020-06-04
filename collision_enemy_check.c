/*
init_enemies가 필요시에만 작동할수 있도록 하는 과정에서 포인터 매개변수가 추가되었습니다.
해당 변수가 1일 때에는 게임의 판이 진행중임을 의미하며 0일때에는 게임의 판이 종료된 것을 의미합니다.
해당 함수에서는 진행상태에서 종료상태로 변화할때를 구현하게 되었습니다. 
*/
void collision_enemy_check(Game* g, int i, int j, int* flag)
{
    int k;
    k = has_enemy_in_pos(g, i, j);
    if(k >= 0)
    {
        g->coins[k].i = -99;
        g->coins[k].j = -99;
        g->lifes--;

        //부딪힌 경우에는 팩맨을 다시 맵 정중앙으로 위치 시킨다.
        g->pacman.y_axis = CELL_SIZE/2;
        g->pacman.x_axis = CELL_SIZE/2;

        //부딪힌 경우에는 멈춤 상태로 다시 변한다.
        g->pacman.direction = PAUSE;
        g->enemies_movement = PAUSE;

        //진행상태에서 종료상태로 바꾸기 위한 포인터변수값 초기화.
        *flag = 0;
    }
}
