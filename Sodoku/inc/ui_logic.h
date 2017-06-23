#ifndef __UI_LOGIC__
#define __UI_LOGIC__

#include "Utils.h"
#include "globals.h"
#include "ui.h"
#include "sudoku.h"
#include "login.h"

int mainMenu();
int loggedInMenu();
int difficulty();
int sudokuControls();

void readUsername(char *cUsername);
void readPassword(char *cPassword);
void handleLogin();
void handleRegistration();
void getHighscore(int user_id);
void help(int xPosition, int yPosition, sudoku_field field[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int pauseMenuHandler();

void navigation(char cKeyPressed[]);
#endif
