#include <stdio.h>
#include <stdlib.h>

void merge(int *v1, int n1, int *v2, int n2, int *v)
{
    int top1 = 0, top2 = 0, top = 0;
    while (top1 < n1 && top2 < n2)
    {
        if (v1[top1] < v2[top2])
        {
            v[top++] = v1[top1++];
        }
        else
        {
            v[top++] = v2[top2++];
        }
    }
    // copia o que sobrou do v1 (se sobrou)
    while (top1 < n1)
    {
        v[top++] = v1[top1++];
    }
    // copia o que sobrou do v2 (se sobrou)
    while (top2 < n2)
    {
        v[top++] = v2[top2++];
    }
}

void mergeSort(int v[], int n)
{
    if (n > 1)
    {
        int n1 = n / 2;
        int n2 = n - n1;
        int *v1 = (int*)malloc(sizeof(int) * n1);
        int *v2 = (int*)malloc(sizeof(int) * n2);
        for (int i = 0; i < n1; i++)
        {
            v1[i] = v[i];
        }
        for (int i = 0; i < n2; i++)
        {
            v2[i] = v[n1 + i];
        }
        mergeSort(v1, n1);
        mergeSort(v2, n2);
        merge(v1, n1, v2, n2, v);
        free(v1);
        free(v2);
    }
}

int main(void)
{
    int valores[] = {38, 27, 43, 3, 9, 82, 10};
    int quantidade = sizeof(valores) / sizeof(valores[0]);

    printf("Antes:  ");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%d ", valores[i]);
    }

    mergeSort(valores, quantidade);

    printf("\nDepois: ");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}