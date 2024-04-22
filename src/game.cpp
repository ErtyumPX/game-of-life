#include <iostream>
#include <time.h>
#include "game.hpp"

void draw_grid(SDL_Renderer* renderer, bool **grid, int WIDTH, int HEIGHT, int CELL_SIZE) {
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      if (grid[i][j]) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      } else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      }
      SDL_Rect cell = {i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE};
      SDL_RenderFillRect(renderer, &cell);
    }
  }
}


void update_grid(bool **grid, int WIDTH, int HEIGHT, int CELL_SIZE) {
  bool **new_grid = new bool*[WIDTH / CELL_SIZE];
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    new_grid[i] = new bool[HEIGHT / CELL_SIZE];
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      new_grid[i][j] = false;
    }
  }
  // go for each cell in the grid
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      int neighbors = 0;
      // check all 8 neighbors
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          // skip the cell itself
          if (x == 0 && y == 0) {
            continue;
          }
          int new_i = i + x;
          int new_j = j + y;
          // check if the neighbor is within the grid bounds
          if (new_i >= 0 && new_i < WIDTH / CELL_SIZE && new_j >= 0 && new_j < HEIGHT / CELL_SIZE) {
            neighbors += grid[new_i][new_j] == true ? 1 : 0;
          }
        }
      }
      // if the cell is alive
      if (grid[i][j]) {
        if (neighbors < 2) {
          new_grid[i][j] = false;
        }
        else if (neighbors == 2 || neighbors == 3) {
          new_grid[i][j] = true;
        }
        else if (neighbors > 3) {
          new_grid[i][j] = false;
        }
      }
      else {
        if (neighbors == 3) {
          new_grid[i][j] = true;
        }
      }
    }
  }
  // copy the new grid to the old grid
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      grid[i][j] = new_grid[i][j];
    }
  }
  // free the new grid
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    delete[] new_grid[i];
  }
  delete[] new_grid;
}


bool** create_random_grid(int WIDTH, int HEIGHT, int CELL_SIZE) {
  srand(time(NULL));
  bool **grid = new bool*[WIDTH / CELL_SIZE];
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    grid[i] = new bool[HEIGHT / CELL_SIZE];
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      grid[i][j] = rand() % 2 == 0;
    }
  }
  return grid;
}

bool** create_empty_grid(int WIDTH, int HEIGHT, int CELL_SIZE) {
  srand(time(NULL));
  bool **grid = new bool*[WIDTH / CELL_SIZE];
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    grid[i] = new bool[HEIGHT / CELL_SIZE];
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      grid[i][j] = 0;
    }
  }
  return grid;
}
