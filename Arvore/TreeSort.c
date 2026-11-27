#include <stdlib.h>
#include <stdio.h>
// Lista salva em vetor
typedef struct Lista
{
    int *v;
    int top, max;
} Lista;

typedef struct No{
    int valor;
    struct No*esq,*dir;
}No;

typedef struct Tree{
    No *raiz;
}Tree;

Lista *newLista(int max){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->v= (int*)malloc(max*sizeof(int));
    l->max=max;
    l->top=0;
    return l;
}


No *newNo(int valor){
    No *no = (No*)malloc(sizeof(No));
    no->valor=valor;
    no->dir=NULL;
    no->esq=NULL;
    return no;
}

Tree *newTree(){
    Tree *t = (Tree*)malloc(sizeof(Tree));
    t->raiz=NULL;
    return t;
}

void addLista(Lista *l,int valor){
    if(l->top==l->max){
        return;
    }
    l->v[l->top++]=valor;
}

void addNo(No *no, int valor){
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
void addTree(Tree *t, int valor){
    if(t->raiz==NULL){
        t->raiz=newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

void percurso(No *no, Lista *l)
{
    if (no == NULL){
        return;
    }
    percurso(no->esq, l);
    addLista(l, no->valor);
    percurso(no->dir, l);
}

void TreeSort(Lista *l)
{
    if (l->top <= 1){
        return;
    }
    // insere os elementos da lista
    // em uma árvore binária de busca
    Tree *t = newTree();
    for (int i = 0; i < l->top; i++)
    {
        addTree(t, l->v[i]);
    }
    // deixar o vetor vazio.
    l->top = 0;
    percurso(t->raiz, l);
}


int main(void)
{
    int valores[] = {7, 3, 5, 1, 9, 2, 8};
    int quantidade = sizeof(valores) / sizeof(valores[0]);
    Lista *lista = newLista(quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        addLista(lista, valores[i]);
    }

    printf("Antes:  ");
    for (int i = 0; i < lista->top; i++)
    {
        printf("%d ", lista->v[i]);
    }

    TreeSort(lista);

    printf("\nDepois: ");
    for (int i = 0; i < lista->top; i++)
    {
        printf("%d ", lista->v[i]);
    }
    printf("\n");

    free(lista->v);
    free(lista);
    return 0;
}

