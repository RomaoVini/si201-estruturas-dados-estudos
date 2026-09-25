#include <stdio.h>
#include <stdlib.h>
typedef struct Pilha{
    int *v;
    int Max,topo;
}Pilha;

Pilha *newPilha(int max){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    novo->v = (int*)malloc(sizeof(int)*max);
    novo->Max=max;
    novo->topo=-1;
    return novo;
}

int vazia(Pilha *p){
    if(p->topo==-1){
        return 1;
    }

    return 0;
}

int cheia(Pilha *p){
    if(p->topo==p->Max-1){
        return 1;
    }
    return 0;
}


void Push(Pilha *p, int valor){
    if(cheia(p)){
        return ;
    }

    p->topo++;
    p->v[p->topo]=valor;
}

int pop(Pilha *p){
    if(vazia(p)){
        return 0;
    }
    int saida=p->v[p->topo];
    p->topo--;
    return saida;
}

void printPilha(Pilha *p){
    printf("\n[");
    for(int x=p->topo;x>=0;x--){
        printf("%i ",p->v[x]);
        int y=x;
        if(--y!=-1){
            printf("->");
        }
    }
    printf("]");
}

int main(){
    Pilha *p1 = newPilha(100);
    Pilha *p2 = newPilha(100);
    Pilha *p3 = newPilha(100);

    int tarefa;
    scanf("%i",&tarefa);

    do{
        if(tarefa<=0){
            break;
        }
        if(tarefa%3==0){
            Push(p1,tarefa);
        }else if (tarefa%3==1){
            Push(p2,tarefa);
            
        }else if(tarefa%3==2){
            Push(p3,tarefa);
        }
    scanf("%i",&tarefa);
    }while (tarefa>0);
    
    printPilha(p1);
    printPilha(p2);
    printPilha(p3);
    
    return 0;
}


