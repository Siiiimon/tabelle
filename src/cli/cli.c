#include "cli.h"

/*
    verarbeitet Nutzerinput
 */
int handleUserInput(Table *t, char *in) {
    if (in == NULL || strncmp(in, "ende", 4) == 0) {
        return 1;
    } else {
        char *token = strtok(in, " ");
        if (strncmp(token, "zeige", 5) == 0) {
            commandPrint(t, in);
        } else if (strncmp(token, "setze", 5) == 0) {
            commandSet(t, in);
        } else if (strncmp(token, "speicher", 8) == 0) {
            commandSave(t, in);
        } else if (strncmp(token, "summiere", 8) == 0) {
            commandSumCol(t, in);
        } else if (strncmp(token, "sortiere", 8) == 0) {
            commandSort(t, in);
        } else {
            printf("unbekannte eingabe\n");
        }
    }
    return 0;
}
