/*
 * move_enemies, 즉 적이 움직이는 기능을 하는 함수 입니다.
 * 적은 X축으로 움직일 확률 2/3, Y축으로 움직일 확률 2/9, 제자리에 있을 확률 1/9를
 * 랜덤값을 이용해서 해당 확률을 구분시켜 주었습니다.
 **/

#include "Header.h"

void move_enemies(Game* g)
{

    int rdm;

    //PAUSE인 경우는 2가지, 게임이 시작하지 않는 경우와, 플레이어와 부딪힌 경우
    if(g->enemies_movement != PAUSE)
    {
        for(int k=0; k < CELL_SIZE*CELL_SIZE; k++)
        {

            //적이 존재한다면 적을 움직이게 합니다.
            if(g->enemies[k].i >= 0 && g->enemies[k].j >= 0)
            {
                 rdm = (rand() % 9);

                //적을 오른쪽으로 움직이게 합니다.
                 if(rdm <= 2)
                 {
                    if(!collision_wall_check(g, g->enemies[k].i+1, g->enemies[k].j))
                    {
                        g->enemies[k].i++;

                        if(g->enemies[k].i > CELL_SIZE - 1){
                            g->enemies[k].i = 0;
                        }
                    }
                 }

                //적을 왼쪽으로 움직이게 합니다.
                 else if(rdm <= 5 && rdm > 2)
                 {
                    if(!collision_wall_check(g, g->enemies[k].i-1, g->enemies[k].j))
                    {
                        g->enemies[k].i--;

                        if(g->enemies[k].i < 0){
                            g->enemies[k].i = CELL_SIZE - 1;
                        }
                    }
                 }

                //적을 위쪽으로 움직이게 합니다.
                 else if(rdm <= 6 && rdm > 5)
                 {
                    if(!collision_wall_check(g, g->enemies[k].i, g->enemies[k].j+1))
                    {
                        g->enemies[k].j++;

                        if(g->enemies[k].j > CELL_SIZE - 1){
                            g->enemies[k].j = 0;
                        }
                    }

                 }

                //적을 아래쪽으로 움직이게 합니다.
                 else if(rdm <= 7 && rdm > 6)
                 {
                    if(!collision_wall_check(g, g->enemies[k].i, g->enemies[k].j-1))
                    {
                        g->enemies[k].j--;

                        if(g->enemies[k].j < 0){
                            g->enemies[k].j = CELL_SIZE - 1;
                        }
                    }
                 }
            }
        }
    }
}
