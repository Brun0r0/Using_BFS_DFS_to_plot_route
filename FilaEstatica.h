#ifndef FILA_ESTATICA_H_INCLUDED
#define FILA_ESTATICA_H_INCLUDED

#define MAX 100

typedef struct{
    int v[MAX];
    int inicio, fim;
}Fila;

Fila *criaFila();
int vazia_fila(Fila *f);
void push_fila(Fila *f, int v);
int pop_fila(Fila *f);
void limpa_fila(Fila *f);
void clear(Fila *f);
#endif // FILA_ESTATICA_H_INCLUDED