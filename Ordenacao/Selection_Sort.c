#include <stdio.h>
#include <stdlib.h>

// encontra a posição do maior elemento do vetor.
// se houver vários, devolve a posição do primeiro maior.
int maximo(int v[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[max])
        {
            max = i;
        }
    }
    return max;
}

void ordena(int v[], int n)
{
    while (n > 1)
    {
        // seleciona o maior elemento
        int max = maximo(v, n);
 
        // coloca na última posição
        int aux = v[n-1];
        v[n-1] = v[max];
        v[max] = aux;
 
        // repete o processo desconsiderando o último
        n--;
    }
}

void ordenacao_selecao(int v[], int n)
{
    for (int N = n; N > 1; N--)
    {
        int max = 0;
        for (int i = 1; i < N; i++)
            if (v[i] > v[max]) max = i;
        int aux = v[N-1];
        v[N-1] = v[max];
        v[max] = aux;
    }
}

void selecao_recursivo(int v[], int n)
{
    if (n > 1)
    {
        int max = 0;
        for (int i = 1; i < n; i++){
            if (v[i] > v[max]) {
                max = i;
            }
        }
        int aux = v[n-1];
        v[n-1] = v[max];
        v[max] = aux;
 
        selecao_recursivo(v, n - 1); // mesmo problema, com 1 elemento a menos
    }
}



int main(){
    int v[]={14,2,31,42,5,64,3,88,6,3,1};
    ordenacao_selecao(v,11);
    for(int x=0;x<11;x++){
        printf("\n%i",v[x]);
    }
    return 0;
}