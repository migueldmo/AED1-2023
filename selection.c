#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5000

void selection(int n, int v[]){
    int i, j, min, x;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++)
            if(v[j] < v[min]) min = j;
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}

int main(){
    
    int v[TAM];
    int i;
    long antes, depois;
    double total;

    

    srand(time(NULL));

    for(i= 0; i < TAM; i++){
        v[i] = rand() % 10000;
    }
    antes = clock();
    selection(TAM-1, v);
    depois = clock();

    total = (double)(depois-antes)/CLOCKS_PER_SEC;

    printf("%lf\n", total);

}