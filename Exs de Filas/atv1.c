#include <stdio.h>
#include <stdlib.h>
typedef struct Fila{
    int *v;
    int ini;
    int fim;
    int max;
}Fila;

int inicializa(Fila *f,int max){
    f->v = (int*)malloc(sizeof(int)*max);
    f->ini=0;
    f->fim=0;
    f->max=max;
    return 1;
}

int estaVazia(Fila *f){
    return f->ini==f->fim;
}

int estacheia(Fila *f){
    return (f->fim+1)%f->max==f->ini;
}

int add(Fila *f,int v){
    if(estacheia(f)){
        return 0;
    }
    f->v[f->fim]=v;
    f->fim=(f->fim+1)%f->max;
    return 1;
}

int remover(Fila *f,int *saida){
    if(estaVazia(f)){
        return 0;
    }
    *saida=f->v[f->ini];
    f->ini=(f->ini+1)%f->max;
    return 1;
}

void imprime(Fila *f) {
    int i;

    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    i = f->ini;

    while (i != f->fim) {
        printf("%d ", f->v[i]);

        i = (i + 1) % f->max;
    }

    printf("\n");
}


int main(){
    Fila f;
    int saida;
    inicializa(&f,10);
    add(&f,10);
    add(&f,50);
    add(&f,120);
    add(&f,104);
    imprime(&f);
    remover(&f,&saida);
    printf("foi removido o numero : %i da lista\n",saida);
    add(&f,101);
    add(&f,1);
    imprime(&f);
    return 0;
}