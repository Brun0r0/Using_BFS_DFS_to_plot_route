#ifndef BUSCA_H
#define BUSCA_H

#include "grafo.h"

typedef struct {
    int encontrado;
    int tamanho;
    int* caminho;
    int passos;
} ResultadoBusca;

void zerarVisitados(int* visitados, int tamanho);
int buscaProfunda(Grafo* grafo, int verticeInicial, int* visitados);
ResultadoBusca buscarCaminhoProfundidade(Grafo* grafo, int origem, int destino, int numVertices);
ResultadoBusca buscarCaminhoLargura(Grafo* grafo, int origem, int destino, int numVertices);
int* reconstruirCaminho(int* pai, int origem, int destino, int* tamanho);

#endif