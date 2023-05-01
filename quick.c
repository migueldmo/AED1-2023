/*Autor: Miguel de Moura Oliveira
/*EP05 - AED1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5000 /*tamanho do vetor desejado (n). Para testar com outros parâmetros, basta alterar o valor desta variável global*/

/*A função abaixo recebe um vetor v[p,...,r], com p <= r. Rearranja os
elementos do vetor e devolve j em p,..,r tal que v[p,...,j-1] <= v[j] < v[j+1,...,r].
*/
int separa(int p, int r, int v[]){
    int c, j, k, t;

    c = v[r]; j= p;

    for(k = p; k < r; k++){
        if(v[k] <= c){
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }

    v[r] = v[j], v[j] = c;

    return j;
}

/*A função abaixo rearranja o vetor v[p,...,r], com p <= r+1,
de modo que ele fique em ordem crescente.*/
void Quicksort(int p, int r, int v[]){
    int j;

    if(p < r){
        j = separa(p, r, v);
        Quicksort(p, j-1, v);
        Quicksort(j+1, r, v);
    }
}

int main(){
    int v[TAM];
    int i;

    long antes, depois;
    double total;

    srand(time(NULL));
    /*geração de um vetor com valores aleatórios*/
    for(i= 0; i < TAM; i++){
        v[i] = rand() % 10000;
    }
    antes = clock();
    Quicksort(0 ,TAM-1, v);
    depois = clock();

    total = (double)(depois-antes)/CLOCKS_PER_SEC;

    printf("%lf\n", total);

}
