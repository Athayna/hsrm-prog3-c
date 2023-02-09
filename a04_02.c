#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *content;
    struct node *prev;
    struct node *next;
} *nodep;

void printList(nodep lst) {
    if (lst == NULL) {
        printf("Empty List!");
    } else {
        do {
            printf("%p\n", lst->content);
            lst = lst->next;
        } while (lst != NULL);
    }
}

nodep insertAt(nodep lst, int pos, void *data) {
    nodep new = malloc(sizeof(struct node));
    int counter = 0;
    nodep result = lst;
    
    new->content = data;

    if (lst == NULL) {
        return new;
    }

    if (pos == 0) {
        new->next = lst;
        lst->prev = new;
        return new;
    } else {
        while (lst->next != NULL && counter != pos) {
            lst = lst->next;
            counter++;
        }
        if(pos == -1) {
            lst->next = new;
            new->prev = lst;
        } else {
            new->next = lst;
            new->prev = lst->prev;

            lst->prev = new;
            if(new->prev != NULL) {
                lst = new->prev;
                lst->next = new;
            }
        }
        return result;
    }  
}

nodep deleteAt(nodep lst, int pos) {
    int counter = 0;
    nodep result = lst;
    nodep next;
    nodep prev;

    while (lst->next != NULL && counter != pos) {
        lst = lst->next;
        counter++;
    }

    next = lst->next;
    prev = lst->prev;

    next->prev = prev;
    prev->next = next;

    free(lst);

    return result;
}

nodep copyList(nodep lst) {
    nodep new;
    nodep prev;
    nodep result;
    if(lst != NULL) {
        new = malloc(sizeof(struct node));
        new->content = lst->content;
        result = new;
        while (lst->next != NULL) {
            prev = new;
            lst = lst->next;
            new = malloc(sizeof(struct node));
            new->content = lst->content;
            new->prev = prev;
            prev->next = new;
        }
    }
    return result;
}

void deleteList(nodep lst) {
    while(lst->next != NULL) {
        lst = lst->next;
        free(lst->prev);
    }
    free(lst);
}

int main(int argc, char *argv[]) {
    nodep lst;
    int i;

    int testc = 3;
    char *test[] = {"./a04_02", "bla", "blub"};

    for (i = 1; i < testc; i++) {
        lst = insertAt(lst, i - 1, test[i]);
    }

    printList(lst);

    deleteList(lst);

    /*
    nodep one = malloc(sizeof(struct node));
    nodep two = malloc(sizeof(struct node));
    nodep three = malloc(sizeof(struct node));

    nodep copy;
    
    int integer = 3;
    char character = 'a';
    float flo = 17.0;

    one->content = &integer;
    one->next = two;

    two->content = &character;
    two->next = three;
    two->prev = one;

    three->content = &flo;
    three->prev = two;

    printList(one);

    copy = copyList(one);

    one = deleteAt(one, 1);

    printList(one);

    printList(copy);

    deleteList(one);

    deleteList(copy);
    */

    return 0;
}