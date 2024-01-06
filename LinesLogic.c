#include "Tetris.h"

void ResetLines(int startLineY)
{
    for (int y = startLineY; y >= 0 ; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offset_below = (y + 1) * STAGE_WIDTH + x;
            if(stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }       
    }
}

int DeleteLines()
{
    int checkLine;
    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        checkLine = 1;
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            if(stage[offset] == 0)
            {
                checkLine = 0;
                break; //If at least one tile in a row is empty skip to next row
            }
        }
        if(checkLine)
        {
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
            ResetLines(y);
        }        
    }
    return checkLine;
}