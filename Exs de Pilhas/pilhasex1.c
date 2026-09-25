#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Pilha{
    int Dados[MAX];
    int topo;
}Pilha;

int inicializa (Pilha *p){
    p->topo=-1;
    return 1;
}

void imprimi1(Pilha *p);
void imprimi2(Pilha *p);

int Vazia(Pilha *p){
    if(p->topo==-1){
        return 1;
    }

    return 0;
}

int cheia(Pilha *p){
    if(p->topo==MAX-1){
        return 1;
    }
    return 0;
}

int push(Pilha *p,int num){
    if(cheia(p)){
        return 0;
    }
    p->topo++;
    p->Dados[p->topo]=num;
    return 1;
}

int pop(Pilha *p,int *saida){
    if(Vazia(p)){
        return 0;
    }
    *saida = p->Dados[p->topo];
    p->topo--;
    return 1;
}

int top(Pilha *p,int *saida){
    if(Vazia(p)){
        return 0;
    }
    *saida = p->Dados[p->topo];
    return 1;
}

int main(){
    Pilha p;
    inicializa(&p);
    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);
    push(&p,13);
    push(&p,22);
    push(&p,67);
    push(&p,10);
    imprimi1(&p);
    printf("\n\n\n");
    imprimi2(&p);
    return 1;
}

void imprimi1(Pilha *p){
    if(Vazia(p)){
        return ;
    }

    printf("PILHA DO TOPO ATE O FIM (SEM MODIFICAR)");
    printf("[%i",p->Dados[p->topo]);
    for(int i=p->topo-1; i>=0; i--){
        printf(",%i",p->Dados[i]);
    }
    printf("]");
}

void imprimi2(Pilha *p){
    int num;
    Pilha copia;
    inicializa(&copia);
     if(Vazia(p)){
        return ;
    }
    printf("PILHA DO TOPO ATE O FIM (Modificando ela)\n");
    while(pop(p,&num)){
        printf("%i ",num);
        push(&copia,num);
    }

    while(pop(&copia,&num)){
        push(p,num);
    }
}