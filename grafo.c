/**
 * @file grafo.c
 *
 * @brief Implementação das funções para manipulação de grafos dirigidos (dígrafos), além de implementar funções auxiliares.
 *
 * @author HenriUz
 */

#include <stdlib.h>
#include "grafo.h"

struct Grafo {
    int nVertices;      /**< Quantidade de vértices. */
    Vertice *v;         /**< Vértice inicial da lista encadeada de vértices. */
};

struct Vertice {
    int id;             /**< ID do vértice. */
    int nAresta;        /**< Quantidade de arestas incidentes a partir do vértice. */
    Aresta *a;          /**< Aresta inicial da lista encadeada de arestas. */
    Vertice *prox;      /**< Próximo vértice na lista. */
};

struct Aresta {
    int id;             /**< ID da aresta, útil para identificar arestas paralelas. */
    float tamanho;      /**< Peso da aresta. */
    Aresta *prox;       /**< Próxima aresta na lista. */
    Vertice *destino;   /**< Vértice de destino. */
};

Grafo *criar_grafo() {
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

/**
 * @brief Função de verificação de vértices.
 *
 * Verifica se o vértice especificado existe no grafo informado.
 *
 * @param g Ponteiro para o grafo.
 * @param id Inteiro identificador do vértice.
 * @retval v Ponteiro para o vértice.
 * @retval NULL Valor nulo se o vértice não existe.
 */
Vertice *verificar_vertice(const Grafo *g, const int id) {
    // Verificando se o vértice já existe.
    for (Vertice *v = g->v; v; v = v->prox) {
        if (v->id == id) {
            return v;
        }
    }
    return NULL;
}

int vertices(const Grafo *g) {
    return !g ? 0 : g->nVertices;
}

int adicionar_vertice(Grafo *g, const int id) {
    if (g && !verificar_vertice(g, id)) {
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
        // Inserindo na lista de vértices.
        g->nVertices++;
        g->v = v;
        return 1;
    }
    return 0;
}

int remover_vertice(Grafo *g, const int id) {
    if (g) {
        // Percorrendo os vértices do grafo.
        Vertice *vElemento = NULL, *vAnterior = NULL;   // vElemento aponta para o vértice que será removido, e vAnterior aponta para o vértice anterior na lista.
        for (Vertice *v = g->v; v; v = v->prox) {
            if (v->id == id) {
                vElemento = v;
            }else if (!vElemento) {
                vAnterior = v;
            }
            // Percorrendo as arestas.
            Aresta *a = v->a, *aAnterior = NULL;        // a é um ponteiro que irá percorrer a lista de arestas, e aAnterior aponta para a aresta anterior na lista.
            while (a) {
                // Remove a aresta caso o destino seja o vértice informado, ou caso o vértice atual seja o informado.
                if (a->destino->id == id || v->id == id) {
                    Aresta *aElemento = a;              // Ponteiro para a aresta que será removida.
                    if (aAnterior) {
                        aAnterior->prox = a->prox;
                    }else {
                        v->a = a->prox;
                    }
                    a = a->prox;
                    v->nAresta--;
                    free(aElemento);
                }else {
                    aAnterior = a;
                    a = a->prox;
                }
            }
        }
        // Caso o vértice tenha sido encontrado, remove ele.
        if (vElemento) {
            if (vAnterior) {
                vAnterior->prox = vElemento->prox;
            }else {
                g->v = vElemento->prox;
            }
            g->nVertices--;
            free(vElemento);
            return 1;
        }
        return -1;
    }
    return 0;
}

/**
 * @brief Função de verificação de arestas.
 *
 * Verifica se a aresta especificada existe no vértice informado.
 *
 * @param v Ponteiro para o vértice.
 * @param id Inteiro identificador da aresta.
 * @retval a Ponteiro para a aresta.
 * @retval NULL Valor nulo se a aresta não existe.
 */
Aresta *verificar_aresta(const Vertice *v, const int id) {
    // Verificando se a aresta já existe.
    for (Aresta *a = v->a; a; a = a->prox) {
        if (a->id == id) {
            return a;
        }
    }
    return NULL;
}

int adicionar_aresta(const Grafo *g, const int idOrigem, const int idDestino, const int idAresta, const float tamanho) {
    if (g) {
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
        if (origem && destino && !verificar_aresta(origem, idAresta)) {
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
            // Inserindo na lista de arestas.
            origem->nAresta++;
            origem->a = a;
            return 1;
        }
    }
    return 0;
}

int remover_aresta(const Grafo *g, const int idVertice, const int idAresta) {
    if (g) {
        // Buscando o vértice.
        Vertice *v = verificar_vertice(g, idVertice);
        if (v) {
            // Buscando a aresta.
            Aresta *a = v->a, *anterior = NULL;
            while (a && a->id != idAresta) {
                anterior = a;
                a = a->prox;
            }
            // Remove a aresta caso ela exista.
            if (a) {
                if (anterior) {
                    anterior->prox = a->prox;
                }else {
                    v->a = a->prox;
                }
                v->nAresta--;
                free(a);
                return 1;
            }
        }
        return -1;
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
    const Vertice *v = g ? verificar_vertice(g, id) : NULL;
    // Retornando o grau.
    return !v ? -1 : v->nAresta;
}

double densidade(const Grafo *g) {
    double densidade = 0;
    if (g) {
        // Calculando a quantidade total de arestas.
        int arestas = 0;
        for (const Vertice *v = g->v; v; v = v->prox) {
            arestas += v->nAresta;
        }
        // Calculando a densidade.
        densidade = (double)arestas / (g->nVertices * (g->nVertices - 1));
    }
    return densidade;
}