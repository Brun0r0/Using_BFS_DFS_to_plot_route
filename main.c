#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "busca.h" 

int main(){
    int N, M;
    int tam;
    int tesouro, localizacao;
    int visitados[10000] = {0};
    int DFS[10000];
    int BFS[10000];
    int sair = 0;

    scanf("%d", &N);
    scanf("%d", &M);

    // Tamanho do mapa
    tam = N * M;

    char* mapa = (char*) malloc(tam * sizeof(char));
    char* auxMapa = (char*) malloc(tam * sizeof(char));

    // Caracteres do mapa
    for(int i = 0; tam > i; i++){
        scanf("%c", &mapa[i]);
        auxMapa[i] = mapa[i];

        if(mapa[i] == 'X')
            tesouro = i;

        if(mapa[i] == 'L')
            localizacao = i;

        if(mapa[i] == '\n') i--;
    }

    nodo** lista = (nodo**) malloc(tam * sizeof(nodo*));
    int viz[4];

    // Vizinhos de cada um
    for(int i = 0; tam > i; i++){
        lista[i] = criaLista();

        viz[0] = i - M;     /*Pega o vizinho de cima*/
        viz[1] = i + 1;     /*Pega o vizinho da direita*/
        viz[2] = i + M;     /*Pega o vizinho de baixo*/
        viz[3] = i - 1;     /*Pega o vizinho da esquerda*/

        if(i == 0)     /*Primeira terra*/
        {
            if(mapa[viz[2]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[2]);}
            if(mapa[viz[1]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[1]);}
        }

        else if(i == (M - 1))     /*Vizinho da coordenada final da 1 linha*/
        {
            if(mapa[viz[3]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[3]);}
            if(mapa[viz[2]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[2]);}
        }

        else if(i == (tam - M))     /*Vizinho da 1 coordenada  da linha final*/
        {
            if(mapa[viz[1]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[1]);}
            if(mapa[viz[0]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[0]);}
        }

        else if(i == (tam - 1))     /*Vizinho da ultima coordenada*/
        {
            if(mapa[viz[3]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[3]);}
            if(mapa[viz[0]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[0]);}
        }

        else if(i < M)     /*Vizinhos da 1 linha*/
        {
            if(mapa[viz[3]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[3]);}
            if(mapa[viz[2]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[2]);}
            if(mapa[viz[1]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[1]);}
        }

        else if(i > (tam - M))     /*Vizinhos da ultima linha*/
        {
            if(mapa[viz[3]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[3]);}
            if(mapa[viz[1]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[1]);}
            if(mapa[viz[0]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[0]);}
        }

        else if((i % M) == 0)     /*Vizinhos da 1 coluna*/
        {
            if(mapa[viz[2]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[2]);}
            if(mapa[viz[1]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[1]);}
            if(mapa[viz[0]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[0]);}
        }

        else if((i % M) == (M - 1))     /*Vizinhos da ultima coluna*/
        {
            if(mapa[viz[3]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[3]);}
            if(mapa[viz[2]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[2]);}
            if(mapa[viz[0]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[0]);}
        }

        else     /*Vizinhos dos termos centrais*/
        {
            if(mapa[viz[3]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[3]);}
            if(mapa[viz[2]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[2]);}
            if(mapa[viz[1]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[1]);}
            if(mapa[viz[0]]!= '.'){
                lista[i] = adicionaLista(lista[i], viz[0]);}
        }
    }

    int qnt_ilha = 0;
    int tamanho_ilha;
    int maior_ilha = 0;
    int menor_ilha = 10000;

    for(int i=0; i<tam; i++)     /*Laço para pegar o tamanho das ilhas e a quantidade de ilhas*/
    {
        if(mapa[i] != '.' && visitados[i] != 1)
        {
            tamanho_ilha = buscaProfunda(lista, i, visitados);

            if(tamanho_ilha > maior_ilha)
                maior_ilha = tamanho_ilha;

            if(tamanho_ilha < menor_ilha)
                menor_ilha = tamanho_ilha;

            qnt_ilha++;
        }
    }

    zerarVisitados(visitados, tam);

    int haCaminho = tesouroProfundidade(lista, localizacao, tesouro, visitados, DFS);     /*Função  caminho de localização até o tesouro com busca em profundidade, com retorno de 1 ou 0 se tem caminho*/

    zerarVisitados(visitados, tam);

    int x = tesouro;

    int passosProfundo = 0;

     if(haCaminho == 1){
        while(sair != 1){     /*Loop para as setas no mapa*/
            if(DFS[x] == localizacao)     /*Marca o ultimo laço*/
                sair = 1;

            if(DFS[x] == x + 1)
                mapa[DFS[x]] = '<';

            else if(DFS[x] == x - 1)
                mapa[DFS[x]] = '>';

            else if(DFS[x] > x)
                mapa[DFS[x]] = '^';

            else if(DFS[x] < x)
                mapa[DFS[x]] = 'v';

            x = DFS[x];
            passosProfundo++;
        }
    }

    tesouroLargura(lista, localizacao, tesouro, visitados, BFS);     /*Função para pegar o caminho de localização até o tesouro com busca em largura*/

    sair = 0;

    x = tesouro;

    int passosLargos = 0;

    if(haCaminho == 1){
        while(sair != 1){
            if(BFS[x] == localizacao)
                sair = 1;

            if(BFS[x] == x + 1)
                auxMapa[BFS[x]] = '<';

            else if(BFS[x] == x - 1)
                auxMapa[BFS[x]] = '>';

            else if(BFS[x] > x)
                auxMapa[BFS[x]] = '^';

            else if(BFS[x] < x)
                auxMapa[BFS[x]] = 'v';

            x = BFS[x];
            passosLargos++;
        }
    }

    printf("Ha %d ilhas(s)\n", qnt_ilha);
    printf("A maior tem tamanho %d\n", maior_ilha);
    printf("A menor tem tamanho %d", menor_ilha);

    if(haCaminho == 1){
        printf("\n\n");
        printf("Busca em profundidade:");
        for(int i = 0; tam > i; i++){
            if(i % M == 0) printf("\n");
            printf("%c", mapa[i]);
        }
        printf("\n%d passo(s)", passosProfundo);

        printf("\n\n");
        printf("Busca em largura:");
        for(int i = 0; tam > i; i++){
            if(i % M == 0) printf("\n");
            printf("%c", auxMapa[i]);
        }
        printf("\n%d passo(s)", passosLargos);
    }
    else
        printf("\nNao ha caminho para o tesouro");

    printf("\n");

    for(int i = 0; tam > i; i++){
        liberaLista(lista[i]);
    }
    
    free(lista);
    free(auxMapa);
    free(mapa);

    return 0;
}