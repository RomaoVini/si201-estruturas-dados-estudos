#include <stdio.h>
#include <stdlib.h>
void bolha_iterativa(int v[], int n){
    while (n > 1){
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i+1])
            {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        n--;
    }
}
void bolha_recursiva(int v[], int n)
{
    if (n > 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i+1])
            {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        bolha_recursiva(v, n - 1); // repete com 1 elemento a menos
    }
}

int main(){
    int v[]={5,33,114,2,31,42,5,64,3,88,6,3,1};
    bolha_recursiva(v,11);
    for(int x=0;x<11;x++){
        printf("\n%i",v[x]);
    }
    return 0;
}

