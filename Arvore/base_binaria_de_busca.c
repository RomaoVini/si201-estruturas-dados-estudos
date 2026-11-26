#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct No{
    int Valor;
    struct No *esq, *dir;
}No;

typedef struct Tree{
    struct No *raiz;
}Tree;

No *newNo(int valor){
    No *no = (No*)malloc(sizeof(No)); 
    no->Valor = valor;
    no->dir = NULL;
    no->esq = NULL;
    return no;
}

Tree *newTree(){
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->raiz= NULL;
    return tree;
}

int altura(No* no){
    if(no == NULL){
        return -1;
    }else{
        int he = altura(no->esq);
        int hd = altura(no->dir);
        if(he>hd){
            return he++;
        }else{
            return hd++;
        }
    }
}

void addTreeIt(Tree *t, int valor){
    if (t->raiz == NULL)
    {
        t->raiz = newNo(valor);
        return;
    }
    No *aux = t->raiz;
    int inseriu = FALSE;
    while (!inseriu)
    {
        if (valor < aux->Valor)
        {
            if (aux->esq != NULL)
            {
                aux = aux->esq;
            }
            else
            {
                aux->esq = newNo(valor);
                inseriu = TRUE;
            }
        }
        else
        {
            if (aux->dir != NULL)
            {
                aux = aux->dir;
            }
            else
            {
                aux->dir = newNo(valor);
                inseriu = TRUE;
            }
        }
    }
}

void addNo(No *no, int valor){
    if(valor<=no->Valor){
        if(no->esq!=NULL){
            addNo(no->esq,valor);
        }else{
            no->esq=newNo(valor);
        }
    }else{
      if(no->dir!=NULL){
            addNo(no->dir,valor);
        }else{
            no->dir=newNo(valor);
        }  
    }
}

void addTree(Tree *t, int valor){
    if(t->raiz == NULL){
        t->raiz=newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

No *buscaRec(No *no, int valor){
    if(no==NULL){
        return NULL;
    }

    if(valor==no->Valor){
        return no;
    }else if (valor <= no->Valor){
        return buscaRec(no->esq,valor);
    }else{
        return buscaRec(no->dir,valor);
    }
    
}


No *buscaIterativa(No *no, int valor){
    No *aux= no;
    while(aux!=NULL){
        if(aux->Valor==valor){
            return aux;
        }else if(valor<=aux->Valor){
            aux=aux->esq;
        }else{
            aux=aux->dir;
        }
    }

    return NULL;
}


int main(){
    Tree *t = newTree();
    addTree(t, 3);
    addTree(t, 6);
    addTree(t, 7);
    addTree(t, 5);
 
    No *achou = buscaIterativa(t->raiz, 10);
    if (achou != NULL)
        printf("Achei o %d\n", achou->Valor);
    else
        printf("Nao existe\n");
 
    return 0;
}