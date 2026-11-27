#include <stdio.h>
#include<stdlib.h>
typedef struct No{
    int Valor;
    struct No *esq,*dir;
}No;

typedef struct Tree{
    No *raiz;
}Tree;

void liberamemoria(No *no){
    if(no==NULL){
        return;
    }

    liberamemoria(no->esq);
    liberamemoria(no->dir);
    free(no);
}

void libreTree(Tree *t){
    if(t->raiz==NULL){
        return;
    }
    liberamemoria(t->raiz);
    t->raiz=NULL;
}

