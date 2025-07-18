#ifndef MAPA_H
#define MAPA_H

#include "grafo.h"

typedef struct {
    int linha;
    int coluna;
} Posicao;

typedef struct {
    int quantidade;
    int maiorTamanho;
    int menorTamanho;
} InfoIlhas;

char** criarMapa(int N, int M);
void lerMapa(char** mapa, char** auxMapa, int N, int M, Posicao* tesouro, Posicao* locInicial);
void liberarMapa(char** mapa, int N);
void imprimirMapa(char** mapa, int N, int M);
void construirGrafoMapa(Grafo* grafo, char** mapa, int N, int M);
InfoIlhas analisarIlhas(Grafo* grafo, char** mapa, int N, int M);
void marcarCaminhoMapa(char** mapa, int* caminho, int tamanho, int M);

#endif