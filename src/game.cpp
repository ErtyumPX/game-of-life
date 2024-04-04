#include <iostream>
#include "game.hpp"

void draw_grid(SDL_Renderer* renderer, int **grid, int WIDTH, int HEIGHT, int CELL_SIZE) {
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      if (grid[i][j] == 1) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      } else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      }
      SDL_Rect cell = {i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE};
      SDL_RenderFillRect(renderer, &cell);
    }
  }
}

void update_grid(int **grid, int WIDTH, int HEIGHT, int CELL_SIZE) {
  int **new_grid = new int*[WIDTH / CELL_SIZE];
  for (int i = 0; i < WIDTH / CELL_SIZE; i++) {
    new_grid[i] = new int[HEIGHT / CELL_SIZE];
    for (int j = 0; j < HEIGHT / CELL_SIZE; j++) {
      new_grid[i][j] = 0;
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
            neighbors += grid[new_i][new_j];
          }
        }
      }
      // if the cell is alive
      if (grid[i][j] == 1) {
        if (neighbors < 2) {
          new_grid[i][j] = 0;
          cout << "Cell at " << i << ", " << j << " died due to underpopulation." << endl;
        }
        else if (neighbors == 2 || neighbors == 3) {
          new_grid[i][j] = 1;
        }
        else if (neighbors > 3) {
          new_grid[i][j] = 0;
          cout << "Cell at " << i << ", " << j << " died due to overpopulation." << endl;
        }
      }
      else {
        if (neighbors == 3) {
          new_grid[i][j] = 1;
          cout << "Cell at " << i << ", " << j << " was born." << endl;
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
}
