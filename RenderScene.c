// [Description]
// 렌더링 관련 함수 모음

#include "Header.h"

// 출력할 화면 순서를 정해줄 변수
static int screen_index;
// 화면을 출력 할 화면 버퍼 2개
static HANDLE screen_array[2];

// 화면 버퍼 생성 함수.
void InitScene()
{
    CONSOLE_CURSOR_INFO current_cursor_info;

    screen_array[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);
    screen_array[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);

    current_cursor_info.dwSize = 1;
    current_cursor_info.bVisible = FALSE;

    SetConsoleCursorInfo(screen_array[0], &current_cursor_info);
    SetConsoleCursorInfo(screen_array[1], &current_cursor_info);

    system("mode con cols=20 lines=20");
}

// 화면 버퍼를 교체해줄 함수.
void FlipScene()
{
    SetConsoleActiveScreenBuffer(screen_array[screen_index]);
    screen_index = !screen_index;
}

// 화면을 지우는 함수.
void ClearScene()
{
    COORD coordination = {0,0};
    DWORD dw;

    //실질적으로는 main 함수 내 clear 함수와 동일한 기능.
    // ' ' 을 80*25 (콘솔 창 크기) 만큼 채워내는 함수르 생각하면 됩니다.
    FillConsoleOutputCharacter(screen_array[screen_index], ' ', 13 * 15, coordination, &dw);
}

// 화면 버퍼를 해제(삭제하는) 함수.
void ReleaseScene()
{
    CloseHandle(screen_array[0]);
    CloseHandle(screen_array[1]);
}

// 배열에 담긴 값을 하나 하나 출력하는 함수.
void PrintScene(int x_position, int y_position, char *print_data)
{
    DWORD dw;
    COORD cursor_position = {x_position, y_position};

    SetConsoleCursorPosition(screen_array[screen_index], cursor_position);

    WriteFile(screen_array[screen_index], print_data,strlen(print_data), &dw, NULL);

}

void SetTextColors(unsigned short text_color, unsigned short background_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color| (background_color<<4));
}


void SetColor(unsigned short color)
{
	SetConsoleTextAttribute(screen_array[screen_index], color);
}
