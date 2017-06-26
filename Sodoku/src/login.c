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
#include "../inc/login.h"
/*
 * =============================================================================
 *  loginUser
 *  Parameter: char *cName, char *cPassword
 *  Rückgabewert: 0
 *  Beschreibung: Bauen der Select-Query auf Basis von Übergabeparametern und
 *  aufruf der databaseCallLogin-Methode.
 *  ============================================================================
 */
int loginUser(char *cName, char *cPassword){
    char *sql;

    //Bauen der Select-Query auf Basis von Übergabeparametern
    sql= sqlite3_mprintf( "select id from accounts where username='%s' and "
                                  "passwort='%s';", cName, cPassword );
    databaseCallLogin(sql);
    return 0;
}
/*
 * =============================================================================
 *  databaseCallLogin
 *  Parameter: char *sQuery
 *  Rückgabewert: -
 *  Beschreibung: Öffnen der Datenbank und ausführen der übergebenen Query
 *  ============================================================================
 */
void databaseCallLogin(char *sQuery){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    //Öffnen der Datenbank
    rc = sqlite3_open(DB_FILE, &db_handle);

    //Ausführen der übergebenen Query auf Datenbank mittels
    // callbackLogin-Funktion
    rc = sqlite3_exec(db_handle, sql, callbackLogin, (void *) NULL,
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
 *  callbackLogin
 *  Parameter: void *data, int argc, char **argv, char **colName
 *  Rückgabewert: 0
 *  Beschreibung: Callback Funktion zur Zuweisung einer Datenbank ID auf
 *  globale iUserId
 *  ============================================================================
 */
int callbackLogin(void *data, int argc, char **argv,
                         char **colName) {
    int  i;

    for( i=0; i<argc; i++) {
        //Prüfung ob Spaltenname id
        if (strcmp("id", (const char *) colName[i]) == 0) {
            //Char zu Int umwandlung und Zuweisung auf globale iUserId
            iUserId = atoi(argv[i]);
        }
        return 0;
    }
}