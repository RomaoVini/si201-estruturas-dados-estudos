#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *prox;
}No;

typedef struct Fila{
    No *ini;
    No *fim;
}Fila;

void inicializa(Fila *f){
    f->ini=NULL;
    f->fim=NULL;
}

int vazia(Fila *f){
    return f->ini==NULL;
}

int add(Fila *f,int num){
    No *novo = (No*)malloc(sizeof(No));
    novo->info=num;
    novo->prox=NULL;
    if(vazia(f)){
        f->ini=novo;
    }else{
        f->fim->prox=novo;
    }
    f->fim=novo;
    return 1;
}

int remover(Fila *f,int *saida){
    if(vazia(f)){
        return 0;
    }
    No *aux;
    aux=f->ini;
    *saida=aux->info;
    f->ini=aux->prox;
    if(vazia(f)){
        f->fim=NULL;
    }
    free(aux);
    return 1;
}

int top(Fila *f, int* num){
    if(vazia(f)){
        printf("Fila vazia");
        return 0;
    }
    *num= f->ini->info;
    return 1;
}

int main(void) {
    Fila f;
    int x;
    inicializa(&f);

    add(&f, 101);
    add(&f, 102);
    add(&f, 103);

    remover(&f, &x);  printf("atendido: %d\n", x);
    remover(&f, &x);  printf("atendido: %d\n", x);
    top(&f, &x);   printf("na frente: %d\n", x);
    return 0;
}


