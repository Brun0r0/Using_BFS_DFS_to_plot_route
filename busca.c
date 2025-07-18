#include <stdlib.h>
#include <string.h>
#include "busca.h"
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
#include "grafo.h"

void zerarVisitados(int* visitados, int tamanho){
    for(int i = 0; i < tamanho; i++){
        visitados[i] = 0;
    }
}

int buscaProfunda(Grafo* grafo, int verticeInicial, int* visitados){
    Pilha *pilha = criarPilha();
    int tamTotal = 1;

    pushPilha(pilha, verticeInicial);
    visitados[verticeInicial] = 1;

    while(!pilhaVazia(pilha)){
        int atual = popPilha(pilha);

        nodo* vizinhos = obterVizinhos(grafo, atual);
        while(vizinhos != NULL){
            int vizinho = vizinhos->destino;

            if(!visitados[vizinho]){
                visitados[vizinho] = 1;
                pushPilha(pilha, vizinho);
                tamTotal++;
            }
            vizinhos = vizinhos->prox;
        }
    }

    free(pilha);
    return tamTotal;
}

    ResultadoBusca buscarCaminhoProfundidade(Grafo* grafo, int origem, int destino, int numVertices){
    ResultadoBusca resultado = {0, 0, NULL, 0};
    
    int* visitados = malloc(numVertices * sizeof(int));
    int* pai = malloc(numVertices * sizeof(int));
    
    zerarVisitados(visitados, numVertices);
    
    // Inicializar array de pais
    for(int i = 0; i < numVertices; i++){
        pai[i] = -1;
    }

    Pilha *pilha = criarPilha();
    pushPilha(pilha, origem);
    visitados[origem] = 1;

    while(!pilhaVazia(pilha)){
        int atual = popPilha(pilha);

        if(atual == destino){
            resultado.encontrado = 1;
            break;
        }

        nodo* vizinhos = obterVizinhos(grafo, atual);
        while(vizinhos != NULL){
            int vizinho = vizinhos->destino;

            if(!visitados[vizinho]){
                visitados[vizinho] = 1;
                pushPilha(pilha, vizinho);
                pai[vizinho] = atual;
            }
            vizinhos = vizinhos->prox;
        }
    }

    if(resultado.encontrado){
        resultado.caminho = reconstruirCaminho(pai, origem, destino, &resultado.tamanho);
        resultado.passos = resultado.tamanho - 1;
    }

    free(visitados);
    free(pai);
    free(pilha);
    return resultado;
}

ResultadoBusca buscarCaminhoLargura(Grafo* grafo, int origem, int destino, int numVertices){
    ResultadoBusca resultado = {0, 0, NULL, 0};
    
    int* visitados = malloc(numVertices * sizeof(int));
    int* pai = malloc(numVertices * sizeof(int));
    
    zerarVisitados(visitados, numVertices);
    
    // Inicializar array de pais
    for(int i = 0; i < numVertices; i++){
        pai[i] = -1;
    }

    Fila *fila = criaFila();
    pushFila(fila, origem);
    visitados[origem] = 1;

    while(!filaVazia(fila)){
        int atual = popFila(fila);
        
        if(atual == destino){
            resultado.encontrado = 1;
            break;
        }

        nodo* vizinhos = obterVizinhos(grafo, atual);
        while(vizinhos != NULL){
            int vizinho = vizinhos->destino;

            if(!visitados[vizinho]){
                visitados[vizinho] = 1;
                pushFila(fila, vizinho);
                pai[vizinho] = atual;
            }
            vizinhos = vizinhos->prox;
        }
    }

    if(resultado.encontrado){
        resultado.caminho = reconstruirCaminho(pai, origem, destino, &resultado.tamanho);
        resultado.passos = resultado.tamanho - 1;
    }

    free(visitados);
    free(pai);
    free(fila);
    return resultado;
}

int* reconstruirCaminho(int* pai, int origem, int destino, int* tamanho){
    // Contar o tamanho do caminho
    int contador = 0;
    int atual = destino;
    while(atual != origem){
        contador++;
        atual = pai[atual];
    }
    contador++; // Incluir a origem
    
    *tamanho = contador;
    
    int* caminho = malloc(contador * sizeof(int));
    atual = destino;
    
    // Preencher o caminho de trás para frente
    for(int i = contador - 1; i >= 0; i--){
        caminho[i] = atual;
        atual = pai[atual];
    }
    
    return caminho;
}