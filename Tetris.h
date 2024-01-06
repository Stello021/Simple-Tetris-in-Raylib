#include "raylib.h"
#include <string.h>

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 16
#define TETROMINO_WIDTH 4
#define TETROMINO_HEIGHT 4
#define TETROMINO_TYPES 7

extern int stage[];

extern const Color colorTypes[8];


int CheckCollision(const int tetrominoX, const int tetrominoY, const int *tetromino);
void DrawStage(int offsetX, int offsetY);
void DrawTetromino(const int stageOffsetX, const int stageOffsetY, const int tetrominoX, const int tetrominoY, const int *tetromino, const Color color);
void ResetLines(int startLineY);
int DeleteLines();