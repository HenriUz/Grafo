#ifndef GRAFO_H
#define GRAFO_H

typedef struct Grafo Grafo;
typedef struct Vertice Vertice;
typedef struct Aresta Aresta;

/*
Descrição: função responsável por criar e inicializar uma estrutura Grafo.
Entrada: nada.
Saída: ponteiro para a estrutura criada.
*/
Grafo *cria_grafo();

/*
Descrição: função responsável por criar e adicionar um vértice ao grafo.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: 1 - sucesso, 0 - vértice já existente ou grafo não existente, −1 - erro na alocação de memória.
*/
int adiciona_vertice(Grafo *g, int id);

/*
Descrição: função responsável por criar e adicionar uma aresta ao vértice.
Entrada: ponteiro para o grafo, inteiro do id do vértice de origem, inteiro do id da aresta, inteiro do id do vértice de destino, ponto flutuante do tamanho da aresta.
Saída: 1 - sucesso, 0 - vértice ou grafo não existente, ou a aresta já existe, −1 - erro na alocação de memória.
*/
int adiciona_aresta(const Grafo *g, int idVertice, int idAresta, int idDestino, float tamanho);

/*
Descrição: função responsável por retornar o grau de entrada de um vértice.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: grau de entrada, −1 - vértice não existente.
*/
int grau_de_entrada(const Grafo *g, int id);

/*
Descrição: função responsável por retornar o grau de saída de um vértice.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: grau de saída, −1 - vértice não existente.
*/
int grau_de_saida(const Grafo *g, int id);

#endif //GRAFO_H
