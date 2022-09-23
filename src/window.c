#include <rogue.h>

void setupCurses() {
  initscr();
  noecho();
  curs_set(0);

  if (has_colors()) {
    start_color();

    init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
  }
}

void closeWindow() {
  endwin();
}
