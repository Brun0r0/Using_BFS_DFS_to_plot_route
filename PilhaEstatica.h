
#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

typedef struct {
int v[999];
int topo;
} Pilha;

Pilha *cria_pilha();
int vazia_pilha(Pilha *p);
void push_pilha(Pilha *p, int x);
int pop_pilha(Pilha *p);
int cheia_pilha(Pilha *p);
void imprime_pilha(Pilha *p);
void limpa_pilha(Pilha *p);

#endif
