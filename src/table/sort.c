#include "sort.h"

/*
    tauscht Zwei Zeilen miteinander
*/
int swapRow(Table *t, int xrow, int yrow) {
    if (xrow >= t->height || xrow < 0 || yrow >= t->height || yrow < 0) {
        return 1;
    }

    for (int i = 0; i < t->width; ++i) {
        Cell *temp = t->table[xrow * t->width + i];
        t->table[xrow * t->width + i] = t->table[yrow * t->width + i];
        t->table[yrow * t->width + i] = temp;
    }
    return 0;
}

/*
    vergleicht Zwei Zellen (vom gleichen Datentyp) miteinander
*/
int compareCell(struct Cell *xCell, struct Cell *yCell) {
    switch (xCell->kind) {
        case l:
            if (yCell->kind == l) {
                return (int) (xCell->data.l - yCell->data.l);
            } else if (yCell->kind == f) {
                return (int) ((float) xCell->data.l - yCell->data.f);
            }
        case f:
            if (yCell->kind == f) {
                return (int) (xCell->data.f - yCell->data.f);
            } else if (yCell->kind == l) {
                return (int) (xCell->data.f - (float) yCell->data.l);
            }
        case str:
            if (yCell->kind == str) {
                return strcmp(xCell->data.str, yCell->data.str);
            }
        default:
            printf("kann keine verschiedenen Datentypen in einer Spalte sortieren, die Sortierung wird fehlerhaft sein.\n");
            return 0;
    }
}

/*
    BubbleSort Implementation
*/
void bubbleSort(Table *t, int col) {
    if (col >= t->width || col < 0) {
        printf("invalide Spaltenindex Angabe\n");
        return;
    }

    for (int i = 0; i < t->height - 1; ++i) {
        for (int j = 0; j < t->height - i - 1; ++j) {
            Cell *x = t->table[j * t->width + col];
            Cell *y = t->table[(j + 1) * t->width + col];
            int val = compareCell(x, y) > 0;
            if (val > 0) {
                swapRow(t, j, j+1);
            }
        }
    }
}