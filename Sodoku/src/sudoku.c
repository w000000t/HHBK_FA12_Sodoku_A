#include "../inc/sudoku.h"

/**
Function initSudoku
Parameters: difficulty The difficulty the sudoku should have,
			sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS] 
				The two dimensional array that contains all fields of the sudoku
Return: -
Description: Inits the sudoku field and loads the preset from the database.
**/
int initSudoku(int difficulty, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
	int iXAXIS = 0, iYAXIS = 0, rc, cols, iCols, iColNrXCord, iColNrYCord, iColNrValue;
	sqlite3 *db;
	sqlite3_stmt *stmt;

	char sql_game_preset_template[] = "SELECT "\
								"spf.x_cordinate as x_cord,"\
								"spf.y_cordinate as y_cord,"\
								"spf.value as value "\
							"FROM sudoku_preset_fields spf "\
							"INNER JOIN sudoku_preset_games spg ON spg.id = spf.preset_id "\
							"WHERE spg.id = ("\
							"	SELECT "\
							"		sspg.id "\
							"	FROM sudoku_preset_games sspg "\
							"	WHERE sspg.difficulty = %i "\
							"	ORDER BY (abs(random())) "\
							"	LIMIT 1 "\
							")";

	char *sql_game_preset;

	sql_game_preset = sqlite3_mprintf(sql_game_preset_template, difficulty);

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
		exit(-1);
	}

	// select game preset from db
	rc = sqlite3_prepare_v2(db, sql_game_preset, strlen(sql_game_preset), &stmt, NULL);

	if(rc != SQLITE_OK){
		printf("Failed to load the game preset. Error code: %i", rc);
		system("pause");
		exit(-1);
	}

	cols = sqlite3_column_count(stmt);
	while(sqlite3_step(stmt) == SQLITE_ROW){
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

	sqlite3_finalize(stmt);
	return 1; // OK
}

/**
Function: validateSudoku
Parameters: sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS] 
				The two dimensional array that contains all fields of the sudoku
Return: Returns 1 if the sudoku is valid and 0 if its not
**/
int validateSudoku(sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
  int rowsValid = 0, boxesValid = 0;
  
  rowsValid = validateRows(sudokuFields);
  boxesValid = validateFields(sudokuFields);

  if(rowsValid == 1 && boxesValid == 1){
	return 1;
  }else{
	return 0;
  }
}

/**
Function: validateRow
Parameters: rowXIndex, rowYIndex, 
			sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS] 
				The two dimensional array that contains all fields of the sudoku
Return: Returns 1 if the given row is valid and 0 if its not
**/
int validateRow(int rowXIndex, int rowYIndex, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
	int existingValuesVertical[SUDOKU_FIELDS_X_AXIS];
	int existingValuesHorizontal[SUDOKU_FIELDS_Y_AXIS];
	int iCol, currentValue, valueIndex;

	// init help arrays
	initExistingValuesArrays(existingValuesVertical, SUDOKU_FIELDS_X_AXIS);
	initExistingValuesArrays(existingValuesHorizontal, SUDOKU_FIELDS_Y_AXIS);

	// vertical check
	for(iCol = 0; iCol < SUDOKU_FIELDS_X_AXIS; iCol++){
		currentValue = sudokuFields[rowXIndex][iCol].value;

		valueIndex = currentValue == 0 ? 0 : currentValue - 1;
		if(existingValuesVertical[valueIndex] == 1){
			return 0;
		}else{
			existingValuesVertical[valueIndex] = 1;
		}
	}
	// horizontal check
	for(iCol = 0; iCol < SUDOKU_FIELDS_Y_AXIS; iCol++){
		currentValue = sudokuFields[iCol][rowYIndex].value;

		valueIndex = currentValue == 0 ? 0 : currentValue - 1;
		if(existingValuesHorizontal[valueIndex] == 1){
			return 0;
		}else{
			existingValuesHorizontal[valueIndex] = 1;
		}
	}
	return 1;
}

/**
Function: validateRows
Parameter: sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS] 
			The two dimensional array that contains all fields of the sudoku
Return: Gives 1 if the row is valid and 0 if it is not.
Description: Checks, whether all rows are valid and all numbers in the given rows exist only once.
**/
int validateRows(sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
	int iX, iY, rc;

	for(iX = 0; iX < SUDOKU_FIELDS_X_AXIS; iX++){
		rc = validateRow(iX, iX, sudokuFields); // diagonale
	}

	return rc;
}

/**
Function: validateField
Parameter: topLeftXIndex The x index of the top left corner of the field to validate
		   topLeftYIndex the y index of the top left corner of the field to validate
		   sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS] 
			The two dimensional array that contains all fields of the sudoku
Return:	Returns 1 if the field is valid and 0 if it is not.
Description: Checks, wheather the given field is valid or not.
**/
int validateField(int topLeftXIndex, int topLeftYIndex, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
	int iX, iY, existingValues[SUDOKU_FIELDS_X_AXIS], currentValue, valueIndex;

	initExistingValuesArrays(existingValues, SUDOKU_FIELDS_X_AXIS);

	for(iX = topLeftXIndex; iX < topLeftXIndex + 3; iX++){
		for(iY = topLeftYIndex; iY < topLeftYIndex + 3; iY++){
			currentValue = sudokuFields[iX][iY].value;

			valueIndex = currentValue == 0 ? 0 : currentValue - 1;

			if(existingValues[valueIndex] == 1){
				return 0;
			}else{
				existingValues[valueIndex] = 1;
			}
		}
	}
	return 1;
}

/**
Function: validateFields
Parameter: sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS] 
			The two dimensional array that contains all fields of the sudoku
Return: Returns 1 if all fields are valid and 0 if not.

Description: Validates that each number from 1-9 is existing once in the 3x3 fields.
**/
int validateFields(sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
	int iX, iY, rc;

	for(iX = 0; iX < SUDOKU_FIELDS_X_AXIS; iX+=3){
		for(iY = 0; iY < SUDOKU_FIELDS_Y_AXIS; iY+=3){
			rc = validateField(iX, iY, sudokuFields);
		}
	}
	return rc;
}

void getPossibleNumbersForField(
  int xCord,
  int yCord,
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
){
  int maxNumbers = 9, firstNumber = 1, i = 0, originalValue;
  originalValue = sudokuFields[xCord][yCord].value;

  for(i = 1; i <= maxNumbers; i++){
    // skip the entered value
    if(originalValue == i) continue;

    // assign temporary value to the current field to check if its valid
    sudokuFields[xCord][yCord].value = i;

    // if the value is valid, expand the array for the possible numbers
    // and add the number to the array
    // =>continue with the next number
    if(
      validateRow(xCord, yCord, sudokuFields) == 1 &&
      validateField((xCord / 3) * 3, (yCord / 3) * 3, sudokuFields) == 1
      ){
      if(firstNumber == 1){
        printf("%i ", i);
        firstNumber = 0;
      } else{
        printf(", %i", i);
      }
    }
  }
  // reset the field to the original value
  sudokuFields[xCord][yCord].value = originalValue;
}

void solveSudoku(int direction, int currentXPos, int currentYPos, sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]){
  // wenn searchFieldDirection -1 -> gehe ein Feld nach links 
  // wenn searchFieldDirection 1 -> gehe ein Feld nach rechts
  int i = 0, originalValue, newXPos = currentXPos, newYPos = currentYPos, maxNumbers = 9;

  originalValue = sudokuFields[currentXPos][currentYPos].value == 0 ?
    1 : sudokuFields[currentXPos][currentYPos].value;
  printf("start %i %i \n", newXPos, newYPos);
  for(i = originalValue; i <= maxNumbers; i++){
    sudokuFields[currentXPos][currentYPos].value = i;
    if(
      validateRow(currentXPos, currentYPos, sudokuFields) == 1 &&
      validateField((currentXPos / 3) * 3, (currentYPos / 3) * 3, sudokuFields)
      ){
      if(
        (newXPos + 1) < SUDOKU_FIELDS_X_AXIS
        ){
        newXPos++;
      } else if(
        (newXPos + 1) == SUDOKU_FIELDS_X_AXIS &&
        (newYPos + 1) < SUDOKU_FIELDS_Y_AXIS
        ){
        newXPos = 0;
        newYPos++;
      } else if(
        (newXPos + 1) == SUDOKU_FIELDS_X_AXIS &&
        (newYPos + 1) == SUDOKU_FIELDS_Y_AXIS
        ){
        newXPos = 0;
        newYPos = 0;
      }
      direction = 1;
      break;
    } else{
      direction = -1;
    }

    if((i + 1) == maxNumbers && originalValue != 1){
      i = 1;
      maxNumbers = originalValue - 1;
    }
  }

  if(newYPos == currentYPos && newXPos == currentXPos){
    if(
      (newXPos - 1) > 0
      ){
      newXPos--;
    } else if(
      (newXPos - 1) < 0 &&
      (newYPos - 1) >= 0
      ){
      newXPos = SUDOKU_FIELDS_X_AXIS - 1;
      newYPos--;
    } else if(
      (newXPos - 1) == 0 &&
      (newYPos - 1) == 0
      ){
      newYPos = SUDOKU_FIELDS_Y_AXIS - 1;
      newXPos = SUDOKU_FIELDS_X_AXIS - 1;
    }
  }
  printf("end %i %i \n", newXPos, newYPos);

  printField(sudokuFields);
  system("pause");
  if(validateSudoku(sudokuFields) == 0){
    solveSudoku(direction, newXPos, newYPos, sudokuFields);
  }
}