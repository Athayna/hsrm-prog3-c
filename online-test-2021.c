/*
 * Name: 
 * Matrikelnummer: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct le {
    int anzahl;
    char name[25];
    struct le *next;
} ListEle;

/* 
 * Prototypen fuer die zu implementierenden Funktionen 
 */

ListEle *hinzufuege(ListEle *liste, const char *name);
ListEle *korrigiere(ListEle *liste, const char *altname, const char *neuname);
ListEle *suche(ListEle *liste, const char *name);

/*
 * Bitte nachfolgend die Funktionen implementieren
 */

ListEle *hinzufuege(ListEle *liste, const char *name) {
    ListEle *new;
    ListEle *start = liste;

    if (liste == NULL) {
        new = malloc(sizeof(struct le));
        new->anzahl = 1;
        strcpy(new->name, name);
        new->next = NULL;
        return new;
    } else {
        while (liste->next != NULL) {
            if (strcmp(liste->name, name) == 0) {
                liste->anzahl++;
                return start;
            }
            liste = liste->next;
        }
        if (strcmp(liste->name, name) == 0) {
            liste->anzahl++;
            return start;
        } else {
            new = malloc(sizeof(struct le));
            new->anzahl = 1;
            liste->next = new;
            strcpy(new->name, name);
            new->next = NULL;
            return start;
        }
    }
}

ListEle *korrigiere(ListEle *liste, const char *altname, const char *neuname) {
    ListEle *start = liste;
    if (liste == NULL) {
        return liste;
    } else {
        while (liste != NULL) {
            if (strcmp(liste->name, altname) == 0) {
                strcpy(liste->name, neuname);
                return start;
            }
            liste = liste->next;
        }
    }
    return start;
}

ListEle *suche(ListEle *liste, const char *name) {
    while (liste != NULL) {
        if (strcmp(liste->name, name) == 0) {
            return liste;
        }
        liste = liste->next;
    }
    return NULL;
}

void deleteList(ListEle *liste) {
    ListEle *prev = liste;
    while (liste != NULL) {
        liste = liste->next;
        free(prev);
        prev = liste;
    }
}

/**********************************************************/

int main(int argc, char **argv) {
    
    ListEle *liste, *p;
    
    /* 
     * Erweiterte Beispiele vom Aufgabenblatt 
     * Sie können Tests für Funktionen, die Sie noch nicht implementiert haben, 
     * auskommentieren und die main()-Funktion beliebig (syntaktisch korrekt) anpassen.
     *
     * Compilieren Sie wie immer mit cc -ansi -pedantic -g
     * durch die -g Option koennen Sie debuggen,
     * UND wenn ein 'assert()' fehlschlaegt, 
     * bekommen Sie die zugehoerige Codezeile ausgegeben
     */

    
    /*
     * hinzufuege() - Hinzufügen von Knoten
     */
    
    printf("Fuege 'Joendhard' zu leerer Liste hinzu\n");
    liste = hinzufuege(NULL, "Joendhard");
    assert(liste->anzahl == 1);
    assert(!strcmp(liste->name, "Joendhard"));
    
    printf("Fuege 'Friedfert' zu Liste hinzu\n");
    liste = hinzufuege(liste, "Friedfert");
    assert(!strcmp(liste->next->name, "Friedfert"));
    
    printf("Fuege 'Joghurta' zu Liste hinzu\n");
    liste = hinzufuege(liste, "Joghurta");
    assert(!strcmp(liste->next->next->name, "Joghurta"));
    
    printf("Fuege nochmal 'Joendhard' zu Liste hinzu\n");
    liste = hinzufuege(liste, "Joendhard");
    assert(liste->anzahl == 2);
    assert(!strcmp(liste->name, "Joendhard"));

    printf("Liste ist nun: [%d_%s] -> [%d_%s] -> [%d_%s]\n\n",
            liste->anzahl, liste->name,
            liste->next->anzahl, liste->next->name,
            liste->next->next->anzahl, liste->next->next->name
          );

   
    /*
     * korrigiere() - Namen korrigieren
     */
    
    printf("Korrigiere 'Friedfert' nach 'Purzel'\n");
    liste = korrigiere(liste, "Friedfert", "Purzel");
    assert(!strcmp(liste->next->name, "Purzel"));
    
    printf("Fuege nochmal 'Purzel' zu Liste hinzu\n");
    liste = hinzufuege(liste, "Purzel");
    assert(liste->next->anzahl == 2);

    printf("Korrigiere 'Fluppi' (gibt's nicht) nach 'Jockel'\n");
    p = korrigiere(liste, "Fluppi", "Jockel");
    assert(liste == p);

    printf("Liste ist nun: [%d_%s] -> [%d_%s] -> [%d_%s]\n\n",
            liste->anzahl, liste->name,
            liste->next->anzahl, liste->next->name,
            liste->next->next->anzahl, liste->next->next->name
          );

    /*
     * suche() - Liste durchsuchen
     */
    
    printf("Suche 'Joendhard' in Liste\n");
    p = suche(liste, "Joendhard");
    assert(p == liste);
    
    printf("Suche 'Friedfert' in Liste (gibts nicht mehr)\n");
    p = suche(liste, "Friedfert");
    assert(p == NULL);

    printf("Suche 'Purzel' in Liste\n");
    p = suche(liste, "Purzel");
    assert(p==liste->next);

    printf("Suche 'Joghurta' in Liste\n");
    p = suche(liste, "Joghurta");
    assert(p== liste->next->next);
    
    /*
     * (Sie brauchen den Speicher nicht freizugeben)
     */
    deleteList(liste);
    
    return 0;
}

