#ifndef TETROMINO_H
#define TETROMINO_H

#define TETROMINO_WIDTH 4
#define TETROMINO_HEIGHT 4
#define TETROMINO_TYPES 7
#define TETROMINO_COLORS 8

int CheckCollision(const int tetrominoX, const int tetrominoY, const int *tetromino, const int stage[]);

#endif //TETROMINO_H