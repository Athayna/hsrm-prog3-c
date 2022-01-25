
/*
 * Name: 
 * Matrikelnummer: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void java2html(const char *jstring, char *htmlstring);

void java2html(const char *jstring, char *htmlstring) {
    /* Ihre Loesung */
    
    
    
}


int main(int argc, char *argv[]) {
    enum { BUFSIZE = 100 };
    char *ergebnis = malloc(BUFSIZE);
    char *s;

    assert(ergebnis != NULL);

    s = "x";
    java2html(s, ergebnis);
    assert(!strcmp("x", ergebnis));

    s = "eingabeFeld";
    java2html(s, ergebnis);
    assert(!strcmp("eingabe-feld", ergebnis));

    s = "benutzerLoginNameHintergrundFarbe";
    java2html(s, ergebnis);
    assert(!strcmp("benutzer-login-name-hintergrund-farbe", ergebnis));

    s = "spaltenZahl17Breite";
    java2html(s, ergebnis);
    assert(!strcmp("spalten-zahl17-breite", ergebnis));

    s = "derADAC";
    java2html(s, ergebnis);
    assert(!strcmp("der-a-d-a-c", ergebnis));

    free(ergebnis);

    printf("Kein assert-Abbruch -- Ergebnisse scheinen so weit ok,\n");
    printf("bitte wegen möglicher Speicherfehler auf Valgrind-Output achten.\n");
    return 0;
}
