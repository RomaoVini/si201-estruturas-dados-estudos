#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int valor;
    struct No *esq, *dir;
} No;

typedef struct Tree{
    No *raiz;
} Tree;
No *newNo(int valor){
    No *no = (No*)malloc(sizeof(No)); 
    no->valor = valor;
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
            return he+1;
        }else{
            return hd+1;
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
    int inseriu = 0;
    while (!inseriu)
    {
        if (valor < aux->valor)
        {
            if (aux->esq != NULL)
            {
                aux = aux->esq;
            }
            else
            {
                aux->esq = newNo(valor);
                inseriu = 1;
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
                inseriu = 1;
            }
        }
    }
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

    if(valor==no->valor){
        return no;
    }else if (valor <= no->valor){
        return buscaRec(no->esq,valor);
    }else{
        return buscaRec(no->dir,valor);
    }
    
}
// imprime a árvore em XML
void printNoXML(No *no, FILE *fp)
{
    fprintf(fp, "%d\n", no->valor);
    if (no->esq != NULL)
    {
        fprintf(fp, "<esq>\n");
        printNoXML(no->esq, fp);
        fprintf(fp, "</esq>\n");
    }
    if (no->dir != NULL)
    {
        fprintf(fp, "<dir>\n");
        printNoXML(no->dir, fp);
        fprintf(fp, "</dir>\n");
    }
}

// imprime a árvore em XML
void printTreeXML(Tree *t)
{
    FILE *fp = fopen("Tree.xml", "w");
    if (fp == NULL)
    {
        perror("Nao foi possivel criar Tree.xml");
        return;
    }

    fprintf(fp, "<tree>\n");
    if (t->raiz != NULL)
        printNoXML(t->raiz, fp);
    fprintf(fp, "</tree>\n");
    if (fclose(fp) != 0)
        perror("Erro ao gravar Tree.xml");
}
int main()
{
    Tree *t = newTree();
    addTree(t, 6);
    addTree(t, 8);
    addTree(t, 2);
    addTree(t, 10);
    addTree(t, 7);
    addTree(t, 1);
    addTree(t, 3);

    printTreeXML(t);
    printf("Arvore exportada para Tree.xml.\n");

    return 0;
}