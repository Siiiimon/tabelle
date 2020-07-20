#include "saveCommand.h"

/*
    verarbeitet Nutzereingabe für den 'speicher' Kommando
*/
void commandSave(Table *t, char *in) {
    // pfad einlesen
    char *path = strsep(&in, "\n");
    if (path == NULL) {
        printf("keine Pfadangabe gefunden\n");
        return;
    }

    // datei speichern
    if (saveFile(t, path) > 0) {
        printf("es ist ein Fehler aufgetreten\n");
        return;
    } else {
        printf("Tabelle unter %s erfolgreich gespeichert\n", path);
    }
}