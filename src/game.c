#include <rogue.h>

void gameLoop() {
  int ch;

  makeFOV(player);
  drawGame();

  while(ch = getch()) { 
    if (ch == 'q') { 
      break;
    } 

    handleInput(ch);
    drawGame();
  } 
}

void closeGame() {
  free(player);
  closeWindow();
}
