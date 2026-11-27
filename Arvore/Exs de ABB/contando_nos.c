#include <stdlib.h>
#include <stdio.h>
#define False 0;
#define True 1;

typedef struct No{
    int Valor;
    struct No *esq,*dir;
}No;


typedef struct Tree{
    No *raiz;
}Tree;

No *newNo(int valor){
    No *no = (No*)malloc(sizeof(No));
    no->Valor=valor;
    no->dir=NULL;
    no->esq=NULL;
    return no;
}

Tree *newTree(){
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->raiz=NULL;
    return tree;
}

int altura(No *no){
    if(no==NULL){
        return -1;
    }

    int he = altura(no->esq);
    int hd= altura(no->dir);

    if(he>hd){
        return he+1;
    }else{
        return hd+1;
    }
}

void addTreeIt(Tree *t,int valor){
    No *aux;
    aux=t->raiz;
    int controle = False;
    if(t->raiz==NULL){
        t->raiz=newNo(valor);
        return;
    }

    while(!controle){
        if(valor<aux->Valor){
            if(aux->esq!=NULL){
                aux=aux->esq;
            }else{
                aux->esq=newNo(valor);
                controle=True;
            }
        }else{
            if(aux->dir!=NULL){
                aux=aux->dir;
            }else{
                aux->dir=newNo(valor);
                controle=True;
            }
        }
    }
}

void addNo(No *no, int Valor){
    if(Valor<=no->Valor){
        if(no->esq!=NULL){
            addNo(no->esq,Valor);
        }else{
            no->esq=newNo(Valor);
        }
    }else{
        if(no->dir!=NULL){
            addNo(no->dir,Valor);
        }else{
            no->dir=newNo(Valor);
        }
    }
}

void addTree(Tree *t, int valor){
    if(t->raiz==NULL){
        t->raiz=newNo(valor);
        return;
    }else{
        addNo(t->raiz,valor);
    }
}

No *buscarec(No *no, int valor){
    if(no==NULL){
        return NULL;
    }

    if(valor==no->Valor){
        return no;
    }else if(valor<=no->Valor){
        return buscarec(no->esq,valor);
    }else{
        return buscarec(no->dir,valor);
    }
    
}

No *bucait(Tree *t, int valor){
    if(t->raiz==NULL){
        return NULL;
    }
    No *aux;
    aux = t->raiz;

    while (aux != NULL){
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

int contaNos(No *no){
    if(no==NULL){
        return 0;
    }

    int esquerda = contaNos(no->esq);
    int direita = contaNos(no->dir);
    return esquerda + direita + 1;
}

int main(){
    Tree *arvore = newTree();
    int valores[] = {8, 4, 12, 2, 6, 10, 14};
    int quantidade = sizeof(valores) / sizeof(valores[0]);

    for(int i = 0; i < quantidade; i++){
        addTree(arvore, valores[i]);
    }

    printf("Quantidade de nos: %d\n", contaNos(arvore->raiz));

    free(arvore);
    return 0;
}