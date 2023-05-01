/*Autor: Miguel de Moura Oliveira
EP05 - AED1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5000 /*tamanho do vetor desejado (n). Para testar com outros parâmetros, basta alterar o valor desta variável global*/

/*O procedimento abaixo recebe um vetor v[p,...,q-1] e v[q,...r-1] e 
rearranja v[p,...,r-1] em ordem crescente.
*/ 
void intercala(int p, int q,int r, int v[]){
    int i, j, k, *w;

    w = malloc((r-p) * sizeof(int));

    i = p; j = q; k = 0;

    while(i < q && j < r){
        if(v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for(i = p; i < r; i++) v[i] = w[i-p];

    free(w);
}
/*O procedimento abaixo rearranja o vetor v[p,...,r-1] em ordem crescente.*/
void Mergesort(int p, int r, int v[]){

    if(p < r-1){
        int q = (p + r)/2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main(){
    
    int v[TAM];
    int i;
    long antes, depois;
    double total;

    srand(time(NULL));
    /*Gerando um vetor com valores aleatórios*/
    for(i= 0; i < TAM; i++){
        v[i] = rand() % 10000;
    }

    antes = clock();
    Mergesort(0,TAM-1, v);
    depois = clock();

    total = (double)(depois-antes)/CLOCKS_PER_SEC;

    printf("%lf\n", total);

}
