#include <ncurses.h>
#include <stdio.h>
#include <rogue.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity* player;
Tile** map;

int main(void) {
  int ch;
  Position startPos = { 10, 20 };
  player = createPlayer(startPos);
  map = createMapTiles();

  setupCurses();
  gameLoop();
  closeGame();

  return 0;
}
