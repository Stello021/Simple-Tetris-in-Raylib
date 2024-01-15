#ifndef TETROMINO_H
#define TETROMINO_H

#define TETROMINO_WIDTH 4
#define TETROMINO_HEIGHT 4
#define TETROMINO_TYPES 7
#define TETROMINO_COLORS 8

extern const int lTetromino0[];
extern const int lTetromino90[];
extern const int lTetromino180[];
extern const int lTetromino270[];
extern const int jTetromino0[];
extern const int jTetromino90[]; 
extern const int jTetromino180[];
extern const int jTetromino270[];
extern const int oTetromino[];
extern const int sTetromino0[]; 
extern const int sTetromino90[]; 
extern const int sTetromino180[]; 
extern const int sTetromino270[]; 
extern const int tTetromino0[];
extern const int tTetromino90[]; 
extern const int tTetromino180[]; 
extern const int tTetromino270[]; 
extern const int iTetromino0[]; 
extern const int iTetromino90[];
extern const int iTetromino180[]; 
extern const int iTetromino270[];
extern const int zTetromino0[]; 
extern const int zTetromino90[];
extern const int zTetromino180[]; 
extern const int zTetromino270[];

extern const int *tetrominoTypes[7][4];

int CheckCollision(const int tetrominoX, const int tetrominoY, const int *tetromino);



#endif //TETROMINO_H