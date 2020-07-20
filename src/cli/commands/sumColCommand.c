#include "sumColCommand.h"

/*
    verarbeitet Nutzereingabe für den 'summiere' Kommando
*/
void commandSumCol(Table *t, char *in) {
    // Spaltenindex einlesen
    float sum;
    char *token = strsep(&in, " ");
    if (token == NULL) {
        printf("unbekannte Eingabe, fehlerhafte Spaltenangabe\n");
        return;
    }
    int col = atoi(token);
    if (sumColumn(t, col, &sum) > 0) {
        printf("Fehler bei Summierung der Spalte %d\n", col);
    } else {
        printf("Summe der Spalte %d: %f\n", col, sum);
    }
}
