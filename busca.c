#include <stdlib.h>
#include "busca.h"
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
#include "grafo.h"

int buscaProfunda(nodo **lista, int terra, int visitados[]){
    Pilha *pilha = cria_pilha();
    int tamTotal = 1;
    int qtdViz;
    int vizinho;
    int vazia = 0;

    push_pilha(pilha, terra);

    visitados[terra] = 1;

    while(vazia != 1)
    {
        terra = pop_pilha(pilha);

        qtdViz = quantidadeVizinhos(lista[terra], visitados);

        for(int i = 0; qtdViz > i; i++)
        {
            vizinho = retornaVizinho(lista[terra], visitados);
            push_pilha(pilha, vizinho);
            visitados[vizinho] = 1;
            tamTotal++;
        }

        vazia = vazia_pilha(pilha);
    }

    free(pilha);
    return tamTotal;
}

int tesouroProfundidade(nodo **lista, int localizacao, int tesouro, int visitados[], int pai[]){
    Pilha *pilha = cria_pilha();
    int qntViz;
    int vizinho;
    int vazia = 0;

    visitados[localizacao] = 1;
    push_pilha(pilha, localizacao);

    while(vazia != 1)
    {
        localizacao = pop_pilha(pilha);

        qntViz = quantidadeVizinhos(lista[localizacao], visitados);

        for(int i = 0; qntViz > i; i++)
        {
            vizinho = retornaVizinho(lista[localizacao], visitados);
               push_pilha(pilha, vizinho);
            visitados[vizinho] = 1;
            pai[vizinho] = localizacao;
        }

        vazia = vazia_pilha(pilha);
    }

    free(pilha);

    if(visitados[tesouro] == 1)
        return 1;

    return 0;

}

void tesouroLargura(nodo **lista, int localizacao, int tesouro, int visitados[], int pai[]){
    Fila *fila = criaFila();
    int qntViz;
    int vizinho;
    int vazia = 0;

    visitados[localizacao] = 1;
    push_fila(fila, localizacao);

    while(vazia != 1){
        localizacao = pop_fila(fila);

        qntViz = quantidadeVizinhos(lista[localizacao], visitados);

        for(int i = 0; qntViz > i; i++)     /*Dependendo do numero de vizinhos de terra faz esse laço para adicionar valores a fila*/
        {
            vizinho = retornaVizinho(lista[localizacao], visitados);
            push_fila(fila, vizinho);
            visitados[vizinho] = 1;
            pai[vizinho] = localizacao;     /*Adiciona no vetor pai, na posição vizinho o valor de localização*/
        }

        vazia = vazia_fila(fila);
    }

    free(fila);
}