#include "header.h"

void move_enemies(Game* g)
{

    int rdm;

 C   //PAUSE인 경우는 2가지, 게임이 시작하지 않는 경우와, 플레이어와 부딪>힌 경우
    if(g->enemies_movement != PAUSE)
    {
        for(int k=0; k < CELL_SIZE*CELL_SIZE; k++)
        {
            //한칸씩 움직이게 설정
            //x축과 y축 움직이는 설정내용인데, 구체적으로 실현했으면 좋겠>음.

            //-1, 0, 1이 발생함.
            rdm = (rand() % 3) - 1;



            //적이 존재하는 x축 위에 있다면,
            if(g->enemies[k].i >= 0)
            {
                //현재 위치에 + rdm(-1,0,1)값이 벽이 아니라면.
                if(!collision_wall_check(g, g->enemies[k].i + rdm, g->enemies[k].j)){
                    //해당 적의 x좌표 위치 변경.
                    g->enemies[k].i += rdm;

                    //다른 공간으로 넘어갈수 있게 설정.맵에서 뚫린 공간
                    if(g->enemies[k].i < 0)
                        g->enemies[k].i = CELL_SIZE-1;
                    if(g->enemies[k].i > CELL_SIZE-1)
                        g->enemies[k].i = 0;
                }
            }



            //랜덤값이 0이어야, y축이 움직임.
            if(rdm == 0)
            {
                //rdm은 -1,0,1이 발생이 가능함.
		rdm = (rand()%3)-1;

                //사실상 enemies[k].i가 존재 한다면 .j도 존재하므로, 해당 조건은 중복된 내용임.
                if(g->enemies[k].j >= 0)
                {
                    //벽인지 확인하기.
                    if(!collision_wall_check(g, g->enemies[k].i, g->enemies[k].j + rdm)){

                        g->enemies[k].j += rdm;

                        //구멍이 뚫린 곳을 통해 다른 곳으로 이동.
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

	











