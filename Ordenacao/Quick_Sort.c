#include <stdio.h>
#include <stdlib.h>
//revisar antes da p2.2
int particaoAleatoria(int v[], int p, int r)
{
    int k = p + rand() % (r - p + 1); // sorteia uma posição entre p e r
    int aux = v[p];                   // troca o sorteado com v[p]
    v[p] = v[k];
    v[k] = aux;
 
    return particao(v, p, r);         // a partição de antes continua igual
}

int particao(int v[], int p, int r)
{
    int pivo = v[p];
    int topo = p;
    for (int i = p + 1; i <= r; i++)
    {
        if (v[i] < pivo)
        {
            v[topo] = v[i];
            v[i] = v[topo + 1];
            topo++;
        }
    }
    v[topo] = pivo;
    return topo;
}

void quickSort(int v[], int p, int r)
{
    if (p < r)
    {
        int q = particao(v, p, r);
        quickSort(v, p, q - 1);
        quickSort(v, q + 1, r);
    }
}

int main(void)
{
    int valores[] = {10, 7, 8, 9, 1, 5};
    int quantidade = sizeof(valores) / sizeof(valores[0]);

    printf("Antes:  ");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%d ", valores[i]);
    }

    quickSort(valores, 0, quantidade - 1);

    printf("\nDepois: ");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}