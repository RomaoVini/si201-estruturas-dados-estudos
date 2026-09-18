#include <stdio.h>
int main(){

    typedef struct aluno {
        int ra;
        float nota;
    }aluno;

    aluno a;
    a.ra = 200123;        /* acesso por variável:  ponto  */

    aluno *pa = &a;
    pa->ra = 200123;      /* acesso por ponteiro:  seta   */
    (*pa).ra = 200129;   /* exatamente a mesma coisa que a linha acima */

    printf("%d", a.ra);

    return 0;
}