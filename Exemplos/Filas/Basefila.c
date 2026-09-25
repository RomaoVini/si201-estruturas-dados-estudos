#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    int ini;
    int fim;
    int max;
} Fila;


/* Inicializa a fila */
void inicializa(Fila *f, int max) {
    f->v = malloc(sizeof(int) * max);

    if (f->v == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    f->ini = 0;
    f->fim = 0;
    f->max = max;
}


/* Verifica se a fila está vazia */
int estaVazia(Fila *f) {
    return f->ini == f->fim;
}


/* Verifica se a fila está cheia */
int estaCheia(Fila *f) {
    return (f->fim + 1) % f->max == f->ini;
}


/* Adiciona um elemento na fila */
void add(Fila *f, int x) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }

    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->max;
}


/* Remove um elemento da fila */
int removeFila(Fila *f, int *x) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return 0;
    }

    *x = f->v[f->ini];

    f->ini = (f->ini + 1) % f->max;

    return 1;
}


/* Mostra os elementos da fila */
void imprime(Fila *f) {
    int i;

    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    i = f->ini;

    while (i != f->fim) {
        printf("%d ", f->v[i]);

        i = (i + 1) % f->max;
    }

    printf("\n");
}


/* Libera a memória */
void libera(Fila *f) {
    free(f->v);

    f->v = NULL;
    f->ini = 0;
    f->fim = 0;
    f->max = 0;
}


int main() {
    Fila f;
    int x;

    inicializa(&f, 6);

    add(&f, 10);
    add(&f, 20);
    add(&f, 30);
    add(&f, 40);

    printf("Fila: ");
    imprime(&f);

    removeFila(&f, &x);
    printf("Removido: %d\n", x);

    removeFila(&f, &x);
    printf("Removido: %d\n", x);

    printf("Fila depois das remocoes: ");
    imprime(&f);

    add(&f, 50);
    add(&f, 60);

    printf("Fila final: ");
    imprime(&f);

    libera(&f);

    return 0;
}