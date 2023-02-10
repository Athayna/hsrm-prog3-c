#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char data;
    struct list *next;
} list;

list *rotate_left(list *lis) {
    list *mem = lis;
    list *res;
    if (lis == NULL || lis->next == NULL) {
        return lis;
    } else {
        res = lis->next;
        while (lis->next != NULL) {
            lis = lis->next;
        }
        lis->next = mem;
        mem->next = NULL;
        return res;
    }
}

list *rotate_right(list *lis) {
    list *mem = lis;
    list *first = lis;
    if (lis == NULL || lis->next == NULL) {
        return lis;
    } else {
        lis = lis->next;
        while (lis->next != NULL) {
            mem = lis;
            lis = lis->next;
        }
        mem->next = NULL;
        lis->next = first;
        return lis;
    }
}

void printList(list *lis) {
    while (lis != NULL) {
        printf("%c", lis->data);
        lis = lis->next;
    }
    printf("\n");
}

void freeList(list *lis) {
    list *prev = lis;
    while (lis != NULL) {
        lis = lis->next;
        free(prev);
        prev = lis;
    }
}

int main(void) {
    list *abc = malloc(sizeof(struct list));
    list *a = malloc(sizeof(struct list));

    abc->data = 'a';
    abc->next = malloc(sizeof(struct list));
    abc->next->data = 'b';
    abc->next->next = malloc(sizeof(struct list));
    abc->next->next->data = 'c';
    abc->next->next->next = NULL;

    a->data = 'a';
    a->next = NULL;

    abc = rotate_left(abc);
    printList(abc); /* bca */
    abc = rotate_right(abc);
    abc = rotate_right(abc);
    printList(abc); /* cab */
    printList(rotate_left(a)); /* a */

    freeList(abc);
    freeList(a);

    return 0;
}