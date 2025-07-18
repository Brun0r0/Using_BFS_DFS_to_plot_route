#include<stdio.h>
#include<stdlib.h>
#include"PilhaEstatica.h"

Pilha *criarPilha() {
Pilha *p = (Pilha *)malloc(sizeof(Pilha));
p->topo = -1;
return p;
}

void pushPilha(Pilha *p, int x) {
p->topo++;
p->v[p->topo] = x;
}

int popPilha(Pilha *p) {
int aux = p->v[p->topo];
p->topo--;
return aux;
}

int pilhaVazia(Pilha *p) {
if(p->topo == -1) return 1;
else return 0;
}