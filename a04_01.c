#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ring *Ring;

struct ring {
        char name[25];
        Ring next;
};

Ring createRing(char *name, Ring p) {
    Ring ring = malloc(sizeof(struct ring));
    strcpy(ring->name, name);
    ring->next = p;
    return ring;
}

Ring add(Ring p, char *name) {
    Ring i = p;
    if(p->next == NULL) {
        p = createRing(name, p);
        p->next = p;
    } else {
        while(i->next != p) {
            i = i->next;
        }
        i->next = createRing(name, p);
    }
    return p;
}

void del(Ring p) {
    Ring i = p;
    Ring del = p;
    while(i->next != p) {
        del = i;
        i = i->next;
        free(del);
    }
    free(i);
    free(p);
}

int main(int argc, char *argv[]) {
    Ring p = malloc(sizeof(struct ring));
    char name[25];
    if(!p) return 1;
    p->next = NULL;

    while(scanf("%s", name) != EOF) {
        p = add(p, name);
    }

    del(p);
    return 0;
}