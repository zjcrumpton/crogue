#include <ncurses.h>
#include <stdio.h>
#include <rogue.h>

Entity* player;

int main(void) {
  int ch;
  Position startPos = { 10, 20 };

  initscr();
  noecho();
  curs_set(0);

  player = createPlayer(startPos);
  printEntity(player);

  while (ch = getch()) {
    if (ch == 'q') {
      break;
    }

    handleInput(ch);
    clear();
    printEntity(player);
  }

  endwin();

  return 0;
}
