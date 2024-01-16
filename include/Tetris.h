#ifndef TETRIS_H
#define TETRIS_H

#include "raylib.h"
#include <string.h>

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 16

void DrawStage(int offsetX, int offsetY, const int stage[], const Color colorTypes[]);
void DrawTetromino(const int stageOffsetX, const int stageOffsetY, const int tetrominoX, const int tetrominoY, const int *tetromino, const Color color);
void ResetLines(int startLineY);
int DeleteLines();
int* GetStage();

#endif //TETRIS_H