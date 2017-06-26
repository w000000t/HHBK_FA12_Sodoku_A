/*
================================================================================
 Autoren: Joel Kamps
 Klasse: FA12
 Programmname: Sudoku
 Datum: 26.06.2017
 Beschreibung: Prüfung auf existens eines Usernamens in der DB und einfügen
 in DB
 Version: 1.0
 Compiler: CMake
 ===============================================================================
 */
#include "../inc/registration.h"
/*
 * =============================================================================
 *  insertNewUser
 *  Parameter: char *cName, char *cPasswort
 *  Rückgabewert: -
 *  Beschreibung:  Einfügen von Username und Passwort in Datenbank
 *  ============================================================================
 */
void insertNewUser(char *cName, char *cPasswort){
    char *sql; sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;

    //offen der Datenbank
    rc = sqlite3_open_v2(DB_FILE, &db_handle, SQLITE_OPEN_READWRITE,
                         NULL);
    //Zusammenbauen der Insert-Query
    sql = sqlite3_mprintf("insert into accounts (username, passwort) values "\
                                  "('%s', '%s');",  cName, cPasswort);
    //Ausführen der Query auf die geöffnete Datenbank
    rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
}

/*
 * =============================================================================
 *  testIfUserNameExists
 *  Parameter: char *cName
 *  Rückgabewert: int iDoesUserExist
 *  Beschreibung: Testen ob das übergebene char-Array in der Datenbank
 *  vorhanden ist. iDoesUserExist dient als pseudo-boolean für denn fall,
 *  dass cName vorhanden ist.
 *  ============================================================================
 */
int testIfUserNameExists(char *cName){
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql;
    int cols, i;
    int iDoesUserExist=0;

    //Zusammenbauen des Select-Query
    sql = sqlite3_mprintf("select id from accounts where username='%s';", cName);
    //öffnen der Datenbank
    rc = sqlite3_open_v2(DB_FILE, &db_handle, SQLITE_OPEN_READWRITE,
                         NULL);
    //Ausführen der Query auf die Datenbank
    sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    //Iteration über die Rückgabestatements
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        //Sollte es eine Rückgabe geben wird iDoesUserExist auf 1 gesetzt
        iDoesUserExist++;
    }

    return iDoesUserExist==1 ? 1 : 0;
}
