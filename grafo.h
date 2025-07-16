/**
 * @file grafo.h
 *
 * @brief Definição das funções para a manipulação de grafos dirigidos (dígrafos).
 *
 * @author HenriUz
 */

#ifndef GRAFO_H
#define GRAFO_H

/**
 * @struct Grafo
 *
 * @brief Representa um grafo dirigido contendo o número de vértices, e os vértices.
 *
 * Os vértices são manipulados em forma de lista encadeada, com inserção no início da lista.
 */
typedef struct Grafo Grafo;

/**
 * @struct Vertice
 *
 * @brief Representa um vértice contendo um identificador, o número de arestas, e as arestas.
 *
 * O número de arestas representa a quantidade de arestas incidentes do vértice, ou seja, seu grau de saída, e as arestas são manipuladas em forma de lista encadeada, com inserção no início da lista.
 */
typedef struct Vertice Vertice;

/**
 * @struct Aresta
 *
 * @brief Representa uma aresta contendo um identificados, um peso, e o vértice de destino.
 */
typedef struct Aresta Aresta;

/**
 * @brief Função de criação do grafo.
 *
 * Aloca espaço para uma estrutura do tipo Grafo, e inicializa seus valores.
 *
 * @retval g Ponteiro para a estrutura alocada.
 * @retval NULL Valor nulo se a alocação falhou.
 */
Grafo *criar_grafo();

/**
 * @brief Função de inserção de vértices.
 *
 * Aloca espaço para uma estrutura do tipo Vertice, e inicializa seus valores, atualizando o grafo em seguida.
 *
 * @param g Ponteiro para o grafo.
 * @param id Inteiro identificador do novo vértice.
 * @retval 1 Inserido com sucesso.
 * @retval 0 Vértice já existe ou grafo não existe.
 * @retval -1 Erro na alocação do vértice.
 */
int adicionar_vertice(Grafo *g, int id);

/**
 * @brief Função de remoção de vértices.
 *
 * Remove todas as arestas do grafo que tenham como destino o vértice informado, e remove o vértice com suas arestas.
 *
 * @param g Ponteiro para o grafo.
 * @param id Inteiro identificador do vértice que será removido.
 * @retval 1 Removido com sucesso.
 * @retval 0 Grafo não existe.
 * @retval -1 Vértice não existe.
 */
int remover_vertice(Grafo *g, int id);

/**
 * @brief Função de inserção de arestas.
 *
 * Aloca espaço para uma estrutura do tipo Aresta, e inicializa seus valores, atualizando o vértice em seguida.
 *
 * @param g Ponteiro para o grafo.
 * @param idOrigem Inteiro identificador do vértice de origem.
 * @param idDestino Inteiro identificador do vértice de destino.
 * @param idAresta Inteiro identificador da nova aresta.
 * @param tamanho Peso da nova aresta.
 * @retval 1 Inserido com sucesso.
 * @retval 0 Vértices ou grafo não existem.
 * @retval -1 Erro na alocação da aresta.
 */
int adicionar_aresta(const Grafo *g, int idOrigem, int idDestino, int idAresta, float tamanho);

/**
 * @brief Função de remoção de arestas.
 *
 * Remove a aresta especificada do vértice informado.
 *
 * @param g Ponteiro para o grafo.
 * @param idVertice Inteiro identificador do vértice de origem.
 * @param idAresta Inteiro identificador da aresta que será removida.
 * @retval 1 Removida com sucesso.
 * @retval 0 Grafo não existe.
 * @retval -1 Vértice ou aresta não existem.
 */
int remover_aresta(const Grafo *g, int idVertice, int idAresta);

/**
 * @brief Função de cálculo do grau de entrada.
 *
 * Calcula o grau de entrada do vértice, ou seja, o número de arestas que são incidentes a esse vértice.
 *
 * @param g Ponteiro para o grafo.
 * @param id Inteiro identificador do vértice.
 * @retval grau Grau de entrada do vértice.
 * @retval -1 Vértice ou grafo não existem.
 */
int grau_de_entrada(const Grafo *g, int id);

/**
 * @brief Função de cálculo do grau de saída.
 *
 * Calcula o grau de saída do vértice, ou seja, o número de arestas que são incidentes desse vértice.
 *
 * @param g Ponteiro para o grafo.
 * @param id Inteiro identificador do vértice.
 * @retval grau Grau de saída do vértice.
 * @retval -1 Vértice ou grafo não existem.
 */
int grau_de_saida(const Grafo *g, int id);

/**
 * @brief Função de cálculo da densidade.
 *
 * Calcula a densidade do grafo informado, com base na equação: E / (V * (V - 1)), sendo E o número total de arestas, e V o número total de vértices.
 *
 * @param g Ponteiro para o grafo.
 * @retval densidade Densidade do grafo.
 */
double densidade(const Grafo *g);

#endif //GRAFO_H
