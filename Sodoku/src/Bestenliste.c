#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "../Sudoku/sqlite3.h"
#define DATABASE_FILE "sodoku_gruppe_a.sqlite3"


void databaseCall(char *sQuery);
static int callbackBestenliste(void *data, int argc, char **argv,
                               char **colName);
void showHighscore();
void quadWhiteSpace();
void getHighscoreTable();
void checkIfColIsPoint(char *const *argv, char *const *colName, int i);
void checkIfColIsName(char *const *argv, char *const *colName, int i) ;

int main() {

    getHighscoreTable();

    system("PAUSE");
    return 0;
}

void getHighscoreTable() {

    showHighscore();
    char sQuery[]= "select games.punkte, accounts.username as name \n"
            "\tfrom games inner join accounts on games.user_id=accounts.id \n"
            "\torder by games.punkte desc;;";

    databaseCall(sQuery);
}

void lineBreaks(){
    printf("\n\n");
}

void showHighscore(){
    lineBreaks();
    quadWhiteSpace();
    quadWhiteSpace();
    printf("Bestenliste\n");
    lineBreaks();
    quadWhiteSpace();
    printf("Platz");
    printf("\t\t\t");
    printf("Punkte");
    printf("\t\t\t");
    printf("Name");
    lineBreaks();

}
void databaseCall(char *sQuery){
    sqlite3 *db_handle;
    int     rc;
    char *zErrMsg;
    const char *sql=sQuery;

    rc = sqlite3_open(DATABASE_FILE, &db_handle);

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

void quadWhiteSpace()
{
    printf("\t\t\t\t");
}
