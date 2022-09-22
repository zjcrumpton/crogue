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

// player.c functions
Entity* createPlayer(Position start_pos);
void handleInput(int input);
void printEntity(Entity* ent);

// externs
extern Entity* player;

// Game funcs
void gameLoop();
void closeGame();

// Window funcs
void setupCurses();
void closeWindow();

#endif
