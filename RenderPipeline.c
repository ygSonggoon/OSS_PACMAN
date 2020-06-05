// [Description]
// 렌더링이 돌아가는 구조를 간편화 시킬 함수.

#include "Header.h"

void RenderingPipeline(Game *game)
{
    ClearScene(); //콘솔 화면 정리.

    DrawScene(game); //게임 화면 출력.

    FlipScene(); //다음 콘솔 버퍼로 변경.
}
