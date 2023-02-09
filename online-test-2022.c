/***************************************************************
*
* Bitte ergaenzen Sie Ihre persoenlichen Angaben
* jeweils HINTER(!) dem Pfeil
*
* Vorname ---------> 
* Nachname --------> 
* Matrikelnummer --> 
* 
* Mit der Abgabe Ihrer Loesung im versichern Sie,
* "keine unerlaubte Hilfe anderer Personen in Anspruch genommen und 
* waehrend der Pruefung mit keiner anderen Person kommuniziert zu haben. 
* Mir ist bekannt, dass eine unwahre Erklaerung rechtliche Folgen haben
* und insbesondere dazu fuehren kann, dass die Pruefung als nicht 
* bestanden bewertet wird. Mir ist auch bekannt, dass im Falle eines
* mehrfachen oder schwerwiegenden Taeuschungsversuchs die Exmatrikulation 
* moeglich ist."
* Betrugsversuche koennen auch noch verfolgt werden, wenn sie erst nach
* Veroeffentlichung der Ergebnisse bekannt werden.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define MAXSTRINGLEN 100

/* Funktionsprototypen - nur zur Sicherheit */
void komprimiere(const char *ein, char *aus);
void entprelle(const char *ein, char *aus);
void expandiere(const char *ein, char *aus);

/***************************************************************
* BITTE NACHFOLGEND IHRE LOESUNG EINTRAGEN und dabei
* bitte KEINEN eigenen (Test-)Konsolenoutput (printf()) 
* ausserhalb main() erzeugen.
* Eigene Testausgaben in der main()-Funktion sind ok.
*
* Die Aufgabe ist in ANSI-C 90 zu loesen, 
* compilieren unter Linux (ggf. ueber holadi) mit
*     gcc -g -ansi-errors -pedantic  ...
* darf keine Fehler ergeben. 
* Laufzeit-/Valgrind-Fehler sind Fehler, auch wenn
* "das richtige Ergebnis rauskommt" (da das Ergebnis
* auf unedle Weise erzeugt wurde).
************************************************/

void komprimiere(const char *ein, char *aus) {
    int compress;
    char out[5];
    if (strlen(ein) <= 3 || !isalpha(ein[0])) {
        strcpy(aus, ein);
    } else {
        out[0] = ein[0];
        compress = strlen(ein) - 2;
        sprintf(out+1, "%d", compress);
        sprintf(out+strlen(out), "%c", ein[strlen(ein) - 1]);
        strcpy(aus, out);
    }
}

void entprelle(const char *ein, char *aus) {
    int i;
    int j;
    char c;
    for (i = 0; i < strlen(ein); i++) {
        c = ein[i];
        j = i + 1;
        while (ein[j] == ein[i]) {
            j++;
        }
        sprintf(aus, "%c", c);
        aus++;
        i = j - 1;
    }
    *aus = '\0';
}

void expandiere(const char *ein, char *aus) {
    int bla;
    if ((strlen(ein) < 3) || !isdigit(ein[1])) {
        strcpy(aus, ein);
    } else {
        *aus = *ein;
        sscanf(ein+1, "%d", &bla);
        aus++;
        while (bla > 0) {
            *aus = 'b';
            aus++;
            bla--;
            if (bla > 0) {
                *aus = 'l';
                aus++;
                bla--;
            }
            if (bla > 0) {
                *aus = 'a';
                aus++;
                bla--;
            }
        }
        *aus = *(ein+(strlen(ein)-1));
        aus++;
        *aus = '\0';
    }
}

/****************************************************************
* Test-Hilfsfunktion zur Verwendung in main() -
* ruft Ihre Funktionen auf, fuettert sie mit Input und vergleicht das Ergebnis
*****************************************************************/

static int teste_bitte_mal(const char *testname, 
            const char* testfunktionsname, void testfunktion(const char*, char*), 
            const char *eingabe, const char *erwartet) {
        char ausgabe[MAXSTRINGLEN+1];
        int unmuss = 0;

        printf("\n*** Starte %s ***\n", testname);
        printf("Versuche %s(\"%s\", ...)\n", testfunktionsname, eingabe);
        fflush(stdout);
        testfunktion(eingabe, ausgabe);
        printf("    Ergebnis: \"%s\" (%lu Zeichen)\n", ausgabe, strlen(ausgabe));
        if (!strcmp(ausgabe, erwartet)) {
            printf("    OK, Ergebnis wie erwartet.\n");
        } else {
            unmuss = 1;
            printf("    ABWEICHUNG - erwartetes und erhaltenes Ergebnis (Anfuehrungszeichen zur Begrenzung):\n");
            printf("        - erwartet: \"%s\" (%lu Zeichen)\n", erwartet, strlen(erwartet));
            printf("        - bekommen: \"%s\" (%lu Zeichen)\n", ausgabe, strlen(ausgabe));
        }
        fflush(stdout);
        return unmuss;
    }


/************************************************
* main() - Hier sind eigene (Test-)Ausgaben zulaessig
* Sie koennen auch gerne eigene Test-Aufrufe Ihrer Funktionen hier
* einfuegen -- die main() wird nicht bewertet
************************************************/
int main(int argc, char *argv[]) {
    int zkomprim=0, zexpan=0, zentpr=0;


    /*                           Test-Name          / Funktionsname / Funktion / Eingabe  /  erwartete Ausgabe */

    zkomprim += teste_bitte_mal("test_komprimiere_1", "komprimiere", komprimiere, "Internationalization", "I18n");
    zkomprim += teste_bitte_mal("test_komprimiere_2", "komprimiere", komprimiere, "Tag", "Tag");
    zkomprim += teste_bitte_mal("test_komprimiere_3", "komprimiere", komprimiere, "", "");
    zkomprim += teste_bitte_mal("test_komprimiere_4", "komprimiere", komprimiere, "170x", "170x");
    zkomprim += teste_bitte_mal("test_komprimiere_5", "komprimiere", komprimiere, "d987", "d27");
    zkomprim += teste_bitte_mal("test_komprimiere_6", "komprimiere", komprimiere, "amamaladnamalahammaadahaam", "a24m");

    zentpr += teste_bitte_mal("test_entprelle_1", "entprelle", entprelle, "cool", "col");
    zentpr += teste_bitte_mal("test_entprelle_2", "entprelle", entprelle, "", "");
    zentpr += teste_bitte_mal("test_entprelle_3", "entprelle", entprelle, "KKKKeeeeekkkksssdoooosee", "Keksdose");
    zentpr += teste_bitte_mal("test_entprelle_4", "entprelle", entprelle, "*** Neuuu   *****", "* Neu *");
    zentpr += teste_bitte_mal("test_entprelle_5", "entprelle", entprelle, "Annnn deeeerr Noooordseeeeekuestttte!!!", "An der Nordsekueste!");
    zentpr += teste_bitte_mal("test_entprelle_6", "entprelle", entprelle, "17000 EEimmerrr BBrennnessel---Teess", "170 Eimer Brenesel-Tes");

    zexpan += teste_bitte_mal("test_expandiere_1", "expandiere", expandiere, "Internationalization", "Internationalization");
    zexpan += teste_bitte_mal("test_expandiere_2", "expandiere", expandiere, "z8", "z8");
    zexpan += teste_bitte_mal("test_expandiere_3", "expandiere", expandiere, "L10n", "Lblablablabn");
    zexpan += teste_bitte_mal("test_expandiere_4", "expandiere", expandiere, "E2i", "Ebli");
    zexpan += teste_bitte_mal("test_expandiere_5", "expandiere", expandiere, "A5x", "Ablablx");
    zexpan += teste_bitte_mal("test_expandiere_6", "expandiere", expandiere, "I18n", "Iblablablablablablan");

    printf("\n================================================================\n");
    printf("Zusammenfassung: Gezaehlte Abweichungen vom erwarteten Ergebnis:\n");
    printf("================================================================\n");
    printf("  - komprimiere(): %d  %s\n", zkomprim, zkomprim? "unvollstaendig":"OK");
    printf("  - entprelle():   %d  %s\n", zentpr, zentpr? "unvollstaendig":"OK");
    printf("  - expandiere():  %d  %s\n", zexpan, zexpan? "unvollstaendig":"OK");
    printf("\n==================================================================\n");
    printf("Hinweis: Die Zusammenfassung behandelt nur Ergebnisvergleiche,\n");
    printf("         bitte auch auf eventuelle Valgrind-Fehlermeldungen achten\n");
    printf("         und z.B. holadi verwenden, wenn Sie kein valgrind haben.\n");
    printf("         Wenn die mitgelieferte Funktion teste_bitte_mal() in Valgrind-\n");
    printf("         Meldungen erscheint, hat Ihre aufgerufene Funktion vermutlich\n");
    printf("         ein fehlerhaftes Ergebnis zurueckgeliefert und der Fehler wirkt\n");
    printf("         sich erst in teste_bitte_mal() aus. Debuggen hilft.\n");
    printf("==================================================================\n\n\n");

    assert(zkomprim == 0 && zentpr == 0 && zexpan == 0);

    return 0;
}

