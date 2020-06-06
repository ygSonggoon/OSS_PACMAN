// [Description]
// 렌더링 관련 함수 모음

#include "Header.h"

// 출력할 화면 순서를 정해줄 변수
static int screen_index;
// 화면을 출력 할 화면 버퍼 2개
static HANDLE screen_array[2];

// 화면 버퍼 생성 함수.
void init_scene()
{
    CONSOLE_CURSOR_INFO current_cursor_info; // 현재 콘솔창의 커서 ("_") 정보를 받을 변수.


    //콘솔 화면 버퍼 창을 생성할 변수들.
    screen_array[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);
    screen_array[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,NULL,CONSOLE_TEXTMODE_BUFFER, NULL);

    //콘솔창의 커서를 보이지 않게 변경.
    current_cursor_info.dwSize = 1;
    current_cursor_info.bVisible = FALSE;

    //콘솔창 커서 옵션을 각 버퍼에 저장함.
    SetConsoleCursorInfo(screen_array[0], &current_cursor_info);
    SetConsoleCursorInfo(screen_array[1], &current_cursor_info);
}

// 화면 버퍼를 교체해줄 함수.
void flip_scene()
{
    SetConsoleActiveScreenBuffer(screen_array[screen_index]);

    //Flag 형식으로 화면을 계속해서 바꿈.
    screen_index = !screen_index;
}

// 화면을 지우는 함수.
void clear_scene()
{
    //0,0 좌표를 저장하여 0,0 좌표부터 시작하게 설정.
    COORD coordination = {0,0};
    DWORD dw;

    //실질적으로는 main 함수 내 clear 함수와 동일한 기능.
    // ' ' 을 80*25 (콘솔 창 크기) 만큼 채워내는 함수르 생각하면 됩니다.
    FillConsoleOutputCharacter(screen_array[screen_index], ' ', 13 * 15, coordination, &dw);
}

// 화면 버퍼를 해제(삭제하는) 함수.
void release_scene()
{
    CloseHandle(screen_array[0]);
    CloseHandle(screen_array[1]);
}

// 배열에 담긴 값을 하나 하나 출력하는 함수.
void print_scene(int x_position, int y_position, char *print_data)
{
    DWORD dw;

    COORD cursor_position = {x_position, y_position}; //출력할 문자의 좌표값을 저장.

    SetConsoleCursorPosition(screen_array[screen_index], cursor_position); //출력할 문자의 좌표값을 일치하게 이동.

    WriteFile(screen_array[screen_index], print_data,strlen(print_data), &dw, NULL); //버퍼에 출력 문자열을 저장.

}

// 문자의 색상값을 변경하는 함수.
void set_color(unsigned short color)
{
	SetConsoleTextAttribute(screen_array[screen_index], color);
}
