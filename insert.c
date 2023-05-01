#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5000 /*tamanho do vetor desejado (n). Para testar com outros parâmetros, basta alterar o valor desta variável global*/

/*A função abaixo recebe um vetor v[p,...,r], com p <= r. Rearranja os
elementos do vetor e devolve j em p,..,r tal que v[p,...,j-1] <= v[j] < v[j+1,...,r].
*/

/*O procedimento abaixo recebe um inteiro n e um vetor v[0,...,n-1] e rearranja-o
em ordem crescente.*/
void insert(int n, int v[]){
    int i, j, x;

    for(j = 1; j < n; j++){
        x = v[j];
        for(i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x; 
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
    insert(TAM-1, v);
    depois = clock();

    total = (double)(depois-antes)/CLOCKS_PER_SEC;

    printf("%lf\n", total);

}
