#include "../inc/registration.h"

void insertNewUser(char *cName, char *cPasswort){
    char *sql; sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;

    rc = sqlite3_open_v2(DB_FILE, &db_handle, SQLITE_OPEN_READWRITE,
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

    sql = sqlite3_mprintf("select id from accounts where username='%s';", cName);
    rc = sqlite3_open_v2(DB_FILE, &db_handle, SQLITE_OPEN_READWRITE,
                         NULL);

    sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        iDoesUserExist++;
    }

    return iDoesUserExist==1 ? 1 : 0;
}
