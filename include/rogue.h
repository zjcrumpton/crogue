#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

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

// map funcs
Tile** createMapTiles();
void freeMap();

// draw funcs
void printMap();
void printTile(int y, int x, Tile* tile);
void printEntity(Entity* ent);
void drawGame();

// player.c functions
Entity* createPlayer(Position start_pos);
void handleInput(int input);

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
