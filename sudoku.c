#include "sudoku.h"

int main(void){
	sudoku_field sudoku_fields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS];
	int i,j;

	initSudoku(1, sudoku_fields);

	for(i = 0; i < SUDOKU_FIELDS_X_AXIS; i++){
		for(j = 0; j < SUDOKU_FIELDS_Y_AXIS; j++){
			printf("%i ", sudoku_fields[i][j].value);
		}
		printf("\n");
	}

	system("pause");
}
int initSudoku(int difficulty, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
	int iXAXIS, iYAXIS, rc, cols, iCols, iColNrXCord, iColNrYCord, iColNrValue;
	sqlite3 *db;
	sqlite3_stmt *stmt;

	char sql_game_preset[] = "SELECT "\
								"spf.x_cordinate as x_cord,"\
								"spf.y_cordinate as y_cord,"\
								"spf.value as value "\
							"FROM sudoku_preset_fields spf "\
							"INNER JOIN sudoku_preset_games spg ON spg.id = spf.preset_id";

	for(iXAXIS = 0; iXAXIS < SUDOKU_FIELDS_X_AXIS; iXAXIS++){
		for(iYAXIS = 0; iYAXIS < SUDOKU_FIELDS_Y_AXIS; iYAXIS++){
			sudokuFields[iXAXIS][iYAXIS].disabled = 1;
			sudokuFields[iXAXIS][iYAXIS].value = 0;
		}
	}

	// init db connection
	rc = sqlite3_open_v2(DB_FILE, &db, SQLITE_OPEN_READWRITE, NULL);

	if(rc != SQLITE_OK){
		printf("Sudoku initialization failed due to a missing database connection.");
		system("pause");
	}

	// select game preset from db
	rc = sqlite3_prepare_v2(db, sql_game_preset, strlen(sql_game_preset), &stmt, NULL);

	if(rc != SQLITE_OK){
		printf("Failed to load the game preset. Error code: %i", rc);
		system("pause");
	}

	cols = sqlite3_column_count(stmt);
	while(sqlite3_step(stmt) == SQLITE_ROW){
		printf("cols: %i \n", cols);
		for(iCols = 0; iCols < cols; iCols++){
			if(strcmp((const char*)sqlite3_column_name(stmt, iCols), "x_cord") == 0){
				iColNrXCord = sqlite3_column_int(stmt, iCols);
			}

			if(strcmp((const char*)sqlite3_column_name(stmt, iCols), "y_cord") == 0){
				iColNrYCord = sqlite3_column_int(stmt, iCols);
			}

			if(strcmp((const char*)sqlite3_column_name(stmt, iCols), "value") == 0){
				iColNrValue = sqlite3_column_int(stmt, iCols);
			}
		}
		sudokuFields[iColNrXCord][iColNrYCord].value = iColNrValue;
	}
	return 1; // OK
}

int validateSudoku(){
	return 0;
}

int validateRow(){
	return 0;
}

int validateField(){
	return 0;
}

