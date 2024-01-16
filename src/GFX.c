#include "Tetris.h"
#include "Tetromino.h"


void DrawStage(int offsetX, int offsetY, const int stage[], const Color colorTypes[])
{
    for(int y = 0; y < STAGE_HEIGHT; y++)
    {
        for(int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            Color color = colorTypes[stage[offset] - 1] ;
            if(stage[offset] != 0)
            { //Draw Grid edge
                if( (y == STAGE_HEIGHT - 1) || (x == 0 || x == STAGE_WIDTH - 1))
                {
                   DrawRectangle(x * TILE_SIZE + offsetX, y * TILE_SIZE + offsetY, TILE_SIZE, TILE_SIZE, WHITE);
                }
                else
                {
                    DrawRectangle(x * TILE_SIZE + offsetX, y * TILE_SIZE + offsetY, TILE_SIZE, TILE_SIZE, color);
                }
            }
            //Draw Line to separate grid's tiles
            DrawRectangleLines(x * TILE_SIZE + offsetX, y * TILE_SIZE + offsetY, TILE_SIZE, TILE_SIZE, GRAY);
        }
    }
}

void DrawTetromino(const int stageOffsetX, const int stageOffsetY, const int tetrominoX, const int tetrominoY, const int *tetromino, const Color color)
{
    for(int y = 0; y < TETROMINO_HEIGHT; y++)
    {
        for(int x = 0; x < TETROMINO_WIDTH; x++)
        {
            const int offset = y * TETROMINO_WIDTH + x;
            if(tetromino[offset] == 1)
            { //Draw Tetromino tile
              DrawRectangle((x + tetrominoX) * TILE_SIZE + stageOffsetX, (y + tetrominoY) * TILE_SIZE + stageOffsetY,
                            TILE_SIZE, TILE_SIZE, color);
            }
        }
    }
}

