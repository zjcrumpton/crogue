#include <rogue.h>

void gameLoop() {
  int ch;

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
