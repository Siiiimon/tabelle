#include "modify.h"

/*
    setzt den wert einer Zelle
*/
void setCell(Table *t, int row, int col, Cell *c) {
    if (row >= t->height || row < 0 || col >= t->width || col < 0) {
        printf("invalider index\n");
    }

    // existierende Zelle freigeben
    Cell *tempcell = t->table[row * t->width + col];
    if (tempcell->kind == str) {
        free(tempcell->data.str);
    }
    free(tempcell);

    // neue Zelle setzen
    t->table[row * t->width + col] = c;
}

// todo: add to calc.c
/*
    summiert alle werte einer spalte (ignoriert strings)
    gibt einen pointer zurück. Falls ein Fehler aufgetreten ist wird NULL zurückgegen.
    Somit kann einfacher zwischen Fehler und validem Ergebnis unterschieden werden.
*/
float *sumColumn(Table *t, int col) {
    if (col >= t->width || col < 0) {
        printf("invalide spaltennummer\n");
        return NULL;
    }

    float sum = 0;
    for (int y = 0; y < t->height; ++y) {
        Cell *value = t->table[y * t->width + col];
        switch (value->kind) {
            case l:
                sum += (float) value->data.l;
                break;
            case f:
                sum += value->data.f;
                break;
            case str:
                break;
        }
    }
    return &sum;
}