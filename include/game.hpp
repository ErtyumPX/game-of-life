#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

using namespace std;

void draw_grid(SDL_Renderer* renderer, bool **grid, int WIDTH, int HEIGHT, int CELL_SIZE);

void update_grid(bool **grid, int WIDTH, int HEIGHT, int CELL_SIZE);

bool** create_random_grid(int WIDTH, int HEIGHT, int CELL_SIZE);

bool** create_empty_grid(int WIDTH, int HEIGHT, int CELL_SIZE);
