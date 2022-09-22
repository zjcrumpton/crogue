#include <ncurses.h>
#include <stdio.h>
#include <rogue.h>

Entity* player;

int main(void) {
  int ch;
  Position startPos = { 10, 20 };
  player = createPlayer(startPos);

  setupCurses();
  gameLoop();
  closeGame();

  return 0;
}

