#include "print.h"

/*
    gibt komplette Tabelle aus
*/
void printTable(Table *t) {
    for (int y = 0; y < t->height; ++y) {
        printf("|");
        for (int x = 0; x < t->width; ++x) {
            Cell *value = t->table[y * t->width + x];
            switch (value->kind) {
                case l:
                    printf(" %ld |", value->data.l);
                    break;
                case f:
                    printf(" %f |", value->data.f);
                    break;
                case str:
                    printf(" %s |", value->data.str);
            }
        }
        printf("\n");
    }
}

/*
    gibt Spalte aus der Tabelle aus
*/
void printColumn(Table *t, int col) {
    if (col >= t->width || col < 0) {
        printf("invalide spaltennummer\n");
        return;
    }

    for (int y = 0; y < t->height; ++y) {
        Cell *value = t->table[y * t->width + col];
        switch (value->kind) {
            case l:
                printf("| %ld |\n", value->data.l);
                break;
            case f:
                printf("| %f |\n", value->data.f);
                break;
            case str:
                printf("| %s |\n", value->data.str);
        }
    }
}

/*
    gibt Zeile aus der Tabelle aus
*/
void printRow(Table *t, int row) {
    if (row >= t->height || row < 0) {
        printf("invalide zeilennummer\n");
        return;
    }

    for (int i = 0; i < t->width; ++i) {
        Cell *value = t->table[row * t->width + i];
        printf("|");
        switch (value->kind) {
            case l:
                printf(" %ld |", value->data.l);
                break;
            case f:
                printf(" %f |", value->data.f);
                break;
            case str:
                printf(" %s |", value->data.str);
        }
    }
    printf("\n");
}

/*
    gibt Zelle aus der Tabelle aus
*/
void printCell(Table *t, int row, int col) {
    if (row >= t->height || row < 0 || col >= t->width || col < 0) {
        printf("invalider index\n");
    }
    Cell *value = t->table[row * t->width + col];
    switch (value->kind) {
        case l:
            printf("%ld\n", value->data.l);
            break;
        case f:
            printf("%f\n", value->data.f);
            break;
        case str:
            printf("%s\n", value->data.str);
    }
}

/*
    gibt Info über die geöffnete Datei aus
*/
void printInfo(Table *t) {
    printf("Datei: %s\nZeilen: %d\nSpalten: %d\n", t->path, t->width, t->height);
}