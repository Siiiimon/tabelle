#ifndef TABELLE_MODIFY_H
#define TABELLE_MODIFY_H

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void setCell(Table *t, int row, int col, Cell *c);
int sumColumn(Table *t, int col, float *sum);

#endif //TABELLE_MODIFY_H