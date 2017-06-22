#include "../inc/login.h"

int loginUser(char *cName, char *cPassword){
    char *sql;


    sql= sqlite3_mprintf( "select id from accounts where username='%s' and "
                                  "passwort='%s';", cName, cPassword );

    databaseCallLogin(sql);
    return 0;
}

void databaseCallLogin(char *sQuery){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    rc = sqlite3_open(DB_FILE, &db_handle);

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
            iUserId = atoi(argv[i]);
        }

        return 0;
    }
}