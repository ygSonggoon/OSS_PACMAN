/*
init_enemies함수가 반복호출되는 것을 막기위한 조치를 취했습니다.
flag 변수가 0인 경우에는 게임이 시작되지 않은 상태를 나타내고,
flag 변수가 1인 경우에는 게임이 시작된 상태를 나타냅니다.
그렇기에 0->1로 바뀌는 경우에만 init_enemies가 호출되게 됩니다.

사전에 말씀드린 대로 1->0으로 바뀐 부분(진행 상태에서 종료상태로의 진행)을 위해서,
효재님이 맡으신 collision_enemy_check의 매개변수에 포인터 변수[flag]를 하나 추가했습니다.
이외에는 전부 동일한 내용입니다.
*/


#include "Header.h"

int main()
{
    Game j;
    int jogando = 1;
    char c = 'v';
    int flag = 0;

    init_game(&j);

    while(jogando)
    {
        //딜레이 시간 설정.
        delay(150);
        clrscr();
        if(kbhit())
        {
            //버퍼값 입력.
            c = getch();

            //init_enemies가 필요시에만 호출되기 위한 장치.
            if(c != 'v' && flag == 0){
              init_enemies(&j);
              flag = 1;
            }
            change_direction(&j, c);
        }

        //팩맨 움직임.

        move_pacman(&j);
        //형평성을 위해서 팩맨은 1.5초간 연속으로 움직여도 되는가?
        //적은 딱 한번만 움직이는데...

        //움직임 후 상태 확인
        collision_coin_check(&j, j.pacman.y_axis, j.pacman.x_axis);
        //진행상태에서 종료상태로 바꾸기위해 매개변수가 하나더 추가된 collision_enemy_check.
        collision_enemy_check(&j, j.pacman.y_axis, j.pacman.x_axis, &flag);

        //움직임 후 상태 변화
        draw_scene(&j);
        move_enemies(&j);
        printf("Score: %d\nLifes: %d\n", j.score, j.lifes);

        //종료 조건.
        if(j.total_coin_number == 0 || j.lifes == 0) jogando = 0;

    }

    printf("Game over.");

    return 0;
}
