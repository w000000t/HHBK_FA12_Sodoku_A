/*
================================================================================
Autoren: Timo Scheile, Lukas Knapp, Nick Schikora
Klasse: FA12
Programmname: ui_logic.h
Datum: 26.06.2017
Beschreibung: Deklaration von Funktionen, sowie Einbindung weiterer
			  Header-Dateien, welche mit der UI-Logik zu tun haben.
Version: 1.0
Compiler: Visual Studio
===============================================================================
*/


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
