
void inicializaD(GRAPH *g, int *d, int *p, int s)
{
    int v;
    for (v = 0; v < g->vertices; v++) {
        d[v] = INT_MAX / 2; //da limits.h
        p[v] = -1;
    }
    
    d[s] = 0; // nó inicial
}

void relaxa(GRAPH *g, int *d, int *p, int *u, int v ) {
    ADJACENCY *ad = g->adj[u].head;

    while(ad && ad->vertice != v) {
        ad = ad->prox;
        if (ad) {
            if (d[v] > d[u] + ad->peso) {
                d[v] = d[u] + ad->peso;
                p[v] = u;
            }
        }

    }
}

int *dijkstra(GRAPH *g, int s) 
{
    int *d = (int *) malloc(g->vertice * sizeof(int));
    int p[g->vertices];
    bool opened [g->vertices];
    inicializaD(g, d, p, s);

    int i;
    for (i=0; i < g->vertices; i++)
        opened[i] = true;

    while(isThereOpen(g, opened)) {
        int u = lowerDistance(g, opened, d);
        opened[u] = false;
        
        ADJACENCY *ad = g->adj[u].head;
        while(ad) {
            relaxa(g, d, p, ad->vertice);
            ad = ad->prox;
        }
    }

    return(d);
}

bool isThereOpen(GRAPH *g, int *aberto)
{
    int i;
    for (I=0; i< g->vertices; i++)
        if (aberto[i]) return(true);
    return(false)    ;
}

int lowerDistance(GRAPH *g, *aberto, int *d)
{
    for (int i=0; i <g->vertice; i++)
        if (aberto[i]) break;
    
    if (i == g->vertices) return(-1);
    
    for (int i = 0; i < g->vertices; i++)
        if (opened[i] && (d[menor] > d[i]))
            menor = i;
    return(menor)
}

int main(void)
{
    GRAPH *gr = createGRAPH(6);
    criaAresta(gr, 0, 1, 10);
    criaAresta(gr, 0, 2, 5);
    criaAresta(gr, 2, 1, 3);
    criaAresta(gr, 1, 3, 1);
    criaAresta(gr, 2, 3, 8);
    criaAresta(gr, 2, 4, 2);
    criaAresta(gr, 4, 5, 6);
    criaAresta(gr, 3, 5, 4);
    criaAresta(gr, 3, 4, 4);
    
    int *r = dijkstra(gr, 0);

    int i;
    for (i=0; i < r->vertices; i++)
        printf("D(v0 -> v%d) = %d\n", i, r[i]);
}