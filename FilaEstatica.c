#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

Fila *criaFila(){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
}

void pushFila(Fila *f, int v){
    f->v[f->fim] = v;
    f->fim = (f->fim+1)%MAX;
}

int popFila(Fila *f){
    int v = f->v[f->inicio];
    f->inicio = (f->inicio+1)%MAX;
    return v;
}

int filaVazia(Fila *f){
    if(f->inicio == f->fim)
        return 1;
    return 0;
}
