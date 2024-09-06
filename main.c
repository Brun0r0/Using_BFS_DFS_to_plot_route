#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaEstatica.h"
#include "FilaEstatica.h"

typedef struct Nodo
{
    int localizacao;
    struct Nodo *prox;
}nodo;

nodo *criaLista()
{
    nodo *novo = (nodo *) malloc(sizeof(nodo));
    novo = NULL;
    return novo;
}

nodo *adicionaLista(nodo *lista, int L)
{
    nodo *novo = (nodo *) malloc(sizeof(nodo));
    novo->localizacao = L;
    novo->prox = lista;
    return novo;
}

int retornaVizinho(nodo *lista, int visitados[])     /*Retorna os vizinhos n�o visitados*/
{
    int aux = lista->localizacao;

    if(visitados[aux] == 0)
        return aux;

    retornaVizinho(lista->prox, visitados);
}

int quantidadeVizinhos(nodo *lista, int visitados[])     /*Fun��o para verificar a quantidade de vizinhos n�o visitados*/
{
    if(lista == NULL)
        return 0;

    int aux = lista->localizacao;

    if(visitados[aux] == 1)
        return quantidadeVizinhos(lista->prox, visitados);

    return 1 + quantidadeVizinhos(lista->prox, visitados);
}

int busca_profunda(nodo **lista, int terra, int visitados[])     /*Fun��o para pegar o tamanho das terras com busca em profundidade*/
{
    Pilha *pilha = cria_pilha();
    int tamTotal = 1;
    int qtdViz;
    int vizinho;
    int vazia = 0;

    push_pilha(pilha, terra);

    visitados[terra] = 1;

    while(vazia != 1)     /*Enquanto a pilha n�o estiver vazia fica em loop*/
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


int tesouroProfundidade(nodo **lista, int localizacao, int tesouro, int visitados[], int pai[])     /*Funcao para fazer caminho para o tesouro usando busca em profundidade, retorna se ha ou nao caminho para o tesouro*/
{
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

    if(visitados[tesouro] == 1)     /*Verifica se ha caminho para o tesouro*/
        return 1;

    return 0;

}

void tesouroLargura(nodo **lista, int localizacao, int tesouro, int visitados[], int pai[])     /*Funcao para fazer caminho para o tesouro usando busca em largura*/
{
    Fila *fila = criaFila();
    int qntViz;
    int vizinho;
    int vazia = 0;

    visitados[localizacao] = 1;
    push_fila(fila, localizacao);

    while(vazia != 1)
    {
        localizacao = pop_fila(fila);

        qntViz = quantidadeVizinhos(lista[localizacao], visitados);

        for(int i = 0; qntViz > i; i++)     /*Dependendo do numero de vizinhos de terra faz esse la�o para adicionar valores a fila*/
        {
            vizinho = retornaVizinho(lista[localizacao], visitados);
            push_fila(fila, vizinho);
            visitados[vizinho] = 1;
            pai[vizinho] = localizacao;     /*Adiciona no vetor pai, na posi��o vizinho o valor de localiza��o*/
        }

        vazia = vazia_fila(fila);
    }

    free(fila);
}


void zerarVisitados(int visitados[], int tam)     /*Fun��o para zerar o vetor visitados*/
{
    for(int i = 0; tam > i; i++)
        visitados[i] = 0;
}


void libera(nodo *lista)     /*Fun��o para liberar a lista*/
{
    if(lista == NULL) return;
    libera(lista->prox);
    free(lista);
    return;
}


int main()
{
    int N, M;
    int i;
    int tam;
    int viz[4];
    int tesouro, localizacao;
    int maior_ilha = 0;
    int menor_ilha = 10000;
    int visitados[10000] = {0};
    int DFS[10000];
    int BFS[10000];
    int sair = 0;


    scanf("%d", &N);
    scanf("%d", &M);

    tam = N * M;     /*Armazena o tamanho da mapa*/

    char *arm = (char *) malloc(tam * sizeof(char));

    char *copy = (char *) malloc(tam * sizeof(char));

    nodo **lista = (nodo **) malloc(tam * sizeof(nodo*));

    for(i = 0; tam > i; i++)     /*la�o para adicionar as caracteres no vetor*/
    {
        scanf("%c", &arm[i]);
        copy[i] = arm[i];

        if(arm[i] == 'X')
            tesouro = i;

        if(arm[i] == 'L')
            localizacao = i;

        if(arm[i] == '\n') i--;
    }


    for(i = 0; tam > i; i++)     /*La�o para adicionar os vizinhos no vetor de listas*/
    {
            lista[i] = criaLista();

            viz[0] = i - M;     /*Pega o vizinho de cima*/
            viz[1] = i + 1;     /*Pega o vizinho da direita*/
            viz[2] = i + M;     /*Pega o vizinho de baixo*/
            viz[3] = i - 1;     /*Pega o vizinho da esquerda*/

            if(i == 0)     /*Primeira terra*/
            {
                if(arm[viz[2]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[2]);}
                if(arm[viz[1]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[1]);}
            }

            else if(i == (M - 1))     /*Vizinho da coordenada final da 1 linha*/
            {
                if(arm[viz[3]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[3]);}
                if(arm[viz[2]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[2]);}
            }

            else if(i == (tam - M))     /*Vizinho da 1 coordenada  da linha final*/
            {
                if(arm[viz[1]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[1]);}
                if(arm[viz[0]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[0]);}
            }

            else if(i == (tam - 1))     /*Vizinho da ultima coordenada*/
            {
                if(arm[viz[3]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[3]);}
                if(arm[viz[0]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[0]);}
            }

            else if(i < M)     /*Vizinhos da 1 linha*/
            {
                if(arm[viz[3]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[3]);}
                if(arm[viz[2]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[2]);}
                if(arm[viz[1]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[1]);}
            }

            else if(i > (tam - M))     /*Vizinhos da ultima linha*/
            {
                if(arm[viz[3]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[3]);}
                if(arm[viz[1]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[1]);}
                if(arm[viz[0]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[0]);}
            }

            else if((i % M) == 0)     /*Vizinhos da 1 coluna*/
            {
                if(arm[viz[2]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[2]);}
                if(arm[viz[1]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[1]);}
                if(arm[viz[0]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[0]);}
            }

            else if((i % M) == (M - 1))     /*Vizinhos da ultima coluna*/
            {
                if(arm[viz[3]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[3]);}
                if(arm[viz[2]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[2]);}
                if(arm[viz[0]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[0]);}
            }

            else     /*Vizinhos dos termos centrais*/
            {
                if(arm[viz[3]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[3]);}
                if(arm[viz[2]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[2]);}
                if(arm[viz[1]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[1]);}
                if(arm[viz[0]]!= '.'){
                    lista[i] = adicionaLista(lista[i], viz[0]);}
            }
    }

    int qnt_ilha = 0;
    int tamanho_ilha;

    for(i=0; i<tam; i++)     /*La�o para pegar o tamanho das ilhas e a quantidade de ilhas*/
    {
        if(arm[i] != '.' && visitados[i] != 1)
        {
            tamanho_ilha = busca_profunda(lista, i, visitados);

            if(tamanho_ilha > maior_ilha)
                maior_ilha = tamanho_ilha;

            if(tamanho_ilha < menor_ilha)
                menor_ilha = tamanho_ilha;

            qnt_ilha++;
        }
    }

    zerarVisitados(visitados, tam);

    int haCaminho = tesouroProfundidade(lista, localizacao, tesouro, visitados, DFS);     /*Fun��o  caminho de localiza��o at� o tesouro com busca em profundidade, com retorno de 1 ou 0 se tem caminho*/

    zerarVisitados(visitados, tam);

    int x = tesouro;

    int passosProfundo = 0;

     if(haCaminho == 1)
    {
        while(sair != 1)     /*Loop para as setas no mapa*/
        {
            if(DFS[x] == localizacao)     /*Marca o ultimo la�o*/
                sair = 1;

            if(DFS[x] == x + 1)
                arm[DFS[x]] = '<';

            else if(DFS[x] == x - 1)
                arm[DFS[x]] = '>';

            else if(DFS[x] > x)
                arm[DFS[x]] = '^';

            else if(DFS[x] < x)
                arm[DFS[x]] = 'v';

            x = DFS[x];
            passosProfundo++;
        }
    }

    tesouroLargura(lista, localizacao, tesouro, visitados, BFS);     /*Fun��o para pegar o caminho de localiza��o at� o tesouro com busca em largura*/

    sair = 0;

    x = tesouro;

    int passosLargos = 0;

    if(haCaminho == 1)
    {
        while(sair != 1)
        {
            if(BFS[x] == localizacao)
                sair = 1;

            if(BFS[x] == x + 1)
                copy[BFS[x]] = '<';

            else if(BFS[x] == x - 1)
                copy[BFS[x]] = '>';

            else if(BFS[x] > x)
                copy[BFS[x]] = '^';

            else if(BFS[x] < x)
                copy[BFS[x]] = 'v';

            x = BFS[x];
            passosLargos++;
        }
    }

    printf("Ha %d ilhas(s)\n", qnt_ilha);
    printf("A maior tem tamanho %d\n", maior_ilha);
    printf("A menor tem tamanho %d", menor_ilha);

    if(haCaminho == 1)
    {
        printf("\n\n");
        printf("Busca em profundidade:");
        for(i = 0; tam > i; i++)
        {
            if(i % M == 0) printf("\n");
            printf("%c", arm[i]);
        }
        printf("\n%d passo(s)", passosProfundo);


        printf("\n\n");
        printf("Busca em largura:");
        for(i = 0; tam > i; i++)
        {
            if(i % M == 0) printf("\n");
            printf("%c", copy[i]);
        }
        printf("\n%d passo(s)", passosLargos);
    }
    else
        printf("\nNao ha caminho para o tesouro");

    printf("\n");

    for(i = 0; tam > i; i++)
    {
        libera(lista[i]);
    }
    
    free(lista);
    free(copy);
    free(arm);

    return 0;
}
