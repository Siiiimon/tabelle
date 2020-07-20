#ifndef TABELLE_SORT_H
#define TABELLE_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

int swapRow(Table *t, int xrow, int yrow);
int compareCell(struct Cell *xCell, struct Cell *yCell);
void bubbleSort(Table *t, int col);

#endif //TABELLE_SORT_H
