clang.exe -o bin/Tetris.exe src/Tetris.c src/CheckCollision.c src/GFX.c src/LinesLogic.c src/Tetromino.c -I .\include -L .\include/Libraries/Raylib -l raylibdll