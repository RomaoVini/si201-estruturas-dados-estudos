#include <stdlib.h>
#include <stdio.h>

// ordena o vetor, desde que esteja ordenado, a não ser o último elemento
void insercaoA(int v[], int n)
{
    int lixo = -1;
    int chave = v[n-1];
    v[n-1] = lixo;
    int i = n - 2;
    while (i >= 0 && v[i] > chave)
    {
        v[i+1] = v[i];
        v[i] = lixo;
        i--;
    }
    v[i+1] = chave;
}

void insercaoIte(int v[], int n)
{
    int N = 2;
    while (N <= n)
    {
        int chave = v[N-1];
        int i = N - 2;
        while (i >= 0 && v[i] > chave)
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
        N++;
    }
}

void insercaoRec(int v[], int n)
{
    if (n > 1)
    {
        insercaoRec(v, n - 1); // 1º: ordena os n-1 primeiros
        int chave = v[n-1];    // 2º: insere o último entre eles
        int i = n - 2;
        while (i >= 0 && v[i] > chave)
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
    }
}

int main(){
    int v[]={5,33,114,2,31,42,5,64,3,88,6,3,1};
    insercaoRec(v,11);
    for(int x=0;x<11;x++){
        printf("\n%i",v[x]);
    }
    return 0;
}
