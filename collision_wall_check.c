///해당 함수는 팩맨/적이 움직이기 전에 예정된 위치가 벽인지 확인하는 기능을 합니다.
//그러므로 매개변수는 사전에 계산된 값이 사용됩니다.
int collision_wall_check(Game* g, int i, int j)
{
    //맵이 배열안에 사용되어있으므로, 배열의 범위를 넘어갈 경우 에러를 알려줍니다.
    if(i < 0 || i > CELL_SIZE-1 || j < 0 || j > CELL_SIZE-1)
        printf("OutOfArrayIndex error\n");
	return 0;

    //예정된 위치가 벽인 경우에는 1을 반환합니다.
    if(g->MAP.dados[i][j] == WALL)
        return 1;

    //예정된 위치는 이동할 수 있는 맵입니다.
    return 0;
}

