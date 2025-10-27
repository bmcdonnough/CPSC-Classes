/*
**********************
 *Benjamin McDonnough
 *mcdonn7@clemson.edu
 *Lab 7 006
 *********************
 */


#include <stdio.h>

struct NODE{
    int a;
    struct NODE *b;
    struct NODE *c;
}nodes[5] = { 
                {15,    nodes + 2,  nodes + 1},
                {30,    nodes + 3,  NULL},
                {46,    nodes + 1,  nodes + 4},
                {95,    nodes + 4,  nodes},
                {123,    NULL, nodes + 2}
    };
struct NODE* np = nodes + 4;
struct NODE** npp = &nodes[2].b;

int main()
{
    printf("nodes   %p\n", nodes);
    printf("nodes[3].a   %i\n", nodes[3].a);
    printf("nodes[3].c   %p\n", nodes[3].c);
    printf("nodes[3].c->a   %i\n", nodes[3].c->a);
    printf("(*nodes).a   %i\n", (*nodes).a);
    printf("nodes->a    %i\n", nodes->a);
    printf("nodes[3].b->b   %p\n", nodes[3].b->b);
    printf("&nodes[3].a   %p\n", &nodes[3].a);
    printf("&nodes[3].c   %p\n", &nodes[3].c);
    printf("&nodes[3].c->a   %p\n", &nodes[3].c->a);
    printf("&nodes->a   %p\n", &nodes->a);
    printf("np   %p\n", np);
    printf("np->a   %i\n", np->a);
    printf("np->c->c->a   %i\n", np->c->c->a);
    printf("npp   %p\n", npp);
    printf("*npp   %p\n", *npp);
    printf("(*npp)->a   %i\n", (*npp)->a);
    printf("&np   %p\n", &np);
    printf("&np->a   %p\n", &np->a);
    printf("&np->c->c->a   %p\n", &np->c->c->a);

    return 0;
}
