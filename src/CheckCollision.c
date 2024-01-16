#include "Tetris.h"
#include "Tetromino.h"

int CheckCollision(const int tetrominoX, const int tetrominoY, const int *tetromino, const int stage[])
{
    for(int y = 0; y < TETROMINO_HEIGHT; y++)
    {
        for(int x = 0; x < TETROMINO_WIDTH; x++)
        {
            const int offset = y * TETROMINO_WIDTH + x;
            if(tetromino[offset] == 1) //if this tetramino's tile is not empty (= 0)
            {
                const int stage_offset = (y + tetrominoY) * STAGE_WIDTH + (x + tetrominoX);
                if(stage[stage_offset] != 0) //Check for not background color rather than edges color
                                             //to keep tetramino's color
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}