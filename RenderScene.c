// [Description]
// ������ ���� �Լ� ����

#include "Header.h"

// ����� ȭ�� ������ ������ ����
static int screen_index;
// ȭ���� ��� �� ȭ�� ���� 2��
static HANDLE screen_array[2];

// ȭ�� ���� ���� �Լ�.
void InitScene()
{
    CONSOLE_CURSOR_INFO current_cursor_info;

    screen_array[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);
    screen_array[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);

    current_cursor_info.dwSize = 1;
    current_cursor_info.bVisible = FALSE;

    SetConsoleCursorInfo(screen_array[0], &current_cursor_info);
    SetConsoleCursorInfo(screen_array[1], &current_cursor_info);
}

// ȭ�� ���۸� ��ü���� �Լ�.
void FlipScene()
{
    SetConsoleActiveScreenBuffer(screen_array[screen_index]);
    screen_index = !screen_index;
}

// ȭ���� ����� �Լ�.
void ClearScene()
{
    COORD coordination = {0,0};
    DWORD dw;

    //���������δ� main �Լ� �� clear �Լ��� ������ ���.
    // ' ' �� 80*25 (�ܼ� â ũ��) ��ŭ ä������ �Լ��� �����ϸ� �˴ϴ�.
    FillConsoleOutputAttribute(screen_array[screen_index], ' ', 80*25, coordination, &dw);
}

// ȭ�� ���۸� ����(�����ϴ�) �Լ�.
void ReleaseScene()
{
    CloseHandle(screen_array[0]);
    CloseHandle(screen_array[1]);
}

// �迭�� ��� ���� �ϳ� �ϳ� ����ϴ� �Լ�.
void PrintScene(int y_position, int x_position, char* print_data)
{
    DWORD dw;
    COORD cursor_position = {y_position, x_position};

    SetConsoleCursorPosition(screen_array[screen_index], cursor_position);
    WriteFile(screen_array[screen_index], print_data, strlen(print_data)+1, &dw, NULL);
}
