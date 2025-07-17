#include <stdlib.h>
#include "grafo.h"

nodo* criaLista(){
    return NULL;
}

nodo* adicionaLista(nodo* lista, int L){
    nodo* novo = (nodo*) malloc(sizeof(nodo));
    novo->localizacao = L;
    novo->prox = lista;
    return novo;
}

void liberaLista(nodo* lista){
    if (lista == NULL) return;
    liberaLista(lista->prox);
    free(lista);
}

void zerarVisitados(int visitados[], int tam){
    for(int i = 0; tam > i; i++)
        visitados[i] = 0;
}

int retornaVizinho(nodo *lista, int visitados[]){
    if(lista == NULL) return -1;

    int aux = lista->localizacao;

    if(visitados[aux] == 0)
        return aux;

    retornaVizinho(lista->prox, visitados);
}

int quantidadeVizinhos(nodo *lista, int visitados[]){     /*Função para verificar a quantidade de vizinhos não visitados*/
    if(lista == NULL)
        return 0;

    int v = lista->localizacao;

    if(visitados[v] == 1)
        return quantidadeVizinhos(lista->prox, visitados);

    return 1 + quantidadeVizinhos(lista->prox, visitados);
}