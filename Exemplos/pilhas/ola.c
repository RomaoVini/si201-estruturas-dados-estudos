#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int info;
    struct No *prox;      
}No;

typedef struct  Pilha{
    No *Topo;
}Pilha;

int inicializa(Pilha *p){
    p->Topo =NULL;
    return 1;
}  

int vazia (Pilha *p){
    if (p->Topo==NULL){
        return 1;
    }
    return 0;
    
}

int push(Pilha *p, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo==NULL){
        return 0;
    }
    novo->info=valor;
    novo->prox=p->Topo;
    p->Topo=novo;

    return 1;

}

int pop(Pilha *p, int *saida){
    if(vazia(p)){
        return 0;
    }
    No *aux;
    aux = p->Topo;
    *saida = aux->info;
    p->Topo = aux->prox;
    free(aux);
    return 1;
}

void libera(Pilha *p) {
    int x;
    while (!vazia(p)) pop(p, &x);
}

int main(void) {
    Pilha p;
    int i, v, x;
    inicializa(&p);

    for (i = 0; i < 3; i++) {
        scanf("%d", &v);
        push(&p, v);
    }
    while (pop(&p, &x))
        printf("%d ", x);
    return 0;
}