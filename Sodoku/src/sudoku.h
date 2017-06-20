#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sqlite3.h"

#define DB_FILE "sodoku_gruppe_a.db"
#define SUDOKU_FIELDS_X_AXIS 9
#define SUDOKU_FIELDS_Y_AXIS 9

typedef struct {
	int disabled; // can the field be edited by the user
	int value; // the value of the sudoku field
}sudoku_field;

// prototypes
int initSudoku(int difficulty, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int validateSudoku();
int validateRow();
int validateField();
