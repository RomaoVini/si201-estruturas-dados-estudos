#include <stdlib.h>
typedef struct No{
    int valor;
    struct No *esq, *dir;
} No;

typedef struct Tree{
    No *raiz;
} Tree;

// construtor da estrutura nó
No *newNo(int valor)
{
    No *no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

// construtor da estrutura árvore
Tree *newTree()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->raiz = NULL;
    return t;
}

int altura(No *no)
{
    if (no == NULL)
    {
        return -1;
    }
    else
    {
        int he = altura(no->esq);
        int hd = altura(no->dir);
        if (he > hd)
        {
            return he + 1;
        }
        else
        {
            return hd + 1;
        }
    }
}

int main(){    
    Tree *t = newTree();
    t->raiz = newNo(5);
    t->raiz->esq = newNo(6);
    t->raiz->dir = newNo(7);
    t->raiz->dir->esq = newNo(2);
    return 0;
}