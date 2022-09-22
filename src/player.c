#include <rogue.h>

Entity* createPlayer(Position startPos) {
  Entity* newPlayer = calloc(1, sizeof(Entity));

  newPlayer->pos.y = startPos.y;
  newPlayer->pos.x = startPos.x;
  newPlayer->ch = '@';

  return newPlayer;
}

void handleInput(int input) {
  switch(input) {
    //move up
    case 'w':
      player->pos.y--;
      break;
    //move down
    case 's':
      player->pos.y++;
      break;
    //move left
    case 'a':
      player->pos.x--;
      break;
    //move right
    case 'd':
      player->pos.x++;
      break;
    default:
      break;
  }
}

void printEntity(Entity* ent) {
  mvaddch(ent->pos.y, ent->pos.x, ent->ch);
}
