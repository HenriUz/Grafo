#include <stdlib.h>
#include "grafo.h"

struct Grafo {
    int nVertices; // Quantidade de vértices.
    Vertice *v; // Vértices do grafo.
};

struct Vertice {
    int id; // ID do vértice.
    int nAresta; // Quantidade de arestas.
    Aresta *a; // Arestas do vértice.
    Vertice *prox; // Próximo vértice na lista.
};

struct Aresta {
    int destino; // ID do vértice de destino.
    float tamanho; // Tamanho da aresta.
};

Grafo *cria_grafo() {
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    // Verificando se o chunk foi alocado corretamente.
    if (!g) {
        return NULL;
    }
    // Inicializando valores iniciais.
    g->nVertices = 0;
    g->v = NULL;
    return g;
}