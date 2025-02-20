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
    int id; // ID da aresta, útil para identificar arestas paralelas.
    int destino; // ID do vértice de destino.
    float tamanho; // Tamanho da aresta.
    Aresta *prox; // Próxima aresta na lista.
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

/*
Descrição: função responsável por verificar se um vértice já existe em um grafo.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: ponteiro para o vértice, e nulo caso não exista.
*/
Vertice *verifica_vertice(const Grafo *g, const int id) {
    Vertice *v = g->v;
    // Verificando se o vértice já existe.
    while (v) {
        if (v->id == id) {
            // Vértice existe.
            return v;
        }
        v = v->prox;
    }
    // Vértice não existe.
    return NULL;
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

/*
Descrição: função responsável por verificar se uma aresta já existe em um vértice.
Entrada: ponteiro para o vértice, inteiro do id da aresta.
Saída: ponteiro para a aresta, e nulo caso não exista.
*/
Aresta *verifica_aresta(const Vertice *v, const int id) {
    Aresta *a = v->a;
    // Verificando se a aresta já existe.
    while (a) {
        if (a->id == id) {
            // Aresta existe.
            return a;
        }
        a = a->prox;
    }
    // Aresta não existe.
    return NULL;
}

int adiciona_aresta(const Grafo *g, const int idVertice, const int idAresta, const int idDestino, const float tamanho) {
    Vertice *v = verifica_vertice(g, idVertice);
    if (v && !verifica_aresta(v, idAresta)) {
        // Criando uma nova aresta.
        Aresta *a = (Aresta *)malloc(sizeof(Aresta));
        if (!a) {
            return -1;
        }
        // Inicializando valores.
        a->id = idAresta;
        a->destino = idDestino;
        a->tamanho = tamanho;
        a->prox = v->a;
        // Inserindo no início para complexidade ser O(1).
        v->a = a;
        v->nAresta++;
        return 1;
    }
    return 0;
}

int grau_de_entrada(const Grafo *g, const int id) {
    int grau = -1;
    const Vertice *v = g->v;
    // Percorrendo os vértices.
    while (v) {
        if (v->id != id) {
            // Somando o grau caso a aresta tenha como destino o vértice informado no id.
            for (const Aresta *a = v->a; a; a = a->prox) {
                grau += a->destino == id ? 1 : 0;
            }
        }
        v = v->prox;
    }
    // Retornando o grau.
    return grau == -1 ? grau : grau + 1;
}

int grau_de_saida(const Grafo *g, const int id) {
    const Vertice *v = g->v;
    // Buscando o vértice correspondente.
    while (v && v->id != id) {
        v = v->prox;
    }
    // Retornando o grau.
    return !v ? -1 : v->nAresta;
}