#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

Fila *criaFila(){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
}

int vazia_fila(Fila *f){
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

void push_fila(Fila *f, int v){
    f->v[f->fim] = v;
    f->fim = (f->fim+1)%MAX;
}

int pop_fila(Fila *f){
    int v = f->v[f->inicio];
    f->inicio = (f->inicio+1)%MAX;
    return v;
}

void clear(Fila *f){
    int v=0;
    while(!vazia_fila(f)){
        int v = pop_fila(f);
    }
    return;
}

void limpa_fila(Fila *f){
    int v=0;
    while(!vazia_fila(f)){
        int v = pop_fila(f);
    }
    free(f);
    return;
}