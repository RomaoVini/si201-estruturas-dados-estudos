#include <stdio.h>
int main(){
    
    typedef struct No {
    int info;
    struct No *prox;      /* aponta para o nó de baixo */
    } No;

    typedef struct {
        No *topo;             /* NULL quando a pilha está vazia */
    } Pilha;

    return 0;
}