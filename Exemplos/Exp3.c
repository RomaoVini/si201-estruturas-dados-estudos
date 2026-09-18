/* aloca.c - alocação dinâmica na prática (SI201, seção 1.4)
   compilar:  gcc -Wall -o aloca aloca.c
   rodar:     ./aloca                                        */

#include <stdio.h>
#include <stdlib.h>   /* malloc, free: obrigatório */

typedef struct No {
    int info;
    struct No *prox;
} No;

/* cria um nó solto, já preenchido e apontando para NULL */
No* cria_no(int v) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {                 /* memória acabou */
        printf("erro: malloc falhou\n");
        return NULL;                    /* devolve NULL e NÃO segue em frente */
    }

    novo->info = v;
    novo->prox = NULL;
    return novo;
}

int main(void) {
    No *a, *b, *p;

    printf("sizeof(No) = %lu bytes\n\n", (unsigned long) sizeof(No));

    /* 1) dois nós criados em tempo de execução */
    a = cria_no(10);
    b = cria_no(20);
    if (a == NULL || b == NULL) return 1;

    printf("no a: info=%d  endereco=%p  prox=%p\n", a->info, (void*) a, (void*) a->prox);
    printf("no b: info=%d  endereco=%p  prox=%p\n\n", b->info, (void*) b, (void*) b->prox);

    /* 2) ligando os dois: a -> b -> NULL */
    a->prox = b;
    printf("depois de a->prox = b:\n");
    printf("  a->prox      = %p (mesmo endereco de b)\n", (void*) a->prox);
    printf("  a->prox->info = %d\n\n", a->prox->info);

    /* 3) percorrendo a partir de a */
    printf("percurso: ");
    for (p = a; p != NULL; p = p->prox)
        printf("[%d] -> ", p->info);
    printf("NULL\n\n");

    /* 4) liberando: sempre guarde o prox ANTES do free */
    p = a;
    while (p != NULL) {
        No *t = p->prox;        /* guarda o caminho */
        printf("free do no com info=%d\n", p->info);
        free(p);
        p = t;
    }

    a = NULL;   /* boa prática: evita usar ponteiro para memória liberada */
    b = NULL;

    return 0;
}
