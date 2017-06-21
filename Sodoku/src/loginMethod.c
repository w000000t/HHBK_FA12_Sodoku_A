#include <stdio.h>
#include <string.h>
#include <mem.h>
#include <stdlib.h>
#include "../Sudoku/sqlite3.h"
#define DATABASE_FILE "sodoku_gruppe_a.sqlite3"


int iGlobalUserId;

void databaseCall(char *sQuery);
static int callbackLogin(void *data,
                         int argc,
                         char **argv,
                         char **colName);
int loginUser(char *cName, char *cPassword);


int main() {

    //Test für loginUser Method
    char *sql;
    char name[] = "nick";
    char passwort[] ="123132";

    loginUser(name, passwort);

    printf("globaleId:  %d", iGlobalUserId);
    return 0;
}

int loginUser(char *cName, char *cPassword){
    char *sql;


    sql= sqlite3_mprintf( "select id from accounts where username='%s' and "
                                  "passwort='%s';", cName, cPassword );

    databaseCall(sql);
    return 0;
}

void databaseCall(char *sQuery){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    rc = sqlite3_open(DATABASE_FILE, &db_handle);

    rc = sqlite3_exec(db_handle, sql, callbackLogin, (void *) NULL,
                      &zErrMsg);

    if ( rc != SQLITE_OK){
        printf("SQL Fehler: %s \n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    if  ( rc != SQLITE_OK){
        sqlite3_close( db_handle);
    }
}


int callbackLogin(void *data, int argc, char **argv,
                         char **colName) {
    int  i;

    for( i=0; i<argc; i++) {
        if (strcmp("id", (const char *) colName[i]) == 0) {
            int userId = atoi(argv[i]);
            iGlobalUserId = userId;
        }

        return 0;
    }
}