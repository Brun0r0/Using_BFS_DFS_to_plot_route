
#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

typedef struct {
int v[999];
int topo;
} Pilha;

Pilha *criarPilha();
void pushPilha(Pilha *p, int x);
int popPilha(Pilha *p);
int pilhaVazia(Pilha *p);

#endif