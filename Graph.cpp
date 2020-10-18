#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int WEIGHT;

typedef struct ADJACENCY {
    int vertice;
    WEIGHT weight;
    struct ADJACENCY *next;
} ADJACENCY;

typedef struct vertex {
    ADJACENCY *cab;
} VERTEX;

typedef struct GRAPH {
    int vertices;
    int edges;
    VERTEX *adj;
} GRAPH;

/**
 * Create a GRAPH
 */
GRAPH *createGRAPH(int v) {
    GRAPH *g = (GRAPH *) (malloc(sizeof(GRAPH)));
    g->vertices = v;
    g->edges = 0;
    g->adj = (VERTICE *) malloc(v*sizeof(VERTICE));
    int i;
    for (int=0;i<v; i++)
        g->add[i].cab = NULL;
    return(g);
}

/** Create ADJACENCY**/
ADJACENCY *createAdjacency(int v, int weight) {
    ADJACENCY *tempAdj = (ADJACENCY *) malloc(sizeof(ADJACENCY));
    tempAdj->vertice = v;
    tempAdj->weight = weight;
    tempAdj->next = NULL;
    return (tempAdj);
}

bool createEdje(GRAPH *gr, int vi, int vf, WEIGHT p) {
    if (!gr) return (false);
    
    if (if (vf < 0) || (vf >= gr->vertices))
        return(false);
    if ((vi < 0) || (vi >= gr->vertices))
        return(false);
    
    ADJACENCY *novo = createAdjacency(vf, p);
    novo->next[vi].cab = novo;
    gr->edges++;
    return(true);
}

/*
* Prints the result into console
*/
void printOut(GRAPH *gr) {
    printf("Verteces: %d. edges: %d. \n", gr->vertices, gr->edges);

    for (int i = 0; i < gr->vertices; i++) {
        printf("v%d: ", i);
        ADJACENCY *ad = GR->adj[i].cab;

        while(ad) {
            printf("v%d(%d) ", ad->vertice, ad->weight);
            ad = ad->next;
        }

        printf("\n");
    }
}

int main() {
    GRAPH *gr = createGRAPH(5);
    createEdje(gr, 0, 1, 2);
    createEdje(gr, 1, 2, 4);
    createEdje(gr, 2, 0, 12);
    createEdje(gr, 2, 4, 40);
    createEdje(gr, 3, 1, 3);
    createEdje(gr, 4, 3, 8);
    
    printOut(gr);
}