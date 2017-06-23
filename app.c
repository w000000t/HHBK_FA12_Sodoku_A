#define _CRT_SECURE_NO_WARNINGS_

#include "app.h"

#include "inc/ui.h"
#include "inc/highscore.h"
#include "inc/sudoku.h"
#include "inc/ui_logic.h"

int main(void){
  SMALL_RECT windowSize = {0,0,156,78};

  BOOL ok;

  COORD screenSize;
  screenSize.X = 157;
  screenSize.Y = 79;

  ok=SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), screenSize);
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), ok, &windowSize);

  showIntro();
  system("pause");
  return 0;
}
