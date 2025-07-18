#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

Grafo* criarGrafo(int vertices){
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->numVertices = vertices;

    grafo->listaAdj = malloc(vertices * sizeof(nodo*));
    for(int i = 0; i < vertices; i++){
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino){
    // Verificar se a aresta já existe para evitar duplicatas
    if(verificarAresta(grafo, origem, destino)){
        return;
    }

    // Adiciona o destino na lista de origem
    nodo* novoNodo1 = (nodo*) malloc(sizeof(nodo));
    novoNodo1->destino = destino;
    novoNodo1->prox = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNodo1;

    // Adiciona origem na lista de destino (grafo não direcionado)
    nodo* novoNodo2 = malloc(sizeof(nodo));
    novoNodo2->destino = origem;
    novoNodo2->prox = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novoNodo2;
}

int verificarAresta(Grafo* grafo, int origem, int destino){
    if(grafo == NULL || origem < 0 || origem >= grafo->numVertices){
        return 0;
    }
    
    nodo* atual = grafo->listaAdj[origem];
    while(atual != NULL){
        if(atual->destino == destino){
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

nodo* obterVizinhos(Grafo* grafo, int vertice){
    if(grafo == NULL || vertice < 0 || vertice >= grafo->numVertices){
        return NULL;
    }
    return grafo->listaAdj[vertice];
}

void liberarGrafo(Grafo* grafo){
    if(grafo == NULL) return;
    
    for(int i = 0; i < grafo->numVertices; i++){
        nodo* atual = grafo->listaAdj[i];
        while(atual != NULL){
            nodo* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    free(grafo->listaAdj);
    free(grafo);
}