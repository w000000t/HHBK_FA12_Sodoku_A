#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#include "sqlite3.h"

#define DB_FILE "sodoku_gruppe_a.db"

void initExistingValuesArrays(int *existingValues, int maxIndex);
#endif