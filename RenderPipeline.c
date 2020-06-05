// [Description]
// 렌더링이 돌아가는 구조를 간편화 시킬 함수.

#include "Header.h"

void rendering_pipeline(Game *game)
{
    clear_scene(); //콘솔 화면 정리.

    draw_scene(game); //게임 화면 출력.

    flip_scene(); //다음 콘솔 버퍼로 변경.
}
