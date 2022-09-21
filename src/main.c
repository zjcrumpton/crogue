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
  mvaddch(player->pos.y, player->pos.x, player->ch);

  while (ch = getch()) {
    if (ch == 'q') {
      break;
    }

    handleInput(ch);
    clear();
    mvaddch(player->pos.y, player->pos.x, player->ch);
  }

  endwin();

  return 0;
}
