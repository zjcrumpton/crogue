#include <rogue.h>

void gameLoop() {
  int ch;

  printEntity(player);

  while(ch = getch()) { 
    if (ch == 'q') { 
      break;
    } 

    handleInput(ch);
    clear();
    printEntity(player);
  } 
}

void closeGame() {
  free(player);
  closeWindow();
}
