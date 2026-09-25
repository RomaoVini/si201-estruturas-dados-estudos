#include <stdio.h>
#include <stdlib.h>

    typedef struct No{
        int info;
        struct No *prox;
    }No;

    typedef struct Pilha{
        No *topo;
    }Pilha;

void binario(int n);

int inicializa(Pilha *P){
    P->topo = NULL;
    return 1;
}

int vazia(Pilha *p){
    if(p->topo==NULL){
        return 1;
    }
    return 0;
}

int push(Pilha *p, int num){
    No *novo= (No*)malloc(sizeof(No));
    if(novo==NULL){
        return 0;
    }
    novo->info=num;
    novo->prox=p->topo;
    p->topo = novo;
    return 1;
}

int pop(Pilha *p, int *saida){
    if (vazia(p)){
        return 0;
    }

    No *aux;
    aux = p->topo;
    *saida = aux->info;
    p->topo=aux->prox;
    free(aux);
    return 1;
}

int main(){
    binario(13);
    return 0;
}


void binario(int n) {
    Pilha p;
    int x;
    inicializa(&p);

    if (n == 0) { printf("0"); return; }
    while (n > 0) {
        push(&p, n % 2);   /* guarda o resto */
        n = n / 2;
    }
    while (pop(&p, &x))
        printf("%d", x);
}