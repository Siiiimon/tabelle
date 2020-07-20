#include "printCommand.h"

/*
    verarbeitet Nutzereingabe für den 'zeige' Kommando
*/
void commandPrint(Table *t, char *in) {
    char *token = strsep(&in, " ");
    if (token == NULL) {
        printTable(t);
    } else if (strncmp(token, "zeile", 5) == 0) {
        token = strsep(&in, " ");
        if (token == NULL) {
            printf("keine index angabe gefunden\n");
            return;
        }
        int row = atoi(token);
        printRow(t, row);
    } else if (strncmp(token, "spalte", 6) == 0) {
        token = strsep(&in, " ");
        if (token == NULL) {
            printf("keine index angabe gefunden\n");
            return;
        }
        int col = atoi(token);
        printColumn(t, col);
    } else if (strncmp(token, "zelle", 5) == 0) {
        token = strsep(&in, " ");
        if (token == NULL) {
            printf("keine index angabe gefunden\n");
            return;
        }
        int row = atoi(token);
        token = strsep(&in, " ");
        if (token == NULL) {
            printf("keine index angabe gefunden\n");
            return;
        }
        int col = atoi(token);
        printCell(t, row, col);
    } else if (strncmp(token, "info", 4) == 0) {
        printInfo(t);
    } else {
        printf("falsches argument für 'zeige'\n");
        return;
    }
}