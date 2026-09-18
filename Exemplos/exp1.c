#include <stdio.h>
int main(){
    int x = 10;
    int *p;      /* p é um ponteiro para int */
    p = &x;      /* p passa a guardar o endereço de x */
    printf("%d\n", *p);   /* imprime 10: "vá até o endereço em p e leia" */
    *p = 99;    /* escreve 99 DENTRO de x, sem tocar no nome x */
    printf("%d", *p);   /* imprime 99: "vá até o endereço em p e leia" */
    return 0;
}