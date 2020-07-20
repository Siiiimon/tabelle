#include "file.h"
#include "table/parse.h"
#include "table/modify.h"
#include "table/types.h"
#include "cli/cli.h"

/*
    in 'main' wickelt sich der komplette programmablauf ab
    'main' kümmert sich fast nur um das entgegen nehmen von nutzer input
    und delegiert jegliche komplexe funktionalität an untermodule
*/
int main(int argc, char const *argv[]) {
    int rows, cols, isRunning = 1;

    // Befehlszeilenargumente einlesen
    if (argc != 2) {
        printf("Unbekannter Parameterformat\n"
               "Nutzung: tabelle.exe <datei>\n");
        return 1;
    }
    char *path = (char *) argv[1];
    if (path == NULL) {
        printf("Unbekannter Parameterformat\n"
               "Nutzung: tabelle.exe <datei>\n");
        return 1;
    }

    // Zeilen und Spalten lesen (wird für den aufbau des internen speicher benötigt)
    if (countRowsAndColumns(path, &rows, &cols) == 1) {
        printf("datei konnte nicht gefunden werden\n");
        return 2;
    }

    // Datei einlesen und Tabellenarray aufbauen
    Table *t = parseTable(path, rows, cols);
    if (t == NULL) {
        printf("fehler beim Lesen der datei\n");
        return 3;
    }

    // auf nutzer input warten und verarbeiten
    while (isRunning) {
        char buf[1024];

        printf("> ");
        char *in = fgets(buf, 1024, stdin);

        if (handleUserInput(t, in) != 0) {
            isRunning = 0;
        }
    }

    // speicher freigeben
    freeTable(t);
//  void *lul = malloc(8); // TODO: check for leaks

    // erfolgreich beenden
    return 0;
}