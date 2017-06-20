#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sqlite3.h"

#define DB_FILE "sodoku_gruppe_a.db"
#define SUDOKU_FIELDS_X_AXIS 9
#define SUDOKU_FIELDS_Y_AXIS 9

typedef struct {
	int disabled;
	int value;
}sudoku_field;

int initSudoku(int difficulty, int sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int validateSudoku();
int validateRow();
int validateField();