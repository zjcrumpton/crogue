#include <rogue.h>

Entity* createPlayer(Position startPos) {
  Entity* newPlayer = calloc(1, sizeof(Entity));

  newPlayer->pos.y = startPos.y;
  newPlayer->pos.x = startPos.x;
  newPlayer->ch = '@';
  newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);

  return newPlayer;
}

void handleInput(int input) {
  Position newPos = { player->pos.y, player->pos.x };

  switch(input) {
    //move up
    case 'w':
      newPos.y--;
      break;
    //move down
    case 's':
      newPos.y++;
      break;
    //move left
    case 'a':
      newPos.x--;
      break;
    //move right
    case 'd':
      newPos.x++;
      break;
    default:
      break;
  }

  movePlayer(newPos);
}

void movePlayer(Position newPos) {
  if (map[newPos.y][newPos.x].walkable) {
    clearFOV(player);
    player->pos.y = newPos.y;
    player->pos.x = newPos.x;
    makeFOV(player);
  }
}
