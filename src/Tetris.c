#include <time.h>
#include "Tetris.h"
#include <stdio.h>
#include "Tetromino.h"

int stage[] = 
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const Color colorTypes[TETROMINO_COLORS] =
{
    { 255, 255, 85, 255 },
    { 85, 43, 158, 255 },
    { 56, 255, 85, 255 },
    { 255, 255, 63, 255 },
    { 255, 42, 85, 255 },
    { 255, 100, 85, 255 },
    { 97, 5, 85, 255 },
    { 85, 45, 63, 255 }
};

const int lTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int lTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino180[] =
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino270[] =
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino90[] =
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino180[] =
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};


const int oTetromino[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};

const int sTetromino180[] =
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
};

const int sTetromino270[] =
{
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
};


const int tTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino270[] =
{
    1, 0, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int zTetromino90[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const int zTetromino180[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino270[] =
{
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int *tetrominoTypes[7][4] =
{
    {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
    {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
    {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
    {oTetromino, oTetromino, oTetromino, oTetromino},
    {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
    {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
    {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

Music soundtrack;
Sound clearSound;
Sound rotateSound;

int score = -100;
float moveTetrominoDownTimer = 1.f;

int* GetStage()
{
  return stage;
}

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
            PlaySound(clearSound);
            score += 200;
            if(moveTetrominoDownTimer > 0.2f)
            {
            moveTetrominoDownTimer -= 0.15f;
            }
        }        
    }
    return checkLine;
}
int main(int argc, char** argv, char** environ)
{
    const int windowWidth = 512;
    const int windowHeight = 512;
    
    //Start Offset to center Grid at the middle of the window
    const int startOffsetX = (windowWidth / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    const int startOffsetY = (windowHeight / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);
     
    //Starting tetromino's coordinates
    const int tetrominostartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;

    int currentTetrominoX = tetrominostartX;
    int currentTetrominoY = tetrominoStartY;

    time_t unixTime;
    time(&unixTime);
    SetRandomSeed(unixTime);
    int currentTetrominoType = GetRandomValue(0, TETROMINO_TYPES - 1);
    int currentTetrominoRotation = 0;
    int currentColor = GetRandomValue(0, TETROMINO_COLORS - 1);

    float remainingTime = moveTetrominoDownTimer;

    InitWindow(windowWidth, windowHeight, "Tetris");
    SetTargetFPS(60);
    InitAudioDevice();
    soundtrack = LoadMusicStream("Assets/Sounds/nutcracker-6-101soundboards.mp3");
    PlayMusicStream(soundtrack);
    rotateSound = LoadSound("Assets/Sounds/se_game_rotate.wav");
    clearSound = LoadSound("Assets/Sounds/clear.wav");

    Font font = LoadFontEx("Assets/Font/monogram.ttf", 64, 0, 0);
    Vector2 scoreNameTextPosition = {30,65};
    Vector2 scoreTextPosition = {50,100};

    while(!WindowShouldClose())
    {
        UpdateMusicStream(soundtrack);
        remainingTime -= GetFrameTime();
        if(IsKeyPressed(KEY_SPACE)) 
        {
          const int lastRotation = currentTetrominoRotation;
          currentTetrominoRotation++;
          if(currentTetrominoRotation > 3)
          {
            currentTetrominoRotation = 0;
          }
          if(CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentTetrominoRotation], stage))
          {
             currentTetrominoRotation = lastRotation;
          }
          else
          {
            PlaySound(rotateSound);
          }

        }
        //No need to check position overflow, wall prevent this situation
        if (IsKeyPressed(KEY_RIGHT) && !CheckCollision(currentTetrominoX + 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentTetrominoRotation], stage))
        {
            currentTetrominoX++;
        }
        //No need to check position overflow, wall prevent this situation
        if (IsKeyPressed(KEY_LEFT)  && !CheckCollision(currentTetrominoX - 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentTetrominoRotation], stage))
        {
            currentTetrominoX--;
        }
        if((remainingTime <= 0 || IsKeyPressed(KEY_DOWN)))
        {
           if(!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[currentTetrominoType][currentTetrominoRotation], stage))
           {
             currentTetrominoY++;
             remainingTime = moveTetrominoDownTimer;           
           }
           else
           {
            for(int y = 0; y < TETROMINO_HEIGHT; y++)
            {
              for(int x = 0; x < TETROMINO_WIDTH; x++)
              {
                const int offset = y * TETROMINO_WIDTH + x;
                const int* tetromino =  tetrominoTypes[currentTetrominoType][currentTetrominoRotation];
                if(tetromino[offset] == 1) //if this tetramino's tile is not empty (= 0)
                {
                  const int stage_offset = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);
                  stage[stage_offset] = currentColor + 1;
                }
              }
            }
            DeleteLines();

            currentTetrominoX = tetrominostartX;
            currentTetrominoY = tetrominoStartY;
            currentTetrominoType = GetRandomValue(0, 6);
            currentTetrominoRotation = 0;
            currentColor = GetRandomValue(0, 7);
           }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Score",scoreNameTextPosition, 38, 2.f, WHITE);
        if(score < 0)
        {
            DrawTextEx(font, "0",scoreTextPosition, 38, 2.f, WHITE);
        
        }
        else
        {
            char scoreString[10];
            sprintf(scoreString, "%d", score);
            DrawTextEx(font, scoreString,scoreTextPosition, 38, 2.f, WHITE);           
        }
        int fullRowCounter = 0;
        //Create Tetris Grid
        DrawStage(startOffsetX, startOffsetY, stage, colorTypes);
        DrawTetromino(startOffsetX, startOffsetY, currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentTetrominoRotation], colorTypes[currentColor]);
        EndDrawing();
        GetFrameTime();
    }
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(soundtrack);
    CloseAudioDevice();
    return 0;
}