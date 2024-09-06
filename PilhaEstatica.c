#include<stdio.h>
#include<stdlib.h>
#include"PilhaEstatica.h"


Pilha *cria_pilha() {
Pilha *p = (Pilha *)malloc(sizeof(Pilha));
p->topo = -1;
return p;
}

int vazia_pilha(Pilha *p) {
if(p->topo == -1) return 1;
else return 0;
}

void push_pilha(Pilha *p, int x) {
p->topo++;
p->v[p->topo] = x;
}

int pop_pilha(Pilha *p) {
int aux = p->v[p->topo];
p->topo--;
return aux;
}

int cheia_pilha(Pilha *p)
{
    if(p->topo > 998){return 1;}  /*a pilha vai estar cheia (999 elementos) na posicao 998, pois o zero eh contado como uma posicao*/
    else{return 0;}
}

void imprime_pilha(Pilha *p)
{
    for(int x = p->topo; x > -1 ; x--)
    {
        printf("%d ", p->v[x]);
    }
}

void limpa_pilha(Pilha *p)
{
    free(p);
}
