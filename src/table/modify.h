#ifndef TABELLE_MODIFY_H
#define TABELLE_MODIFY_H

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void setCell(Table *t, int row, int col, Cell *c);
float *sumColumn(Table *t, int col);

#endif //TABELLE_MODIFY_H