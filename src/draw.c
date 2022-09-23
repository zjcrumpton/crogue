#include <rogue.h>

void printEntity(Entity* ent) {
  mvaddch(ent->pos.y, ent->pos.x, ent->ch | ent->color);
}

void printTile(int y, int x, Tile* tile, int color) {
  mvaddch(y, x, tile->ch | COLOR_PAIR(color));
};

void printMap() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {

      if (map[y][x].visible) {
        printTile(y, x, &map[y][x], map[y][x].color);
      } else if (map[y][x].seen) {
        printTile(y, x, &map[y][x], SEEN_COLOR);
      } else {
        Tile tile;
        tile.ch = ' ';
        printTile(y, x, &tile, VISIBLE_COLOR);
      }
    }
  }
}

void drawGame() {
  clear();
  printMap();
  printEntity(player);
};
