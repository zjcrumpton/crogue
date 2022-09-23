#include <ncurses.h>
#include <stdio.h>
#include <rogue.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity* player;
Tile** map;

int main(void) {
  int ch;
  map = createMapTiles();
  setupCurses();
  srand(time(NULL));
  Position startPos = setupMap();
  player = createPlayer(startPos);

  gameLoop();
  closeGame();

  return 0;
}
