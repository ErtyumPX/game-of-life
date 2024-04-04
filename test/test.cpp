#include <cassert>
#include <iostream>
#include <stdexcept>
#include "game.hpp"

bool compare_grids(int** grid1, int** grid2, int WIDTH, int HEIGHT) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (grid1[i][j] != grid2[i][j]) return false;
    }
  }
  return true;
}

// Still Life Patterns
void block_test() {
  int** block_starter = new int*[4]
  {
    new int[4]{0, 0, 0, 0},
    new int[4]{0, 1, 1, 0},
    new int[4]{0, 1, 1, 0},
    new int[4]{0, 0, 0, 0}
  };
  int** block = new int*[4]
  {
    new int[4]{0, 0, 0, 0},
    new int[4]{0, 1, 1, 0},
    new int[4]{0, 1, 1, 0},
    new int[4]{0, 0, 0, 0}
  };
  int failed_count = 0;
  for (int i = 0; i < 32; i++) {
    update_grid(block_starter, 4, 4, 1);
    if (compare_grids(block_starter, block, 4, 4) != true) {
      failed_count++;
    }
  }
  if (failed_count > 0) {
    cout << "FAILED: Block Test" << endl;
  }
  else {
    cout << "PASSED: Block Test" << endl;
  }
  for (int i = 0; i < 4; i++) {
    delete[] block_starter[i];
    delete[] block[i];
  }
  delete[] block_starter;
  delete[] block;
}

void beehive_test() {
  int** beehive_starter = new int*[5]
  {
    new int[6]{0, 0, 0, 0, 0, 0},
    new int[6]{0, 0, 1, 1, 0, 0},
    new int[6]{0, 1, 0, 0, 1, 0},
    new int[6]{0, 0, 1, 1, 0, 0},
    new int[6]{0, 0, 0, 0, 0, 0},
  };
  int** beehive = new int*[5]
  {
    new int[6]{0, 0, 0, 0, 0, 0},
    new int[6]{0, 0, 1, 1, 0, 0},
    new int[6]{0, 1, 0, 0, 1, 0},
    new int[6]{0, 0, 1, 1, 0, 0},
    new int[6]{0, 0, 0, 0, 0, 0},
  };
  int failed_count = 0;
  for (int i = 0; i < 32; i++) {
    update_grid(beehive_starter, 5, 6, 1);
    if (compare_grids(beehive_starter, beehive, 5, 6) != true) {
      failed_count++;
    }
  }
  if (failed_count > 0) {
    cout << "FAILED: Beehive Test" << endl;
  }
  else {
    cout << "PASSED: Beehive Test" << endl;
  }
  for (int i = 0; i < 5; i++) {
    delete[] beehive_starter[i];
    delete[] beehive[i];
  }
  delete[] beehive_starter;
  delete[] beehive;
}

// Oscillator Life Patterns
void blinker_test() {
    int** blinker_starter = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 1, 1, 1, 0},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 0, 0}
  };
  int** blinker_horizontal = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 1, 1, 1, 0},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 0, 0}
  };
  int** blinker_vertical = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 1, 0, 0},
    new int[5]{0, 0, 1, 0, 0},
    new int[5]{0, 0, 1, 0, 0},
    new int[5]{0, 0, 0, 0, 0}
  };
  int failed_count = 0;
  for (int i = 0; i < 32; i++) {
    update_grid(blinker_starter, 5, 5, 1);
    if (i % 2 == 0) {
      if (compare_grids(blinker_starter, blinker_vertical, 5, 5) != true) {
        failed_count++;
      }
    }
    else {
      if (compare_grids(blinker_starter, blinker_horizontal, 5, 5) != true) {
        failed_count++;
      }
    }
  }
  if (failed_count > 0) {
    cout << "FAILED: Blinker Test" << endl;
  }
  else {
    cout << "PASSED: Blinker Test" << endl;
  }
  for (int i = 0; i < 5; i++) {
    delete[] blinker_starter[i];
    delete[] blinker_horizontal[i];
    delete[] blinker_vertical[i];
  }
  delete[] blinker_starter;
  delete[] blinker_horizontal;
  delete[] blinker_vertical;
}

// Spaceship Life Patterns
void glider_test() {
  int** glider_starter = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 1, 0, 0},
    new int[5]{0, 0, 0, 1, 0},
    new int[5]{0, 1, 1, 1, 0},
    new int[5]{0, 0, 0, 0, 0}
  };
  int** glider_first_day = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 1, 0, 1, 0},
    new int[5]{0, 0, 1, 1, 0},
    new int[5]{0, 0, 1, 0, 0}
  };
  int** glider_second_day = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 0, 1, 0},
    new int[5]{0, 1, 0, 1, 0},
    new int[5]{0, 0, 1, 1, 0}
  };
  int** glider_third_day = new int*[5]
  {
    new int[5]{0, 0, 0, 0, 1},
    new int[5]{0, 0, 0, 0, 0},
    new int[5]{0, 0, 1, 0, 0},
    new int[5]{0, 0, 0, 1, 1},
    new int[5]{0, 0, 1, 1, 0}
  };
  int failed_count = 0;
  update_grid(glider_starter, 5, 5, 1);
  if (compare_grids(glider_starter, glider_first_day, 5, 5) != true) {
    failed_count++;
  }
  update_grid(glider_starter, 5, 5, 1);
  if (compare_grids(glider_starter, glider_second_day, 5, 5) != true) {
    failed_count++;
  }
  update_grid(glider_starter, 5, 5, 1);
  if (compare_grids(glider_starter, glider_third_day, 5, 5) != true) {
    failed_count++;
  }
  if (failed_count > 0) {
    cout << "FAILED: Glider Test" << endl;
  }
  else {
    cout << "PASSED: Glider Test" << endl;
  }
  for (int i = 0; i < 5; i++) {
    delete[] glider_starter[i];
    delete[] glider_first_day[i];
    delete[] glider_second_day[i];
    delete[] glider_third_day[i];
  }
  delete[] glider_starter;
  delete[] glider_first_day;
  delete[] glider_second_day;
  delete[] glider_third_day;
}


int main(){
  // Still Life Patterns
  block_test();
  beehive_test();
  // Oscillator Life Patterns
  blinker_test();
  // Spaceship Life Patterns
  glider_test();
  return 0;
}
