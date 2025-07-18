#ifndef FILA_ESTATICA_H_INCLUDED
#define FILA_ESTATICA_H_INCLUDED

#define MAX 100

typedef struct{
    int v[MAX];
    int inicio, fim;
}Fila;

Fila *criaFila();
void pushFila(Fila *f, int v);
int popFila(Fila *f);
int filaVazia(Fila *f);

#endif // FILA_ESTATICA_H_INCLUDED