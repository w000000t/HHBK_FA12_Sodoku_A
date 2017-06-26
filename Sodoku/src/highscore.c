/*
================================================================================
 Autoren: Joel Kamps
 Klasse: FA12
 Programmname: Sudoku
 Datum: 26.06.2017
 Beschreibung: Login eines Users mittels Username und Passwort
 Version: 1.0
 Compiler: CMake
 ===============================================================================
 */
#include "../inc/highscore.h"

/*
 * =============================================================================
 *  Parameter: -
 *  Rückgabewert: -
 *  Beschreibung: Zusammenbau einer Select-Query und aufruf der ShowHighscore
 *  und databaseCallHighscore Methode
 *  ============================================================================
 */
void getHighscoreTable() {
    char sQuery[] = "select games.punkte, accounts.username as name "\
            "from games inner join accounts on games.user_id=accounts.id "\
            "order by games.punkte desc;";

    showHighscore();
    databaseCallHighscore(sQuery);
}

/*
 * =============================================================================
 *  Parameter: char *sQuery
 *  Rückgabewert: -
 *  Beschreibung: Ausfüren eines DatenbankCalls mittels übergeber Query unter
 *  Zuhilfe nahme einer Callback-Funktion
 *  ============================================================================
 */
void databaseCallHighscore(char *sQuery){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    //Öffnen der Datenbank
    rc = sqlite3_open(DB_FILE, &db_handle);

    //Ausführen der übegebenen Query auf geöffnete Datenbank mittels
    // Callback-Funktion
    rc = sqlite3_exec(db_handle, sql, callbackBestenliste, (void *) NULL,
                      &zErrMsg);

    //Validierung ob es zu Fehlern bei der SQL-Operation gab
    if ( rc != SQLITE_OK){
        printf("SQL Fehler: %s \n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    //Schließen der Datenbank bei Fehlern auf der Datenbank
    if  ( rc != SQLITE_OK){
        sqlite3_close( db_handle);
    }
}

/*
 * =============================================================================
 *  Parameter: void *data, int argc, char **argv, char **colName
 *  Rückgabewert: 0
 *  Beschreibung: Callback-Funktion für Bestenlisten Darstellung
 *  ============================================================================
 */
static int callbackBestenliste(void *data, int argc, char **argv,
                               char **colName) {
    int  i;

    //Für jede zurückgegebene Zeile Prüfung ob die Spalte Name oder Punkte ist.
    for( i=0; i<argc; i++){
        checkIfColIsPoint(argv, colName, i);
        checkIfColIsName(argv, colName, i);
    }
    printf("\n");
    return 0;
}

/*
 * =============================================================================
 *  Parameter: char *const *argv, char *const *colName, int i
 *  Rückgabewert: 0
 *  Beschreibung: Prüfung ob Spaltenname "name" ist. Und formatierte Ausgabe.
 *  ============================================================================
 */
void checkIfColIsPoint(char *const *argv, char *const *colName, int i) {
    if(strcmp(colName[i], "name")){
        quadWhiteSpace();
        quadWhiteSpace();
        printf("%s",argv[i]);
    }
}
/*
 * =============================================================================
 *  Parameter: char *const *argv, char *const *colName, int i
 *  Rückgabewert: 0
 *  Beschreibung: Prüfung ob Spaltenname "punkte" ist. Und formatierte Ausgabe.
 *  ============================================================================
 */
void checkIfColIsName(char *const *argv, char *const *colName, int i) {
    if(strcmp(colName[i], "punkte")){
        printf("\t\t\t");
            printf("%s",argv[i]);
    }
}
