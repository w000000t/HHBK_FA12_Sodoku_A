#include "../inc/highscore.h"

void getHighscoreTable() {
    char sQuery[] = "select games.punkte, accounts.username as name "\
            "from games inner join accounts on games.user_id=accounts.id "\
            "order by games.punkte desc;";

    showHighscore();
    databaseCallHighscore(sQuery);
}

void databaseCallHighscore(char *sQuery){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    rc = sqlite3_open(DB_FILE, &db_handle);

    rc = sqlite3_exec(db_handle, sql, callbackBestenliste, (void *) NULL,
                      &zErrMsg);

    if ( rc != SQLITE_OK){
        printf("SQL Fehler: %s \n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    if  ( rc != SQLITE_OK){
        sqlite3_close( db_handle);
    }
}


static int callbackBestenliste(void *data, int argc, char **argv,
                               char **colName) {
    int  i;

    for( i=0; i<argc; i++){
        checkIfColIsPoint(argv, colName, i);
        checkIfColIsName(argv, colName, i);
    }
    printf("\n");
    return 0;
}

void checkIfColIsPoint(char *const *argv, char *const *colName, int i) {
    if(strcmp(colName[i], "name")){
        quadWhiteSpace();
        quadWhiteSpace();
        printf("%s",argv[i]);
    }
}
void checkIfColIsName(char *const *argv, char *const *colName, int i) {
    if(strcmp(colName[i], "punkte")){
        printf("\t\t\t");
            printf("%s",argv[i]);
        }
}
