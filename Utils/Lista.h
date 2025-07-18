/**
 * @file Lista.h
 *
 * @brief Definição das funções de uma lista de ponteiros.
 *
 * @author HenriUz
 */

#ifndef LISTA_H
#define LISTA_H

/**
 * @struct Lista
 *
 * @brief Representa uma lista encadeada simples.
 */
typedef struct Lista Lista;

/**
 * @struct No
 *
 * @brief Representa os elementos de uma lista.
 *
 * O elemento principal da lista é um ponteiro do tipo void, dessa forma a lista pode ser usada para qualquer dado, desde que se faça o cast corretamente.
 */
typedef struct No No;

/**
 * @brief Função de criação da lista.
 *
 * Aloca espaço para uma estrutura do tipo Lista, e inicializa seus valores.
 *
 * @retval l Ponteiro para a estrutura alocada.
 * @retval NULL Erro na alocação da lista.
 */
Lista *criar_lista();

/**
 * @brief Retorna a quantidade de nós na lista.
 *
 * @param l Ponteiro para a lista.
 *
 * @retval nos Número de nós na lista.
 */
int quantidade_nos(const Lista *l);

/**
 * @brief Função de inserção de nós.
 *
 * Aloca espaço para uma estrutura do tipo nó, e em seguida inicializa seus valores e insere na lista. A função apenas insere se o índice for válido, ou seja, se estiver entre 0 e o tamanho da lista (inserção no final da lista).
 *
 * @param l Ponteiro para a lista.
 * @param ptr Ponteiro para o elemento.
 * @param indice Posição do novo nó - [0, n].
 *
 * @retval 1 Inserido com sucesso.
 * @retval 0 Lista não existe, ou índice inválido.
 * @retval -1 Erro na alocação do nó.
 */
int adicionar_no(Lista *l, void *ptr, int indice);

/**
 * @brief Função de remoção de nós.
 *
 * Remove um nó da lista, retornando seu valor. A função apenas remove se o índice for válido, ou seja, se estiver entre 0 e o tamanho da lista menos 1.
 *
 * @param l Ponteiro para a lista.
 * @param indice Posição do nó - [0, n - 1].
 *
 * @retval ptr Ponteiro para o elemento armazenado no nó.
 * @retval NULL Lista não existe, ou índice inválido.
 */
void *remover_no(Lista *l, int indice);

/**
 * @brief Função de esvaziamento da lista.
 *
 * Remove todos os nós da lista, liberando a lista em seguida. Os elementos armazenados nos nós não são liberados.
 *
 * @param l Endereço do ponteiro para a lista.
 */
void esvaziar_lista(Lista **l);

#endif //LISTA_H
