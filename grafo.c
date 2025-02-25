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
    float tamanho; // Tamanho da aresta.
    Aresta *prox; // Próxima aresta na lista.
    Vertice *destino; // Vértice de destino.
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
    // Verificando se o vértice já existe.
    for (Vertice *v = g->v; v; v = v->prox) {
        if (v->id == id) {
            // Vértice existe.
            return v;
        }
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
        v->nAresta = 0;
        v->a = NULL;
        v->prox = g->v;
        // Inserindo no início para a complexidade ser O(1).
        g->nVertices++;
        g->v = v;
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
    // Verificando se a aresta já existe.
    for (Aresta *a = v->a; a; a = a->prox) {
        if (a->id == id) {
            // Aresta existe.
            return a;
        }
    }
    // Aresta não existe.
    return NULL;
}

int adiciona_aresta(const Grafo *g, const int idOrigem, const int idDestino, const int idAresta, const float tamanho) {
    Vertice *origem = NULL, *destino = NULL;
    // Buscando os vértices (sem usar a verifica_vertice para buscar os dois em um único loop).
    for (Vertice *v = g->v; v; v = v->prox) {
        // 2 ifs para identificar laço.
        if (v->id == idOrigem) {
            origem = v;
        }
        if (v->id == idDestino) {
            destino = v;
        }
    }
    // Verificando se a aresta pode ser inserida (vértices existem, e a aresta ainda não existe).
    if (origem && destino && !verifica_aresta(origem, idAresta)) {
        // Criando uma nova aresta.
        Aresta *a = (Aresta *)malloc(sizeof(Aresta));
        if (!a) {
            return -1;
        }
        // Inicializando valores.
        a->id = idAresta;
        a->tamanho = tamanho;
        a->prox = origem->a;
        a->destino = destino;
        // Inserindo no início para complexidade ser O(1).
        origem->nAresta++;
        origem->a = a;
        return 1;
    }
    return 0;
}

int grau_de_entrada(const Grafo *g, const int id) {
    int grau = 0, aux = -1;
    if (g) {
        // Percorrendo os vértices.
        for (const Vertice *v = g->v; v; v = v->prox) {
            // Verificando se o vértice existe.
            if (v->id == id) {
                aux = 1;
            }
            // Somando o grau caso a aresta tenha como destino o vértice informado no id.
            for (const Aresta *a = v->a; a; a = a->prox) {
                grau += a->destino->id == id ? 1 : 0;
            }
        }
    }
    // Retornando o grau.
    return aux == -1 ? aux : grau;
}

int grau_de_saida(const Grafo *g, const int id) {
    const Vertice *v = NULL;
    if (g) {
        v = g->v;
        // Buscando o vértice correspondente.
        while (v && v->id != id) {
            v = v->prox;
        }
    }
    // Retornando o grau.
    return !v ? -1 : v->nAresta;
}

double densidade(const Grafo *g) {
    int arestas = 0;
    double densidade = 0;
    if (g) {
        // Calculando a quantidade total de arestas.
        for (const Vertice *v = g->v; v; v = v->prox) {
            arestas += v->nAresta;
        }
        // Calculando a densidade.
        densidade = (double)arestas / (g->nVertices * (g->nVertices - 1));
    }
    return densidade;
}