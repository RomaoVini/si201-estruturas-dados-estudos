#include <stdio.h>
#include <stdlib.h>
    int balanceado(const char *s);

    typedef struct No{
        int info;
        struct No *prox;
    }No;

    typedef struct Pilha{
        No *topo;
    }Pilha;

    int inicializa(Pilha *p){
        p->topo=NULL;
        return 1;
    }

    int vazia(Pilha *p){
        if(p->topo==NULL){
            return 1;
        }
        return 0;
    }

    int push(Pilha *p,int num){
        No *novo = (No*)malloc(sizeof(No));
        if(novo==NULL){
            return 0;
        }

        novo->info=num;
        novo->prox=p->topo;
        p->topo=novo;
        return 1;
    }

    int pop(Pilha *p,int *saida){
        if(vazia(p)){
            return 0;
        }

        No *aux;
        aux = p->topo;
        *saida = aux->info;
        p->topo=aux->prox;
        free(aux);
        return 1;
    }


int main(){
    char test[100]={"(((())))"};
    char *pont;
    pont = test;
    int r = balanceado(pont);         
    printf("balanceado(\"%s\") = %d\n", test, r);  

    return 0;
}

int balanceado(const char *s) {
    Pilha p;
    int i, x;
    inicializa(&p);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(')
            push(&p, s[i]);
        else if (s[i] == ')') {
            if (!pop(&p, &x)) return 0;   /* fechou sem ter aberto */
        }
    }
    return vazia(&p);   /* sobrou aberto? então não está balanceado */
}