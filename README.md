# Conway's Game of Life

I believe it was the fastest project I've ever done which took around 1.5 hours.

Infamous Conway's Game of Life implemented in C++ with SDL2.

---

<p align="left">
  <img width="400" height="400" src="https://github.com/ErtyumPX/game-of-life/blob/main/assets/images/window_screenshot.png?raw=true">
</p>

## License

This project is licensed under the [GNU GPL-3.0](https://github.com/ErtyumPX/game-of-life/blob/main/LICENSE) license.

Feel free to use the source code. Referring to the repository would be very much appreciated.

## Setup

Project is currently compiled with `GNU G++ 13.2.1`.

The only third-party dependency is `SDL2`. Used version of SDL2 in project is `2.28.5`, should work as long as it is **SDL2** and not **SDL**.

For compiling and linking rules `GNU Make 4.4.1` was used. After downloading dependencies, make sure to change the include paths inside the Makefile.

```
# change the paths for '-I' 
CC := g++
CFLAGS := -Wall -std=c++11 -I/usr/include/SDL2           # here
TEST_CFLAGS := -Wall -std=c++11 -Iinclude/SDL2 -Isrc/    # and here
LDFLAGS := -lSDL2 -lSDL2_image
...
```

After fulfilling dependencies, download or clone the project and use Makefile to easily compile:

```
> make all
> make run
```

Since SDL2 is a cross-platform media library, output should work on Windows, MacOS and Linux.

## Rules

The simulation goes in a 2D grid where each cell can be either dead or alive. The rules are as follows:
- Any live cell with fewer than two live neighbors dies, as if by underpopulation.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by overpopulation.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Directly taken from the Wikipedia page of the [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

## General Structure

### Directory Structure and Files

- `src/` directory contains the source code
  - `src/main.cpp` is the entry point of the program
  - `src/game.hpp` contains the declarations of the methods
  - `src/game_of_life.cpp` contains the implementation
- `stable/` directory contains the stable output
  - `stable/game.life` is the executable

### How It Goes

Current version is not designed specifically to be used anywhere. Without any arguments, it will create a grid according to the `WIDTH`, `HEIGHT` and `CELL_SIZE` constants in `main.cpp`, randomly fill a grid and start the simulation.

The constant `FPS` is the frame rate of the simulation. It is set to 15 by default.
