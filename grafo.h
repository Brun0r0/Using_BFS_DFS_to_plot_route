#ifndef GRAFO_H
#define GRAFO_H

typedef struct Nodo{
    int localizacao;
    struct Nodo *prox;    
} nodo;

nodo* criaLista();
nodo* adicionaLista(nodo* lista, int L);
void liberaLista(nodo* lista);
void zerarVisitados(int visitados[], int tam);
int retornaVizinho(nodo* lista, int visitados[]);
int quantidadeVizinhos(nodo* lista, int visitados[]);

#endif