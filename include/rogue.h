#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int y;
  int x;
} Position;

typedef struct {
  Position pos;
  char ch;
} Entity;

// Map Data Structures
typedef struct {
  bool walkable;
  char ch;
} Tile;

typedef struct {
  int height;
  int width;
  Position pos;
  Position center;
} Room;

// room funcs
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// map funcs
Tile** createMapTiles();
void freeMap();
Position setupMap();

// draw funcs
void printMap();
void printEntity(Entity* ent);
void drawGame();
void printTile(int y, int x, Tile* tile);

// player.c functions
Entity* createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);

// externs
extern Entity* player;
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Tile** map;

// Game funcs
void gameLoop();
void closeGame();

// Window funcs
void setupCurses();
void closeWindow();

#endif
