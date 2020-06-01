#include "Header.h"

void RenderingPipeline(Game *game)
{
    ClearScene();

    DrawScene(game);

    FlipScene();
}
