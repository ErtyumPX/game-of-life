#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

using namespace std;

void draw_grid(SDL_Renderer* renderer, int **grid, int WIDTH, int HEIGHT, int CELL_SIZE);

void update_grid(int **grid, int WIDTH, int HEIGHT, int CELL_SIZE);
