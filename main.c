#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "grafo.h"
#include "busca.h"
#include "mapa.h"

int main(){
    int N, M;
    
    scanf("%d", &N);
    scanf("%d", &M);

    char** mapa = criarMapa(N, M);
    char** auxMapa = criarMapa(N, M);
    
    Posicao tesouro, locInicial;
    lerMapa(mapa, auxMapa, N, M, &tesouro, &locInicial);

    // Criar o grafo
    int vertices = N * M;
    Grafo* grafo = criarGrafo(vertices);
    construirGrafoMapa(grafo, mapa, N, M);

    // Análise das ilhas
    InfoIlhas infoIlhas = analisarIlhas(grafo, mapa, N, M);
    
    printf("Ha %d ilhas(s)\n", infoIlhas.quantidade);
    printf("A maior tem tamanho %d\n", infoIlhas.maiorTamanho);
    printf("A menor tem tamanho %d", infoIlhas.menorTamanho);

    // Buscar caminho para o tesouro
    int locInicialVertice = locInicial.linha * M + locInicial.coluna;
    int tesouroVertice = tesouro.linha * M + tesouro.coluna;
    
    ResultadoBusca resultadoDFS = buscarCaminhoProfundidade(grafo, locInicialVertice, tesouroVertice, vertices);
    ResultadoBusca resultadoBFS = buscarCaminhoLargura(grafo, locInicialVertice, tesouroVertice, vertices);

    if(resultadoDFS.encontrado){
        printf("\n\n");
        printf("Busca em profundidade:");
        marcarCaminhoMapa(mapa, resultadoDFS.caminho, resultadoDFS.tamanho, M);
        imprimirMapa(mapa, N, M);
        printf("\n%d passo(s)", resultadoDFS.passos);

        printf("\n\n");
        printf("Busca em largura:");
        marcarCaminhoMapa(auxMapa, resultadoBFS.caminho, resultadoBFS.tamanho, M);
        imprimirMapa(auxMapa, N, M);
        printf("\n%d passo(s)", resultadoBFS.passos);
    }
    else {
        printf("\nNao ha caminho para o tesouro");
    }

    printf("\n");

    // Limpeza
    liberarMapa(mapa, N);
    liberarMapa(auxMapa, N);
    liberarGrafo(grafo);
    
    if(resultadoDFS.encontrado) {
        free(resultadoDFS.caminho);
    }
    if(resultadoBFS.encontrado) {
        free(resultadoBFS.caminho);
    }

    return 0;
}