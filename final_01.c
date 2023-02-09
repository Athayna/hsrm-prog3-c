#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct lst {
    char name[20];
    int alter;
    struct lst *next;}
    ListEle;

ListEle *einfuegen(ListEle *lst, const char *n, int a) {
    ListEle *new = malloc(sizeof(struct lst));
    ListEle *first = lst;

    strcpy(new->name, n);
    new->alter = a;
    new->next = NULL;

    if(lst != NULL) {
        while(lst->next != NULL) {
            lst = lst->next;
        }
        lst->next = new;
        return first;
    }
    return new;
}

int dopple(ListEle *lst, const char *n, int a) {
    ListEle *new;
    while(lst != NULL) {
        if((strcmp(lst->name, n) == 0) && (lst->alter == a)) {
            new = malloc(sizeof(struct lst));
            strcpy(new->name, lst->name);
            new->alter = lst->alter;
            new->next = lst->next;
            lst->next = new;
            return 1;
        }
        lst = lst->next;
    }
    return 0;
}

void befreie(ListEle *lst) {
    ListEle *next;
    if(lst != NULL) {
        while(lst->next != NULL) {
            next = lst->next;
            free(lst);
            lst = next;
        }
        free(lst);
    }
}

int main(void) {
    char n[24];
    int a;
    ListEle *lst = NULL;

    while(scanf("%s", n) != EOF) {
        sscanf((strchr(n, ',') + 1), "%d", &a);
        /* *strchr(n, ',') + 1 = '\0'; */
        lst = einfuegen(lst, n, a);
    }

    if(dopple(lst, "Joghurta,21", 21) == 1) {
        printf("Verdopplung gelungen.\n");
    } else {
        printf("Verdopplung gescheitert\n");
    }

    befreie(lst);

    return 0;
}