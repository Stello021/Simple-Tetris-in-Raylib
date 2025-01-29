# Simple Tetris in Raylib

A simple implementation of the classic Tetris game using the `Raylib` graphics library in C. This project demonstrates fundamental game development concepts including grid-based gameplay, collision detection, and real-time user input handling.

## Game Features

- Classic Tetris gameplay mechanics
- Scoring system with increasing difficulty
- Piece rotation and movement
- Sound effects and background music
- Colorful tetromino pieces
- Grid-based collision detection

## Key Points

### Core Game Mechanics

The game's core mechanics are built around several key functions and structures that work together to create the Tetris experience:

#### Stage Management

```c
int stage[] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,  // First row with walls
    // ... middle rows ...
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1   // Bottom wall
};
```

The stage array represents the game field where:

- 0 represents empty space
- 1 represents walls
- Values 2-8 represent different colored blocks

#### Tetromino Structure

Tetrominoes are defined as 4x4 arrays for each rotation state:

```c
const int lTetromino0[] = {
    0, 1, 0, 0,   // Each tetromino is represented
    0, 1, 0, 0,   // as a 4x4 grid where 1s
    0, 1, 1, 0,   // indicate filled blocks
    0, 0, 0, 0,
};
```

The game maintains four rotation states (0°, 90°, 180°, 270°) for each tetromino type, stored in the `tetrominoTypes` array:

```c
const int *tetrominoTypes[7][4] = {
    {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
    // ... other tetromino definitions
};
```

#### Drawing Functions

`DrawStage`: Renders the game grid and placed blocks

```c
void DrawStage(int offsetX, int offsetY, const int stage[], const Color colorTypes[])
{
    // Iterates through the stage array
    for(int y = 0; y < STAGE_HEIGHT; y++)
    {
        for(int x = 0; x < STAGE_WIDTH; x++)
      {
           // Draws colored rectangles for blocks
           const int offset = y * STAGE_WIDTH + x;
            Color color = colorTypes[stage[offset] - 1] ;
            if(stage[offset] != 0)
            { 
                // Handles special coloring for grid edges
                if( (y == STAGE_HEIGHT - 1) || (x == 0 || x == STAGE_WIDTH - 1))
                {
                   DrawRectangle(x * TILE_SIZE + offsetX, y * TILE_SIZE + offsetY, TILE_SIZE, TILE_SIZE, WHITE);
                }
                else
                {
                    DrawRectangle(x * TILE_SIZE + offsetX, y * TILE_SIZE + offsetY, TILE_SIZE, TILE_SIZE, color);
                }
            }
            //Draw lines for visibility
            DrawRectangleLines(x * TILE_SIZE + offsetX, y * TILE_SIZE + offsetY, TILE_SIZE, TILE_SIZE, GRAY);
      }          
}
```

`DrawTetromino`: Renders the active tetromino piece

```c
void DrawTetromino(const int stageOffsetX, const int stageOffsetY, 
                   const int tetrominoX, const int tetrominoY, 
                   const int *tetromino, const Color color)
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
```

#### Collision Detection System

`CheckCollision`: Determines if a tetromino movement or rotation is valid

```c
int CheckCollision(const int tetrominoX, const int tetrominoY, 
                  const int *tetromino, const int stage[])
{
    // Checks each cell of the tetromino against the stage
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
```

#### Line Clearing Mechanism

`DeleteLines`: Checks for and removes completed lines

```c
int DeleteLines()
{
    // Scans each row for completeness
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
            // Removes completed lines
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
            ResetLines(y);
            PlaySound(clearSound);
            // Updates score
            score += 200;
            if(moveTetrominoDownTimer > 0.2f)
            {
                // Increases game speed
                moveTetrominoDownTimer -= 0.15f;
            }
        }        
    }
    return checkLine;    // Returns whether a line was cleared
}
```

`ResetLines`: Handles the gravity effect after line removal

```c
void ResetLines(int startLineY)
{
    // Moves all lines above the cleared line down
    for (int y = startLineY; y >= 0 ; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            // Updates the stage array to reflect new positions
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
```

#### Game Loop Implementation

The main game loop handles:

1. **Input Processing:**
   
   ```c
   // Rotation handling
   if(IsKeyPressed(KEY_SPACE)) {
    currentTetrominoRotation++;
    // Collision check and rotation validation
   }
   // Movement handling
   if (IsKeyPressed(KEY_RIGHT)) { 
   // Right movement with collision check
   }
   ```

2. **Game State Updates:**
   
   ```c
   // Vertical movement timing
   if(remainingTime <= 0 || IsKeyPressed(KEY_DOWN)) 
   { // Move piece down or lock it in place 
     // Generate new piece if necessary
     // Check for line clears
   }
   ```
   
   
   

3. **Scoring System:**
   
   ```c
   score += 200;  // Points for line clear
   moveTetrominoDownTimer -= 0.15f;  // Speed increase
   ```

### Constants and Configuration

Key game parameters are defined in header files:

```c
#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 16
#define TETROMINO_WIDTH 4
#define TETROMINO_HEIGHT 4
#define TETROMINO_TYPES 7
#define TETROMINO_COLORS 8
```

These constants control:

- Game grid dimensions
- Tetromino piece sizes
- Available piece types
- Color palette size

### Performance Considerations

1. Array Access Optimization:
   
   ```c
   const int offset = y * TETROMINO_WIDTH + x;  // Single calculation for array access
   ```

2. Collision Detection Efficiency:
   
   ```c
   if(tetromino[offset] == 1) 
   {  
     // Only check filled tetromino cells
     // Collision detection logic
   }
   ```

3. Memory Management:
   
   ```c
   memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));  // Efficient line clearing
   ```

# 
