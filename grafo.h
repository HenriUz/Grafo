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
Descrição: função responsável por criar um vértice e adicionar no grafo.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: 1 - sucesso, 0 - vértice já existente ou grafo não existente, −1 - erro na alocação de memória.
*/
int adiciona_vertice(Grafo *g, int id);

/*
Descrição: função responsável por verificar se um vértice já existe em um grafo.
Entrada: ponteiro para o grafo, inteiro do id do vértice.
Saída: 1 - vértice existe, 0 - vértice não existe.
*/
int verifica_vertice(const Grafo *g, int id);

#endif //GRAFO_H
