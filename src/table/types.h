#ifndef TABELLE_TYPES_H
#define TABELLE_TYPES_H

/*
    Eine Zentrale Headerdatei mit allen relevanten Tabellentypen
*/

enum DataType {
    l,
    f,
    str
};

union Data {
    long l;
    float f;
    char *str;
};

typedef struct Cell {
    enum DataType kind;
    union Data data;
} Cell;

typedef struct Table {
    char *path;
    int width;
    int height;
    struct Cell **table;
} Table;

#endif //TABELLE_TYPES_H
