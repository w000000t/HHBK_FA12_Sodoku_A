#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "../UserRegistration/sqlite3.h"
#define DATABASE_FILE "sodoku_gruppe_a.db"

int iIsUserId=0;


void databaseCall(char *sQuery, int iUseCase);
int callbackRegistration(void *data,
                         int argc,
                         char **argv,
                         char **colName);
int testIfUserNameExists(char *cName);
void insertNewUser(char *cName, char *cPasswort);


int main() {
    char cName[] ="aoiöhfoashads";
    char cPasswort[] ="12233";
    int iTestUserExisting;

    iTestUserExisting=testIfUserNameExists(cName);

    if(iTestUserExisting==0) {
        insertNewUser(cName, cPasswort);
    }else if(iTestUserExisting == 1){

        printf("helalsdjjasüpd");
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

    printf("\n%d\n", rc);

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


void databaseCall(char *sQuery, int iUseCase){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    rc = sqlite3_open_v2(DATABASE_FILE, &db_handle, SQLITE_OPEN_READWRITE,
            NULL);
    printf("in database\n");

/*
    if (iUseCase==0){
*/
    rc = sqlite3_exec(db_handle, sql, callbackRegistration, (void *) NULL,
                          &zErrMsg);
   /* } else if(iUseCase==1) {
        printf("in Usecase 1");
        rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);

    }*/

    printf("\n%d\n", rc);
    if (rc == 0){
        printf("\nnope\n");
    }


    if ( rc != SQLITE_OK){
        printf("SQL Fehler: %s \n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    if  ( rc != SQLITE_OK){
        sqlite3_close( db_handle);
    }
}

int callbackRegistration(void *data, int argc, char **argv,
                         char **colName){
    int i;
    printf("hello there in callbackRegistation\n");

    for( i=0; i <argc; i++) {

        if (strcmp("id", (const char *) colName[i]) == 0) {

            printf("%d", atoi(argv[i]));
            if(argv[i] == '\0'){
                printf("hello empty string\n");
            }
        }
    }
    return 0;
}