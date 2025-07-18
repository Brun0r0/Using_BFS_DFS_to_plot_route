#ifndef GRAFO_H
#define GRAFO_H

typedef struct Nodo{
    int destino;
    struct Nodo *prox;    
} nodo;

typedef struct {
    int numVertices;
    nodo** listaAdj;
} Grafo;

Grafo* criarGrafo(int vertices);
void adicionarAresta(Grafo* grafo, int origem, int destino);
int verificarAresta(Grafo* grafo, int origem, int destino);
void liberarGrafo(Grafo* grafo);
nodo* obterVizinhos(Grafo* grafo, int vertice);

#endif