#ifndef __UI_LOGIC__
#define __UI_LOGIC__

#include "Utils.h"
#include "ui.h"

int mainMenu();
int loggedInMenu();
int difficulty();
int sudokuControls();

char readUsername(char cUsername[]);
void readPassword(char cPassword[]);
void handleLogin();
void handleRegistration();
void getHighscore(int user_id);
void help(int xPosition, int yPosition, sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int pauseMenuHandler();

void navigation(char cKeyPressed[]);
#endif
