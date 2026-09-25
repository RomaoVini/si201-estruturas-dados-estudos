#define MAX 100
typedef struct {
    int dados[MAX];   /* os elementos, do fundo (0) para o topo */
    int topo;         /* índice do elemento do topo; -1 = vazia  */
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int push(Pilha *p, int v) {
    if (cheia(p)) return 0;      /* 0 = não deu certo (overflow) */
    p->topo++;                     /* 1) abre espaço: sobe o topo  */
    p->dados[p->topo] = v;         /* 2) escreve na nova posição   */
    return 1;
}

int pop(Pilha *p, int *saida) {
    if (vazia(p)) return 0;      /* underflow */
    *saida = p->dados[p->topo];    /* 1) copia o valor para quem chamou */
    p->topo--;                     /* 2) desce o topo                   */
    return 1;
}

int top(Pilha *p, int *saida) {
    if (vazia(p)) return 0;
    *saida = p->dados[p->topo];    /* só lê; topo não muda */
    return 1;
}