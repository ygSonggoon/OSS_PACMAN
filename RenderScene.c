// [Description]
// ������ ���� �Լ� ����

#include "Header.h"

// ����� ȭ�� ������ ������ ����
static int screen_index;
// ȭ���� ��� �� ȭ�� ���� 2��
static HANDLE screen_array[2];

// ȭ�� ���� ���� �Լ�.
void init_scene()
{
    CONSOLE_CURSOR_INFO current_cursor_info; // ���� �ܼ�â�� Ŀ�� ("_") ������ ���� ����.


    //�ܼ� ȭ�� ���� â�� ������ ������.
    screen_array[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);
    screen_array[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);

    //�ܼ�â�� Ŀ���� ������ �ʰ� ����.
    current_cursor_info.dwSize = 1;
    current_cursor_info.bVisible = FALSE;

    //�ܼ�â Ŀ�� �ɼ��� �� ���ۿ� ������.
    SetConsoleCursorInfo(screen_array[0], &current_cursor_info);
    SetConsoleCursorInfo(screen_array[1], &current_cursor_info);
}

// ȭ�� ���۸� ��ü���� �Լ�.
void flip_scene()
{
    SetConsoleActiveScreenBuffer(screen_array[screen_index]);

    //Flag �������� ȭ���� ����ؼ� �ٲ�.
    screen_index = !screen_index;
}

// ȭ���� ����� �Լ�.
void clear_scene()
{
    //0,0 ��ǥ�� �����Ͽ� 0,0 ��ǥ���� �����ϰ� ����.
    COORD coordination = {0,0};
    DWORD dw;

    //���������δ� main �Լ� �� clear �Լ��� ������ ���.
    // ' ' �� 80*25 (�ܼ� â ũ��) ��ŭ ä������ �Լ��� �����ϸ� �˴ϴ�.
    FillConsoleOutputCharacter(screen_array[screen_index], ' ', 13 * 15, coordination, &dw);
}

// ȭ�� ���۸� ����(�����ϴ�) �Լ�.
void release_scene()
{
    CloseHandle(screen_array[0]);
    CloseHandle(screen_array[1]);
}

// �迭�� ��� ���� �ϳ� �ϳ� ����ϴ� �Լ�.
void print_scene(int x_position, int y_position, char *print_data)
{
    DWORD dw;

    COORD cursor_position = {x_position, y_position}; //����� ������ ��ǥ���� ����.

    SetConsoleCursorPosition(screen_array[screen_index], cursor_position); //����� ������ ��ǥ���� ��ġ�ϰ� �̵�.

    WriteFile(screen_array[screen_index], print_data,strlen(print_data), &dw, NULL); //���ۿ� ��� ���ڿ��� ����.

}

// ������ ������ �����ϴ� �Լ�.
void set_color(unsigned short color)
{
	SetConsoleTextAttribute(screen_array[screen_index], color);
}
