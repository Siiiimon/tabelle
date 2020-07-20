#ifndef TABELLE_CLI_H
#define TABELLE_CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../table/print.h"
#include "../table/parse.h"
#include "../table/modify.h"
#include "commands/printCommand.h"
#include "commands/setCommand.h"
#include "commands/saveCommand.h"
#include "commands/sumColCommand.h"
#include "commands/sortCommand.h"

int handleUserInput(Table *t, char* in);

#endif //TABELLE_CLI_H
