#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "grafo.h"
#include "busca.h"

char** criarMapa(int N, int M){
    char** mapa = malloc(N * sizeof(char*));
    for(int i = 0; i < N; i++){
        mapa[i] = malloc(M * sizeof(char));
    }
    return mapa;
}

void lerMapa(char** mapa, char** auxMapa, int N, int M, Posicao* tesouro, Posicao* locInicial){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &mapa[i][j]);
            auxMapa[i][j] = mapa[i][j];
    
            if(mapa[i][j] == 'X'){
                tesouro->linha = i; 
                tesouro->coluna = j;
            }
    
            if(mapa[i][j] == 'L'){
                locInicial->linha = i;
                locInicial->coluna = j;
            }
        }
    }
}

void liberarMapa(char** mapa, int N){
    for(int i = 0; i < N; i++){
        free(mapa[i]);
    }
    free(mapa);
}

void imprimirMapa(char** mapa, int N, int M){
    for(int i = 0; i < N; i++){
        printf("\n");
        for(int j = 0; j < M; j++){
            printf("%c", mapa[i][j]);
        }
    }
}

void construirGrafoMapa(Grafo* grafo, char** mapa, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mapa[i][j] == '.') continue; // Pula água
            
            int verticeAtual = i * M + j;

            // Conectar com vizinho de baixo
            if(i < N - 1 && mapa[i+1][j] != '.'){
                adicionarAresta(grafo, verticeAtual, (i+1) * M + j);
            }

            // Conectar com vizinho da direita
            if(j < M - 1 && mapa[i][j+1] != '.'){
                adicionarAresta(grafo, verticeAtual, i * M + (j+1));
            }
        }
    }
}

InfoIlhas analisarIlhas(Grafo* grafo, char** mapa, int N, int M){
    InfoIlhas info = {0, 0, 10000};
    int vertices = N * M;
    int* visitados = malloc(vertices * sizeof(int));
    
    zerarVisitados(visitados, vertices);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int vertice = i * M + j;
            
            if(mapa[i][j] != '.' && !visitados[vertice]){
                int tamanhoIlha = buscaProfunda(grafo, vertice, visitados);
                
                if(tamanhoIlha > info.maiorTamanho){
                    info.maiorTamanho = tamanhoIlha;
                }
                
                if(tamanhoIlha < info.menorTamanho){
                    info.menorTamanho = tamanhoIlha;
                }
                
                info.quantidade++;
            }
        }
    }

    free(visitados);
    return info;
}

void marcarCaminhoMapa(char** mapa, int* caminho, int tamanho, int M){
    for(int i = 0; i < tamanho - 1; i++){
        int atual = caminho[i];
        int proximo = caminho[i + 1];
        
        int linhaAtual = atual / M;
        int colunaAtual = atual % M;
        
        if(mapa[linhaAtual][colunaAtual] == 'L' || mapa[linhaAtual][colunaAtual] == 'X'){
            continue; // Não alterar posição inicial nem tesouro
        }
        
        // Determinar direção
        if(proximo == atual + 1){
            mapa[linhaAtual][colunaAtual] = '>';
        }
        else if(proximo == atual - 1){
            mapa[linhaAtual][colunaAtual] = '<';
        }
        else if(proximo > atual){
            mapa[linhaAtual][colunaAtual] = 'v';
        }
        else if(proximo < atual){
            mapa[linhaAtual][colunaAtual] = '^';
        }
    }
}