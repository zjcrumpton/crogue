#include <rogue.h>

Tile** createMapTiles() {
  Tile** tiles = calloc(MAP_HEIGHT, sizeof(Tile*));

  for (int y = 0; y < MAP_HEIGHT; y++) {
    tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
    for (int x = 0; x < MAP_WIDTH; x++) {
      tiles[y][x].ch = '#';
      tiles[y][x].walkable = false;
      tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
      tiles[y][x].visible = false;
      tiles[y][x].transparent = false;
      tiles[y][x].seen = false;
    }
  }

  return tiles;
}

Position setupMap() {
  int y, x, height, width, nRooms;
  nRooms =  (rand() % 11) + 5;
  Room* rooms = calloc(nRooms, sizeof(Room));
  Position startPos;

  for (int i = 0; i < nRooms; i++) {
    y = (rand() % (MAP_HEIGHT - 10)) + 1;
    x = (rand() % (MAP_WIDTH - 20)) + 1;
    height = (rand() % 7) + 3;
    width = (rand() % 15) + 5;
    rooms[i] = createRoom(y, x, height, width);
    addRoomToMap(rooms[i]);

    if (i > 0) {
      connectRoomCenters(rooms[i - 1].center, rooms[i].center);
    }
  }

  startPos.y = rooms[0].center.y;
  startPos.x = rooms[0].center.x;

  free(rooms);

  return startPos;
}

void freeMap() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    free(map[y]);
  }
  free(map);
}
