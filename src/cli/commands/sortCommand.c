#include "sortCommand.h"

void commandSort(Table *t, char *in) {
    char *token = strsep(&in, " ");
    if (token == NULL) {
        printf("keine Indexangabe gefunden\n");
        return;
    }
    int row = atoi(token);

    bubbleSort(t, row);
}