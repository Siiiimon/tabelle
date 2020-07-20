#include "cli.h"

/*
    verarbeitet Nutzerinput
 */
int handleUserInput(Table *t, char *in) {
    if (in == NULL || strncmp(in, "ende", 4) == 0) {
        return 1;
    } else {
        char *token = strsep(&in, " ");
        if (strncmp(token, "zeige", 5) == 0) {
            commandPrint(t, in);
        } else if (strncmp(token, "setze", 5) == 0) {
            commandSet(t, in);
        } else if (strncmp(token, "speicher", 8) == 0) {
            commandSave(t, in);
        } else if (strncmp(token, "summiere", 8) == 0) {
            commandSumCol(t, in);
        } else if (strncmp(token, "sortiere", 8) == 0) {
            commandSort(t, in);
        } else if (strncmp(token, "hilfe", 5) == 0) {
            printf("'zeige' - Zeigt Tabelle an\n"
                   "\t'zeige'\n"
                   "\t'zeige spalte <index>'\n"
                   "\t'zeige zeile <index>'\n"
                   "\t'zeige zelle <zeilenindex> <spaltenindex>'\n"
                   "\t'zeige info'\n"
                   "'setze' - setzt wert einer Zelle\n"
                   "\t'setze <zeilenindex> <spaltenindex>' --> '<Zelleninhalt>'\n"
                   "'speicher' - speichert die bearbeitete Tabelle als Datei ab\n"
                   "\t'speicher <Datei>' (Pfad zu Datei+Dateiname+Dateiendung)\n"
                   "'summiere' - summiert Zahlenwerte einer Spalte\n"
                   "\t'summiere <index>'\n"
                   "'sortiere' - sortiert Tabelle nach einer ausgewählten Spalte\n"
                   "\t'sortiere <index>'\n"
                   "'hilfe' - zeigt diese Hilfe an\n"
                   "\t'hilfe'\n"
                   "'ende' - beendet das Programm\n"
                   "\t'ende'\n");
        } else {
            printf("unbekannte eingabe, 'hilfe' für eine Befehlsübersicht\n");
        }
    }
    return 0;
}
