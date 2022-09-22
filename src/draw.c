#include <rogue.h>

void printEntity(Entity* ent) {
  mvaddch(ent->pos.y, ent->pos.x, ent->ch);
}

void printMap() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      mvaddch(y, x, map[y][x].ch);
    }
  }
}

void drawGame() {
  clear();
  printMap();
  printEntity(player);
};
