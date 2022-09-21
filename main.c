#include <ncurses.h>
#include <stdio.h>

int main(void) {
  initscr();
  endwin();
  printf("Hello World!\n");

  return 0;
}
