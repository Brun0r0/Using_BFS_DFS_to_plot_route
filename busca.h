#ifndef BUSCA_H
#define BUSCA_H

#include "grafo.h"

int buscaProfunda(nodo **lista, int terra, int visitados[]);
int tesouroProfundidade(nodo **lista, int localizacao, int tesouro, int visitados[], int pai[]);
void tesouroLargura(nodo **lista, int localizacao, int tesouro, int visitados[], int pai[]);

#endif