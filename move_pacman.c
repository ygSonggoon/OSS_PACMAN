/*
팩맨이 움직이는 기능을 합니다. 사용자가 방향키를 입력한 경우 한칸 씩 움직이게 됩니다.
*/

#include "Header.h"

void move_pacman(Game* g)
{

    // 동서남북 4가지 방향으로 움직일 수 있습니다.
    switch(g->pacman.direction)
    {
        //북쪽 방향을 가리키는 경우 입니다.
        case UP_MOVE :

            //위쪽 방향이 벽인 경우 팩맨은 움직임을 진행하지 않습니다.
            if(!collision_wall_check(g, g->pacman_vertical - 1, g->pacman_horizontal)){
                g->pacman_vertical--;
                //한칸 씩 움직이게 할 계획이므로 상태를 멈추게 합니다.
                g->pacman.direction = PAUSE;

                //벽을 넘어간 경우 위치를 다시 설정해 줍니다.
                if(g->pacman_vertical < 0){
                    g->pacman_vertical = CELL_SIZE - 1;
                }
            }
            break;

        //위 내용과 동일한 과정을 지닙니다.
        case DOWN_MOVE:
            if(!collision_wall_check(g, g->pacman_vertical + 1, g->pacman_horizontal)){
                g->pacman_vertical++;
                g->pacman.direction = PAUSE;

                if(g->pacman_vertical > CELL_SIZE - 1){
                    g->pacman_vertical = 0;
                }
            }
            break;

        case RIGHT_MOVE:
            if(!collision_wall_check(g, g->pacman_vertical, g->pacman_horizontal + 1)){
                g->pacman_horizontal++;
                 g->pacman.direction = PAUSE;
                if(g->pacman_horizontal > CELL_SIZE - 1){
                    g->pacman_horizontal = 0;
                }
            }
            break;

        case LEFT_MOVE :
            if(!collision_wall_check(g, g->pacman_vertical, g->pacman_horizontal - 1)){
                g->pacman_horizontal--;
                g->pacman.direction = PAUSE;

                if(g->pacman_horizontal < 0){
                    g->pacman_horizontal = CELL_SIZE - 1;
                }
            }
            break;
    }
}
