/* Problema 1172 Beecrowd
Autor: Miguel de Moura Oliveira
*/
#include <stdio.h>
#include <stdlib.h>

void busca_subs(int v[]){
    int k, *p;
    for(k = 0;k < 10; k++){
        if(v[k] == 0 || v[k] < 0){
            p = &v[k];
            *p = 1;
        }
    }
    for(k = 0; k < 10; k++){
        printf("X[%d] = %d\n", k, v[k]);
    }
}

int main(){
    int *v, i;
    v = (int *)malloc((10)*sizeof(int));
    for(i = 0; i < 10; i++)
        scanf("%d", &v[i]);
    busca_subs(v);
    
    return 0;
}
