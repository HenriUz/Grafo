#ifndef GRAFO_H
#define GRAFO_H

typedef struct Grafo Grafo;
typedef struct Vertice Vertice;
typedef struct Aresta Aresta;

/*
Descrição: função responsável por criar e inicializar um grafo.
Entrada: nada.
Saída: ponteiro para o grafo, e nulo caso um erro tenha ocorrido.
*/
Grafo *cria_grafo();

/*
Descrição: função responsável por criar e adicionar um vértice ao grafo.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: 1 - sucesso, 0 - vértice já existe ou grafo não existe, −1 - erro na alocação de memória.
*/
int adiciona_vertice(Grafo *g, int id);

/*
Descrição: função responsável por criar e adicionar uma aresta ao vértice.
Entrada: ponteiro para o grafo, inteiro do id do vértice de origem, inteiro do id do vértice de destino, inteiro do id da aresta, ponto flutuante do tamanho da aresta.
Saída: 1 - sucesso, 0 - vértices ou grafo não existe, ou a aresta já existe, −1 - erro na alocação de memória.
*/
int adiciona_aresta(const Grafo *g, int idOrigem, int idDestino, int idAresta, float tamanho);

/*
Descrição: função responsável por retornar o grau de entrada de um vértice.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: grau de entrada, −1 - vértice ou grafo não existe.
*/
int grau_de_entrada(const Grafo *g, int id);

/*
Descrição: função responsável por retornar o grau de saída de um vértice.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: grau de saída, −1 - vértice ou grafo não existe.
*/
int grau_de_saida(const Grafo *g, int id);

/*
Descrição: função responsável por calcular a densidade do grafo.
Entrada: ponteiro para o grafo.
Saída: double da densidade calculada.
*/
double densidade(const Grafo *g);

#endif //GRAFO_H
