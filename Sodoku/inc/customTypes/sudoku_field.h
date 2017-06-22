#ifndef __sudoku_field__
#define __sudoku_field__
typedef struct {
	int disabled; // can the field be edited by the user
	int value; // the value of the sudoku field
}sudoku_field;
#endif