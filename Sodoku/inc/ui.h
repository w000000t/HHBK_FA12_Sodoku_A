#ifndef __UI__
#define __UI__

#include "Utils.h"
#include "constants.h"
#include "customTypes\sudoku_field.h"

void center(char cMessage[]);
void bigWhiteSpace();
void whiteSpace();
void quadWhiteSpace();
void hexaWhiteSpace();
void lineBreaks();
void printErrorMessage(char *cError);
void showStartScreen(int iSelector);
void printLogin();
void printRegistration();
void printInputUsername();
void printInputPassword();
void printInputPasswordRepeat();
void printSuccessMessage(char* cUsername);
void showDifficulty(int iSelector);
void showLoggedInStartScreen(int iSelector);
void printFieldHorizontal();
void printField(sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
void showHighscore();
void printSelector(int iPosition, int iSelector);
void showIntro();
#endif
