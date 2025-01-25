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

int adiciona_vertice(Grafo *g, const int id) {
    if (g && !verifica_vertice(g, id)) {
        // Criando um novo vértice.
        Vertice *v = (Vertice *)malloc(sizeof(Vertice));
        if (!v) {
            return -1;
        }
        // Inicializando valores.
        v->id = id;
        v->prox = g->v;
        v->nAresta = 0;
        v->a = NULL;
        // Inserindo no início para a complexidade ser O(1).
        g->v = v;
        g->nVertices++;
        return 1;
    }
    return 0;
}

int verifica_vertice(const Grafo *g, const int id) {
    const Vertice *v = g->v;
    // Verificando se o vértice já existe.
    while (v) {
        if (v->id == id) {
            // Vértice existe.
            return 1;
        }
        v = v->prox;
    }
    // Vértice não existe.
    return 0;
}