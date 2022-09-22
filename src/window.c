#include <rogue.h>

void setupCurses() {
  initscr();
  noecho();
  curs_set(0);
}

void closeWindow() {
  endwin();
}
