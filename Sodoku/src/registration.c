#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "../UserRegistration/sqlite3.h"
#define DATABASE_FILE "sodoku_gruppe_a.db"

int testIfUserNameExists(char *cName);
void insertNewUser(char *cName, char *cPasswort);


int main() {
    char cName[] ="hallowelt";
    char cPasswort[] ="1223333";
    int iTestUserExisting;

    iTestUserExisting=testIfUserNameExists(cName);

    if(iTestUserExisting==0) {
        insertNewUser(cName, cPasswort);
    }else if(iTestUserExisting == 1){

        // TODO timo neue namens eingabe + fehlermeldung
    }
    system("PAUSE");

    return 0;
}

void insertNewUser(char *cName, char *cPasswort){
    char *sql; sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;

    rc = sqlite3_open_v2(DATABASE_FILE, &db_handle, SQLITE_OPEN_READWRITE,
                         NULL);

    sql = sqlite3_mprintf("insert into accounts (username, passwort) values "\
                                  "('%s', '%s');",  cName, cPasswort);

    rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);


}

int testIfUserNameExists(char *cName){

    sqlite3_stmt *stmt;
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql;
    int cols, i;
    int iDoesUserExist=0;

    sql = sqlite3_mprintf( "select id from accounts where username='%s';", cName);
    rc = sqlite3_open_v2(DATABASE_FILE, &db_handle, SQLITE_OPEN_READWRITE,
                         NULL);

    sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    cols =  sqlite3_column_count(stmt);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        iDoesUserExist++;
    }

    return iDoesUserExist==1 ? 1 : 0;
}
