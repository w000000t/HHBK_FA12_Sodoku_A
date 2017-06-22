#ifndef __SUDOKU__
#define __SUDOKU__
#include "Utils.h"

#include "customTypes\sudoku_field.h"
#include "constants.h"

// prototypes
int initSudoku(int difficulty, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int validateSudoku(sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int validateRow(int rowXIndex, int rowYIndex, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int validateRows(sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]);
int validateField();
#endif