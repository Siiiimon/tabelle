#include "parse.h"

/*
    versucht 'token' als 'Cell' zu interpretieren (bzw. ganzzahl, gleitkommazahl oder string)
    achtung: modifiziert 'token' (entfernt zeilenumbrüche vom ende des strings)
*/
Cell *parseCell(char *token) {
    struct Cell *chunk = malloc(sizeof(*chunk));

    // Zeilenumbruch von 'token'-ende entfernen
    size_t length = strlen(token);
    if (length && ((token[length - 1] == '\n') || (token[length - 1] == '\r'))) {
        token[length - 1] = '\0';
    }

    // Fall für leere zelle abfangen
    if (*token == '\0') {
        chunk->kind = str;
        chunk->data.str = "";
        return chunk;
    }

    // versuchen als integer zu interpretieren
    char *check = NULL;
    long number = strtol(token, &check, 10);
    if (*check == '\0') {
        chunk->kind = l;
        chunk->data.l = number;
        return chunk;
    }

    // versuchen als gleitkommazahl zu interpretieren
    check = NULL;
    float decimal = strtof(token, &check);
    if (*check == '\0') {
        chunk->kind = f;
        chunk->data.f = decimal;
        return chunk;
    }

    chunk->kind = str;
    chunk->data.str = strdup(token);
    return chunk;
}

/*
    ließt Datei ein und speichert Inhalt im Tabellenarray
*/
Table *parseTable(char *path, int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }

    // Datei mit Leserechten öffnen
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }

    // Tabellenarray initialisieren und Speicher allozieren
    Table *t = malloc(sizeof(*t));
    t->table = malloc(rows * cols * sizeof(Cell));
    t->height = rows;
    t->width = cols;
    t->path = path;

    char *line = NULL;
    size_t linecap = 0;
    int rowcounter = 0, colcounter = 0;

    // zeilenweise durch Datei iterieren
    while ((getline(&line, &linecap, file)) > 0) {
        char *datachunk, *copy, *temp;
        temp = copy = strdup(line); // strtok modifiziert 'copy', der 'temp' Pointer wird zur Speicherfreigabe genutzt

        // zellenweise durch Zeile iterieren
        for (datachunk = strtok(copy, ","); (datachunk); datachunk = strtok(NULL, ",")) {
            // Inhalt lesen
            Cell *c = parseCell(datachunk);
            t->table[rowcounter * cols + colcounter] = c;
            colcounter++;
        }

        rowcounter++;
        colcounter = 0;
        free(temp);
    }

    fclose(file);
    free(line);
    return t;
}

void freeTable(Table *t) {
    for (int y = 0; y < t->height; ++y) {
        for (int x = 0; x < t->width; ++x) {
            // falls die zelle ein string enthält, muss dieser seperat freigegeben werden
            if (t->table[y * t->width + x]->kind == str) {
                free(t->table[y * t->width + x]->data.str);
            }
            free(t->table[y * t->width + x]);
        }
    }
    free(t);
}