#ifndef __HIGHSCORE__
#define __HIGHSCORE__

#include "Utils.h"
#include "ui.h"

void databaseCallHighscore(char *sQuery);
static int callbackBestenliste(void *data, int argc, char **argv,
                               char **colName);
void showHighscore();
void getHighscoreTable();
void checkIfColIsPoint(char *const *argv, char *const *colName, int i);
void checkIfColIsName(char *const *argv, char *const *colName, int i);

#endif