/**
 * @file Lista.c
 *
 * @brief Implementação das funções de uma lista de ponteiros.
 *
 * @author HenriUz
 */

#include <stdlib.h>
#include "Lista.h"

struct Lista {
    int nos;    /**< Quantidade de nós na lista. */
    No *n;      /**< Nó inicial da lista. */
};

struct No {
    void *ptr;  /**< Ponteiro para o elemento. */
    No *prox;   /**< Próximo elemento da lista. */
};

Lista *criar_lista() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    // Verificando se o chunk foi alocado corretamente.
    if (!l) {
        return NULL;
    }
    // Inicializando seus valores.
    l->nos = 0;
    l->n = NULL;
    return l;
}

int quantidade_nos(const Lista *l) {
    return !l ? 0 : l->nos;
}

int adicionar_no(Lista *l, void *ptr, const int indice) {
    if (l && indice >= 0 && indice <= l->nos) {
        No *no = (No *)malloc(sizeof(No));
        // Verificando se o chunk foi alocado corretamente.
        if (!no) {
            return -1;
        }
        // Inserindo o nó. Caso não seja no início, busca o nó de posição índice - 1.
        if (indice == 0) {
            no->prox = l->n;
            l->n = no;
        }else {
            No *n = l->n;
            for (int i = 1; i < indice; i++) {
                n = n->prox;
            }
            no->prox = n->prox;
            n->prox = no;
        }
        no->ptr = ptr;
        l->nos++;
        return 1;
    }
    return 0;
}

void *remover_no(Lista *l, const int indice) {
    if (l && indice >= 0 && indice < l->nos) {
        // Buscando o nó.
        No *nAnterior = NULL, *n = l->n;
        for (int i = 0; i < indice; i++) {
            nAnterior = n;
            n = n->prox;
        }
        // Removendo o nó da lista.
        if (!nAnterior) {
            l->n = n->prox;
        }else {
            nAnterior->prox = n->prox;
        }
        l->nos--;
        // Liberando o nó e retornando seu valor.
        void *ptr = n->ptr;
        free(n);
        return ptr;
    }
    return NULL;
}

void esvaziar_lista(Lista **l) {
    // Removendo nós da lista.
    while ((*l)->n) {
        No *n = (*l)->n;
        (*l)->n = (*l)->n->prox;
        free(n);
    }
    // Liberando a lista.
    free(*l);
    *l = NULL;
}