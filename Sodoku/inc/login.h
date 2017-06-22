#ifndef __LOGIN__
#define __LOGIN__
#include "Utils.h"
#include "globals.h"

void databaseCallLogin(char *sQuery);
static int callbackLogin(void *data,
                         int argc,
                         char **argv,
                         char **colName);
int loginUser(char *cName, char *cPassword);
#endif