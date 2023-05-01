/*Autor: Miguel de Moura Oliveira
EP05 - AED1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20000 /*tamanho do vetor desejado (n). Para testar com outros parâmetros, basta alterar o valor desta variável global*/

/*O procedimento abaixo recebe um max-heap v[1,...,m] e transforma
v[1,...,m+1] em max heap*/
void insereEmHeap(int m, int v[]){
    int t, f = m+1;

    while(f > 1 && v[f/2] < v[f]){
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f = f/2;
    }
}
/*O procedimento abaixo rearranja v[1,..,m] nas propriedades de um heap*/
void heapify(int m, int v[]){
    int t, f = 2;

    while(f <= m){
        if(f < m && v[f] < v[f+1])  ++f;
        if(v[f/2] >= v[f])  break;
        t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f *= 2;
    }
}

/*O procedimento abaixo rearranja o vetor v[1,...,n] de modo que ele fique
crescente.*/
void Heapsort(int n, int v[]){
    int m, t;

    for(m = 1; m < n; m++)
        insereEmHeap(m, v);

    for(m = n; m > 1; m--){
        t = v[1]; v[1] = v[m]; v[m] = t;
        heapify(m-1, v);
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
    Heapsort(TAM-1, v);
    depois = clock();

    total = (double)(depois-antes)/CLOCKS_PER_SEC;

    printf("%lf", total);

}
