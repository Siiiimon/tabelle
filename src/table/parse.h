#ifndef TABELLE_PARSE_H
#define TABELLE_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

Cell *parseCell(char *token);
Table *parseTable(char *path, int rows, int cols);

void freeTable(Table *t);

#endif //TABELLE_PARSE_H
