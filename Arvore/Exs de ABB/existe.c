#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct No{
    int valor;
    struct No *esq,*dir;
}No;

typedef struct Tree{
    No *raiz;
}Tree;

No *newNo(int valor){
    No *no=(No*)malloc(sizeof(No));
    no->valor=valor;
    no->dir=NULL;
    no->esq=NULL;
    return no;
}

Tree *newTree(){
    Tree *t= (Tree*)malloc(sizeof(Tree));
    t->raiz=NULL;
    return t;
}

int altura(No* no){
    if(no==NULL){
        return -1;
    }

    int he = altura(no->esq);
    int hd = altura(no->dir);
    if(he>hd){
        return he+1;
    }else{
        return hd+1;
    }
}

void addTreeit(Tree *t,int valor){
    if(t->raiz==NULL){
        t->raiz=newNo(valor);
        return;
    }

    No *aux = t->raiz;
    int controle =False;
    while(!controle){
        if(valor<=aux->valor){
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

void addNo(No *no,int valor){
    if(valor<=no->valor){
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
void addTree(Tree *t,int valor){
    if(t->raiz==NULL){
        t->raiz=newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

No * buscaRec(No *no, int valor){
    if(no==NULL){
        return NULL;
    }

    if(valor==no->valor){
        return no;
    }else if(valor<=no->valor){
        return buscaRec(no->esq,valor);
    }else{
        return buscaRec(no->dir,valor);
    }

}

No *buscaIterativa(No *no,int valor){
    if(no==NULL){
        return NULL;
    }
    No *aux=no;
    while (aux!=NULL){
        if(valor==aux->valor){
            return aux;
        }else if(valor<=aux->valor){
            aux=aux->esq;
        }else{
            aux=aux->dir;
        }
    }

    return NULL; 

}

int existe(No *no, int valor){
    if(no==NULL){
        return 0;
    }

    int esquerda= existe(no->esq,valor);
    int direita= existe(no->dir,valor);
    if(no->valor==valor){
        return 1;
    }

    return esquerda+direita;
}
int main(){
    int test=3;
    Tree *t = newTree();
    addTree(t, 31);
    addTree(t, 64);
    addTree(t, 72);
    addTree(t, 51);
    addTree(t, 10);
    addTree(t, 63);
    addTree(t, 45);
    addTree(t, 52);
    addTree(t, 3);
    addTree(t, 1);
    int num =existe(t->raiz,test);
    if(num>0){
        printf("EXISTE NA ARVORE O NUMERO : %i",test);
    }else{
        printf("NAO EXISTE");
    }
    return 0;
}