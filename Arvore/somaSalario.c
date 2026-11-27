#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int valor;
    struct No * esq;
    struct No * dir;
 }No;

 typedef struct Tree {
    No * raiz;
 }Tree;

No *newNo(int valor){
    No *no = malloc(sizeof(No));
    if(no == NULL){
        return NULL;
    }

    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

Tree *newTree(void){
    Tree *arvore = malloc(sizeof(Tree));
    if(arvore == NULL){
        return NULL;
    }

    arvore->raiz = NULL;
    return arvore;
}

int addNo(No *no, int valor){
    if(valor <= no->valor){
        if(no->esq == NULL){
            no->esq = newNo(valor);
            return no->esq != NULL;
        }else{
            return addNo(no->esq, valor);
        }
    }else{
        if(no->dir == NULL){
            no->dir = newNo(valor);
            return no->dir != NULL;
        }else{
            return addNo(no->dir, valor);
        }
    }
}

int addTree(Tree *arvore, int valor){
    if(arvore->raiz == NULL){
        arvore->raiz = newNo(valor);
        return arvore->raiz != NULL;
    }else{
        return addNo(arvore->raiz, valor);
    }
}

void freeNo(No *no){
    if(no != NULL){
        freeNo(no->esq);
        freeNo(no->dir);
        free(no);
    }
}

 int somasalario(No *no){
    if(no==NULL){
        return 0;
    }

    int esquerda = somasalario(no->esq);
    int direita = somasalario(no->dir);
    if(no->valor>=5000){
        return esquerda + direita+no->valor;
    }
    return esquerda + direita;
 }

int main(void){
    int salarios[] = {7000, 4000, 8000, 3000, 5500, 4500, 10000};
    int quantidade = sizeof(salarios) / sizeof(salarios[0]);
    Tree *arvore = newTree();
    if(arvore == NULL){
        fprintf(stderr, "Erro ao criar a arvore.\n");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < quantidade; i++){
        if(!addTree(arvore, salarios[i])){
            fprintf(stderr, "Erro ao adicionar um salario na arvore.\n");
            freeNo(arvore->raiz);
            free(arvore);
            return EXIT_FAILURE;
        }
    }

    printf("Soma dos salarios de pelo menos 5000: %d\n",
           somasalario(arvore->raiz));

    freeNo(arvore->raiz);
    free(arvore);
    return 0;
}