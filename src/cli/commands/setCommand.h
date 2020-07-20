#ifndef TABELLE_SETCOMMAND_H
#define TABELLE_SETCOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../table/types.h"
#include "../../table/modify.h"
#include "../../table/parse.h"
#include "../cli.h" // todo: do we need this??

void commandSet(Table *t, char *in);

#endif //TABELLE_SETCOMMAND_H
