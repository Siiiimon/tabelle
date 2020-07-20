#ifndef TABELLE_FILE_H
#define TABELLE_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table/types.h"

int _countCols(char *source, char delim);
int countRowsAndColumns(char *path, int *rows, int *cols);
int saveFile(Table *t, char *path);

#endif //TABELLE_FILE_H
