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

void navigation(char cKeyPressed[]);
#endif