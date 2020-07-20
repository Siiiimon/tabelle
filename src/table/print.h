#ifndef TABELLE_PRINT_H
#define TABELLE_PRINT_H

#include <stdio.h>
#include "types.h"

void printTable(Table *t);
void printColumn(Table *t, int col);
void printRow(Table *t, int row);
void printCell(Table *t, int row, int col);
void printInfo(Table *t);

#endif //TABELLE_PRINT_H
