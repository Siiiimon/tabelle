#include "file.h"

/*
    zählt anzahl an delimiter in einem string
*/
int _countCols(char *source, char delim) {
    char *copy = source;
    int counter = 0;
    while (*copy) {
        if (*copy == delim) {
            counter++;
        }
        ++copy;
    }
    return counter+1;
}

/*
    ließt Datei ein und zählt Anzahl an Zeilen und Spalten
*/
int countRowsAndColumns(char *path, int *rows, int *cols) {
    // todo: merge into parseTable
    // datei mit leserechten öffnen
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return 1;
    }

    char *line = NULL;
    size_t linecap = 0;
    *rows = 0, *cols = 0;

    // durch datei zeile für zeile iterieren
    while ((getline(&line, &linecap, file)) > 0) {
        *cols = _countCols(line, ','); // spalten zählen
        (*rows)++; // zeilen zählen
    }

    fclose(file);
    free(line);
    return 0;
}

int saveFile(Table *t, char *path) {
    // datei mit leserechten öffnen
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        return 1;
    }

    for (int y = 0; y < t->height; ++y) {
        for (int x = 0; x < t->width; ++x) {
            Cell *value = t->table[y * t->width + x];
            switch (value->kind) {
                case l:
                    fprintf(file, "%ld", value->data.l);
                    break;
                case f:
                    fprintf(file, "%f", value->data.f);
                    break;
                case str:
                    fprintf(file, "%s", value->data.str);
            }
            if (x != t->width - 1) {
                fprintf(file, ",");
            } else {
                fprintf(file, "\n");
            }
        }
    }
    fflush(file);
    fclose(file);
    return 0;
}