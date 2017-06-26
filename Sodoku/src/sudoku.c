/*
================================================================================
Autoren: Simon Marx
Klasse: FA12
Programmname: Sudoku
Datum: 23.06.2017
Beschreibung: Die Datei enthält alle nötigen Funktionen zum Umgang mit dem
              Sudoku. Funktionen zur Validierung, Initialisierung, Lösung eines
              Sudokus und der Hilfe zum Sudoku werden bereitgestellt.
Version: 0.2
Compiler: Visual Studio 2017
===============================================================================
*/
#include "../inc/sudoku.h"
/*
* =============================================================================
*  initSudoku
*  Parameter: sudoku_field 
*               sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*             int iWithSolution Gibt an, ob das Spielfeld aufgelöst werden soll
*  Rückgabewert: -
*  Beschreibung: Die Funktion lädt eines der in der Datenbank gespeicherten
*				 Spiele mit dem gewünschten Schwierigkeitsgrad und füllt
*				 die Spieldaten in das Array.
*  ============================================================================
*/
void initSudoku(
	sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS],
  int iWithSolution
)
{
	int iXAXIS = 0,
		  iYAXIS = 0,
		  iRc, // return code für verschiedene Funktionen => Überprüfen auf Fehler
		  iCols,
		  iColsCounter, 
		  iColNrXCord, 
		  iColNrYCord, 
		  iColNrValue;
	sqlite3 *db;
	sqlite3_stmt *stmt;

	// sql statement
	char cSqlGamePresetTemplate[] = "SELECT "\
								"spf.x_cordinate as x_cord,"\
								"spf.y_cordinate as y_cord,"\
								"spf.value as value "\
							"FROM sudoku_preset_fields spf "\
							"INNER JOIN sudoku_preset_games spg"\
							" ON spg.id = spf.preset_id "\
							"WHERE spg.id = ("\
							"	SELECT "\
							"		sspg.id "\
							"	FROM sudoku_preset_games sspg "\
							"	WHERE sspg.difficulty = %i "\
							"	ORDER BY (abs(random())) "\
							"	LIMIT 1 "\
							") AND is_solution = %i";

	char *cSqlGamePreset;

	cSqlGamePreset = sqlite3_mprintf(cSqlGamePresetTemplate, iDifficulty, iWithSolution);
  printf("%s", cSqlGamePreset);
	// initialisieren des kompletten arrays mit 0
	for(iXAXIS = 0; iXAXIS < SUDOKU_FIELDS_X_AXIS; iXAXIS++){
		for(iYAXIS = 0; iYAXIS < SUDOKU_FIELDS_Y_AXIS; iYAXIS++){
			// ist der Wert disabled auf 1 gesetzt kann dieses Feld
			// nicht editiert werden
			sudokuFields[iXAXIS][iYAXIS].disabled = 0;
			// Ein Feld "ohne" Wert bekommt den Wert 0
			sudokuFields[iXAXIS][iYAXIS].value = 0;
		}
	}

	// Verbindung zur Datenbank aufbauen
	iRc = sqlite3_open_v2(DB_FILE, &db, SQLITE_OPEN_READWRITE, NULL);

	if(iRc != SQLITE_OK){
		printf("Sudoku initialization failed due to a missing database connection.");
		system("pause");
		exit(-1);
	}

	// Ein Spiel aus der Datenbank laden
	iRc = sqlite3_prepare_v2(
    db, 
    cSqlGamePreset, 
    strlen(cSqlGamePreset),
    &stmt, 
    NULL
  );

	if(iRc != SQLITE_OK){
		printf("Failed to load the game preset. Error code: %i", iRc);
		system("pause");
		exit(-1);
	}

	iCols = sqlite3_column_count(stmt); // anzahl der Spalten

	// alle Datensätze durchlaufen
	while(sqlite3_step(stmt) == SQLITE_ROW){
		// alle Spalten/pro Datensatz durchlaufen
		for(iColsCounter = 0; iColsCounter < iCols; iColsCounter++){
			// zuordnen der Werte aus der Datenbank
			if(
        strcmp(
          (const char*)sqlite3_column_name(stmt, iColsCounter),
          "x_cord"
        ) == 0
      ){
        // x Kordinate des aktuellen Felds
				iColNrXCord = sqlite3_column_int(stmt, iColsCounter);
			}

			if(
        strcmp(
          (const char*)sqlite3_column_name(stmt, iColsCounter),
          "y_cord"
        ) == 0
      ){
        // y Kordinate des aktuellen Felds
				iColNrYCord = sqlite3_column_int(stmt, iColsCounter);
			}

			if(
        strcmp(
          (const char*)sqlite3_column_name(stmt, iColsCounter),
          "value"
        ) == 0
      ){
        // Wert des aktuellen Felds
				iColNrValue = sqlite3_column_int(stmt, iColsCounter);
			}
		}
		// Sudokufeld befüllen
    sudokuFields[iColNrXCord][iColNrYCord].disabled = 1;
		sudokuFields[iColNrXCord][iColNrYCord].value = iColNrValue;
	}

	sqlite3_finalize(stmt);
}

/*
* =============================================================================
*  validateSudoku
*  Parameter: sudoku_field 
*     				sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*  Rückgabewert: int Gibt 1 zurück, wenn das Sudoku komplett valide ist und
*                    alle Regeln befolgt wurden, 0 wenn nicht.
*  Beschreibung: Die Funktion überprüft alle Zeilen und Spalten sowie, ob alle
*                Felder gesetzt sind. Sollten alle Zeile und Spalten valide und
*                alle Felder ausgefüllt sein, liefert die Funktion SUDOKU_TRUE
*                zurück, sollten nicht alle Felder valide sein, liefert die
*                Funktion SUDOKU_FALSE zurück.
*  ============================================================================
*/
int validateSudoku(
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
){
  int iRowsValid = SUDOKU_FALSE,
      iBoxesValid = SUDOKU_FALSE,
      iAllFieldsUsed = SUDOKU_FALSE;

  iRowsValid = validateRows(sudokuFields);
  iBoxesValid = validateFields(sudokuFields);
  iAllFieldsUsed = areAllFieldsFilledOut(sudokuFields);

  return iRowsValid == SUDOKU_TRUE &&
         iBoxesValid == SUDOKU_TRUE &&
         iAllFieldsUsed == SUDOKU_TRUE 
         ? SUDOKU_TRUE : SUDOKU_FALSE;
}

/*
* =============================================================================
*  areAllFieldsFilledOut
*  Parameter: sudoku_field 
*     				sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*  Rückgabewert: int SUDOKU_TRUE wenn alle Felder ausgefüllt sind/
*                    SUDOKU_FALSE wenn NICHT alle Felder ausgefüllt sind
*  Beschreibung: Die Funktion überprüft, ob alle Felder im Sudoku gesetzt sind
*  ============================================================================
*/
int areAllFieldsFilledOut(
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
){
  int i, j;

  for (i = 0; i < SUDOKU_FIELDS_X_AXIS; i++) {
    for (j = 0; j < SUDOKU_FIELDS_Y_AXIS; j++) {
      if (sudokuFields[i][j].value == 0) {
        return SUDOKU_FALSE;
      }
    }
  }
  return SUDOKU_TRUE;
}

/*
* =============================================================================
*  validateRow
*  Parameter: int iRowXIndex Der X Index, dessen Zeile/Spalte überprüft werden
*                            soll.
*             int iRowYIndex Der Y Index, dessen Zeile/Speile überprüft werden
*                            soll.
*             sudoku_field 
*     				sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*  Rückgabewert: int Gibt entweder SUDOKU_TRUE zurück wenn Zeile und Spalte
*                    der übergebenen Koordinaten valide sind. Gibt SUDOKU_FALSE
*                    zurück, wenn Zeile und Spalte nicht valide sind.
*  Beschreibung: Die Funktion überprüft, ob die Zahl an den angegebenen
*                Koordinaten in der Zeile und der Spalte bereits existieren und
*                gibt den entsprechenden Rückgabewert zurück.
*  ============================================================================
*/
int validateRow(
  int rowXIndex,
  int rowYIndex, 
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
){
  int existingValuesVertical[SUDOKU_FIELDS_X_AXIS];
  int existingValuesHorizontal[SUDOKU_FIELDS_Y_AXIS];
  int iCol, currentValue, valueIndex;

  // init help arrays
  initExistingValuesArrays(existingValuesVertical, SUDOKU_FIELDS_X_AXIS);
  initExistingValuesArrays(existingValuesHorizontal, SUDOKU_FIELDS_Y_AXIS);

  for (iCol = 0; iCol < SUDOKU_FIELDS_X_AXIS; iCol++) {
    currentValue = sudokuFields[rowXIndex][iCol].value;

    if (currentValue == 0) continue;

    valueIndex = currentValue - 1;
    if (existingValuesVertical[valueIndex] == 1) {
      return SUDOKU_FALSE;
    }
    else {
      existingValuesVertical[valueIndex] = 1;
    }
  }
  // horizontal check
  for (iCol = 0; iCol < SUDOKU_FIELDS_Y_AXIS; iCol++) {
    currentValue = sudokuFields[iCol][rowYIndex].value;

    if (currentValue == 0) continue;

    valueIndex = currentValue - 1;
    if (existingValuesHorizontal[valueIndex] == 1) {
      return SUDOKU_FALSE;
    }
    else {
      existingValuesHorizontal[valueIndex] = 1;
    }
  }
  return SUDOKU_TRUE;
}

/*
* =============================================================================
*  validateRows
*  Parameter: sudoku_field 
*     				sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*  Rückgabewert: int SUDOKU_TRUE, wenn alle Zeilen und Spalten des Sudokus
*                    valide sind. SUDOKU_FALSE, wenn nicht alle Zeilen und
*                    Spalten valide sind.
*  Beschreibung: Die Funktion überprüft alle Zeilen und Spalten des Sudokus
*                und gibt den entsprechenden Rückgabewert zurück.
*  ============================================================================
*/
int validateRows(
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
){
  int iX;

  for (iX = 0; iX < SUDOKU_FIELDS_X_AXIS; iX++) {
    if (validateRow(iX, iX, sudokuFields) == 0) {// diagonale
      return SUDOKU_FALSE;
    }
  }

  return SUDOKU_TRUE;
}

/*
* =============================================================================
*  validateField
*  Parameter: int iTopLeftXIndex Die Y-Position der linken oberen Ecke des 
*                                3x3 Felds.
*             int iTopLeftYIndex Die X-Position der linken oberen Ecke des
*                                3x3 Felds.
*             sudoku_field 
*     				sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*  Rückgabewert: int SUDOKU_TRUE, wenn die Zahl im angegebenen Feld nur einmal
                     existiert, SUDOKU_FALSE, wenn eine Zahl mehrmals existiert
*  Beschreibung: Die Funktion überprüft, ob eine Zahl mehrmals in dem
*                angegebenen Feld vorhanden ist und gibt den entsprechenenden
*                Rückgabewert zurück.
*  ============================================================================
*/
int validateField(
  int iTopLeftXIndex,
  int iTopLeftYIndex,
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
) 
{
  int iX, iY, existingValues[SUDOKU_FIELDS_X_AXIS], currentValue, valueIndex;

  initExistingValuesArrays(existingValues, SUDOKU_FIELDS_X_AXIS);

  for (iX = iTopLeftXIndex; iX < iTopLeftXIndex + 3; iX++) {
    for (iY = iTopLeftYIndex; iY < iTopLeftYIndex + 3; iY++) {
      currentValue = sudokuFields[iX][iY].value;

      if (currentValue == 0) continue;

      valueIndex = currentValue - 1;

      if (existingValues[valueIndex] == 1) {
        return SUDOKU_FALSE;
      }
      else {
        existingValues[valueIndex] = 1;
      }
    }
  }
  return SUDOKU_TRUE;
}

/*
* =============================================================================
*  validateFields
*  Parameter: sudoku_field 
*     				sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*  Rückgabewert: int Gibt SUDOKU_TRUE zurück, wenn alle 3x3 valide sind.
*                         SUDOKU_FALSE, wenn nicht.
*  Beschreibung: Die Funktion überprüft alle 3x3 Felder.
*  ============================================================================
*/
int validateFields(
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
) {
  int iX, iY;

  for (iX = 0; iX < SUDOKU_FIELDS_X_AXIS; iX += 3) {
    for (iY = 0; iY < SUDOKU_FIELDS_Y_AXIS; iY += 3) {
      if (validateField(iX, iY, sudokuFields) == 0) {
        return SUDOKU_FALSE;
      }
    }
  }
  return SUDOKU_TRUE;
}

/*
* =============================================================================
*  solveSudoku
*  Parameter: int xPos
*             int yPos
*             sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*             int iHasError Gibt an, ob das nächste Feld einen Error hat
*  Rückgabewert: -
*  Beschreibung: Die Funktion löst das Sudoku
*  ============================================================================
*/
void solveSudoku(
  int xPos,
  int yPos,
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS],
  int iHasError
)
{  
  if (USE_TEMP_SOLUTION_TO_SOLVE_SUDOKU == SUDOKU_TRUE) {
    initSudoku(sudokuFields, 1);
  }
  else {
    solveSudokuTemp(xPos, yPos, sudokuFields, iHasError);
  }
}

/*
* =============================================================================
*  solveSudokuTemp
*  Parameter: int xPos
*             int yPos
*             sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
*     				  Dieses zweidimensionale Array enthält alle Felder des Sudokus.
*             int iHasError Gibt an, ob das nächste Feld einen Error hat
*  Rückgabewert: Gibt 1 zurück, wenn das Sudoku gelöst werde konnte.
*                Gibt 0 zurück, wenn das SUdoku nicht gelöst werden konnte.
*  Beschreibung: Die Funktion löst das Sudoku *** NICHT FERTIG***
*                Die Zeit hat nicht gereicht, den Algorithmus richtig zu
*                implementieren.
*  ============================================================================
*/
int solveSudokuTemp(
  int xPos,
  int yPos,
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS],
  int iHasError
) {
  int i = 1, newXPos, newYPos, iMaxValue = 9, iOriginalValue;

  iOriginalValue = sudokuFields[xPos][yPos].value;

  // Sudoku gelöst
  if (yPos == 9) {
    return SUDOKU_TRUE;
  }

  // Anfang der Zeile => Ende der Zeile und eine Zeile hoch
  if (xPos == -1) {
    xPos = 8;
    yPos--;
  }

  // Ende der Zeile => Anfang der Zeile und eine Zeile runter
  if (xPos > 8) {
    xPos = 0;
    yPos++;
  }

  newXPos = xPos;
  newYPos = yPos;

  if (iHasError == SUDOKU_TRUE) {
    i = iOriginalValue;
  }

  // Feld kann bearbeitet werden // Alle anderen Felder sind fest eingetragen
  if (sudokuFields[xPos][yPos].disabled == SUDOKU_FALSE) {

    // alle Zahlen von 1 bis 9 durchgehen
    for (i = 1; i <= iMaxValue; i++) {
      if (iHasError == SUDOKU_TRUE && i == iOriginalValue) continue;

      // temporäre Zuweisung
      sudokuFields[xPos][yPos].value = i;
      printf("\n\n row: %i col: %i i: %i", validateRow(xPos, yPos, sudokuFields), validateField((xPos / 3) * 3, (yPos / 3) * 3, sudokuFields), i);
      // Wenn die Zahl valide ist => springe aus der Schleife und gehe ein Feld weiter
      if (
        validateRow(xPos, yPos, sudokuFields) == SUDOKU_TRUE
        && validateField((xPos / 3) * 3, (yPos / 3) * 3, sudokuFields) == SUDOKU_TRUE
        ) {
        break;
      }

      if (i == iMaxValue && iHasError == SUDOKU_TRUE) {
        i = 1;
        iMaxValue = iOriginalValue;
      }
      // Die Zahl ist nicht valide => zurücksetzen
      sudokuFields[xPos][yPos].value = 0;
    }

    // wenn keine valide Zahl gefunden wurde
    if (sudokuFields[xPos][yPos].value == 0) {
      // ein Feld zurück
      newXPos--;
      iHasError = 1;
    }
    else {
      newXPos++;
      iHasError = 0;
    }
  }
  // Feld ist default
  else {
    // Nächstes Feld konnte nicht befüllt werden dieses Feld ist default also weiter zurück
    if (iHasError == SUDOKU_TRUE) {
      newXPos--;
    }
    // default feld => darf nicht geändert werden => weiter
    else {
      newXPos++;
    }
  }
  printf("\n\n %i %i %i \n\n", xPos, yPos, iHasError);

  // rekursion wird beendet wenn das yPos = 9
  solveSudoku(newXPos, yPos, sudokuFields, iHasError);
}

void getPossibleNumbersForField(
  int xCord,
  int yCord,
  sudoku_field sudokuFields[SUDOKU_FIELDS_X_AXIS][SUDOKU_FIELDS_Y_AXIS]
) {
  int maxNumbers = 9, firstNumber = 1, i = 0, originalValue;
  originalValue = sudokuFields[xCord][yCord].value;

  for (i = 1; i <= maxNumbers; i++) {
    // skip the entered value
    if (originalValue == i) continue;

    // assign temporary value to the current field to check if its valid
    sudokuFields[xCord][yCord].value = i;

    // if the value is valid, expand the array for the possible numbers
    // and add the number to the array
    // =>continue with the next number
    if (
      validateRow(xCord, yCord, sudokuFields) == 1 &&
      validateField((xCord / 3) * 3, (yCord / 3) * 3, sudokuFields) == 1
      ) {
      if (firstNumber == 1) {
        printf("%i ", i);
        firstNumber = 0;
      }
      else {
        printf(", %i", i);
      }
    }
  }
  // reset the field to the original value
  sudokuFields[xCord][yCord].value = originalValue;
}