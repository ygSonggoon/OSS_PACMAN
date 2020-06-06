/*
init_enemies�Լ��� �ݺ�ȣ��Ǵ� ���� �������� ��ġ�� ���߽��ϴ�.
flag ������ 0�� ��쿡�� ������ ���۵��� ���� ���¸� ��Ÿ����,
flag ������ 1�� ��쿡�� ������ ���۵� ���¸� ��Ÿ���ϴ�.
�׷��⿡ 0->1�� �ٲ�� ��쿡�� init_enemies�� ȣ��ǰ� �˴ϴ�.
������ �����帰 ��� 1->0���� �ٲ� �κ�(���� ���¿��� ������·��� ����)�� ���ؼ�,
ȿ����� ������ collision_enemy_check�� �Ű������� ������ ����[flag]�� �ϳ� �߰��߽��ϴ�.
�̿ܿ��� ���� ������ �����Դϴ�.
*/


#include "Header.h"

int main()
{
    Game j;
    int jogando = 1;
    char c = 'v';
    int flag = 0;

    init_game(&j);

    while (jogando)
    {
        //������ �ð� ����.
        delay(150);
        clrscr();
        if (kbhit())
        {
            //���۰� �Է�.
            c = getch();

            //init_enemies�� �ʿ�ÿ��� ȣ��Ǳ� ���� ��ġ.
            if (c != 'v' && flag == 0) {
                init_enemies(&j);
                flag = 1;
            }
            change_direction(&j, c);
        }

        //�Ѹ� ������.

        move_pacman(&j);
        //������ ���ؼ� �Ѹ��� 1.5�ʰ� �������� �������� �Ǵ°�?
        //���� �� �ѹ��� �����̴µ�...

        //������ �� ���� Ȯ��
        collision_coin_check(&j, j.pacman.y_axis, j.pacman.x_axis);
        //������¿��� ������·� �ٲٱ����� �Ű������� �ϳ��� �߰��� collision_enemy_check.
        collision_enemy_check(&j, j.pacman.y_axis, j.pacman.x_axis, &flag);

        //������ �� ���� ��ȭ
        draw_scene(&j);
        move_enemies(&j);
        printf("Score: %d\nLifes: %d\n", j.score, j.lifes);

        //���� ����.
        if (j.total_coin_number == 0 || j.lifes == 0) jogando = 0;

    }

    printf("Game over.");

    return 0;
}