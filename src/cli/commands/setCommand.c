#include "setCommand.h"

void commandSet(Table *t, char *in) {
    // Indexangabe einlesen
    char *token = strsep(&in, " ");
    if (token == NULL) {
        printf("keine Indexangabe gefunden\n");
        return;
    }
    int row = atoi(token);
    token = strsep(&in, " ");
    if (token == NULL) {
        printf("keine Indexangabe gefunden\n");
        return;
    }
    int col = atoi(token);

    if (row >= t->height || row < 0 || col >= t->width || col < 0) {
        printf("invalider index\n");
        return;
    }

    // nach Zeileninhalt fragen
    printf("zelle[%d][%d] ausgewählt, bitte zeilen inhalt eingeben (ENTER zum abbrechen)\n> ", row, col);
    char buf[1024];
    char *setin = fgets(buf, 1024, stdin);
    if (setin == NULL || *setin == '\n') {
        printf("Abbruch\n");
        free(setin);
        return;
    }
    Cell *setcell = parseCell(setin);
    setCell(t, row, col, setcell);
}
