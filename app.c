#define _CRT_SECURE_NO_WARNINGS_

#include "app.h"

#include "inc/ui.h"
#include "inc/highscore.h"
#include "inc/sudoku.h"
#include "inc/ui_logic.h"

int main(void){
  COORD screenSize;
  screenSize.X = 157;
  screenSize.Y = 79;

  SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), screenSize);

  mainMenu();
	system("pause");
	return 0;
}