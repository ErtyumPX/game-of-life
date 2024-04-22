#include <iostream>
#include <string>
#include <vector>

#include "game.hpp"

using namespace std;

#define FPS 15
#define WIDTH 800
#define HEIGHT 800
#define CELL_SIZE 10 // optimally should be a factor of WIDTH and HEIGHT

int main(int argc, char* argv[]) {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    cout << "Error initializing SDL: " << SDL_GetError() << endl;
  }
  SDL_Window* window = SDL_CreateWindow(
    "CsGoL",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WIDTH,
    HEIGHT,
    0
  );
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  cout << "Game initialized." << endl;

  bool** grid = create_random_grid(WIDTH, HEIGHT, CELL_SIZE);

  bool running = true;
  SDL_Event event;
  while (running) {
    Uint32 start_time = SDL_GetTicks();
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    // mouse events
    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
      int x, y;
      SDL_GetMouseState(&x, &y);
      if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        continue;
      }
      int i = x / CELL_SIZE;
      int j = y / CELL_SIZE;
      grid[i][j] = true;
    }
    else if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
      int x, y;
      SDL_GetMouseState(&x, &y);
      if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        continue;
      }
      int i = x / CELL_SIZE;
      int j = y / CELL_SIZE;
      grid[i][j] = false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    draw_grid(renderer, grid, WIDTH, HEIGHT, CELL_SIZE);
    update_grid(grid, WIDTH, HEIGHT, CELL_SIZE);

    SDL_RenderPresent(renderer);

    Uint32 end_time = SDL_GetTicks();
    if (end_time - start_time < 1000 / FPS) {
      SDL_Delay(1000 / FPS - (end_time - start_time));
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
