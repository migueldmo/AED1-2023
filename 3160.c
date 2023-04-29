/*Problema 3160 Beecrowd
Autor: Miguel de Moura Oliveira - Disciplina: Algorítmo e Estruras de Dados 1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct elemento
{
    char nome[MAX];
    struct elemento *prox;
};
typedef struct elemento tipoElemento;
struct Lista
{
    tipoElemento *primeiro, *ultimo;
    int tamanho;
};
typedef struct Lista tipoLista;

/*O procedimento abaixo recebe uma lista e ajusta seus parâmetros para os iniciais*/
void inicializa(tipoLista *aux){
    aux->primeiro = NULL;
    aux->ultimo = NULL;
    aux->tamanho = 0;
}
/*O procedimento abaixo recebe um elemento a ser inserido na lista e a sua respectiva lista*/
void insere(tipoLista *aux, char *x){
    tipoElemento *novo;
    novo = malloc(sizeof(tipoElemento));

    strcpy(novo->nome, x);

    if(aux->tamanho == 0){
        aux->primeiro = novo;
        aux->ultimo = novo;
        novo->prox = NULL;
    }
    else{
        aux->ultimo->prox = novo;
        novo->prox = NULL;
        aux->ultimo = novo;
    }
    aux->tamanho++;
}
/*O procedimento abaixo recebe uma lista e imprime seus elementos*/
void imprime(tipoLista *aux){
    tipoElemento *q = aux->primeiro;

    while(q->prox != NULL){
        printf("%s ",  q->nome);
        q = q->prox;
    }
    printf("%s\n",  q->nome);
}
/*O procedimento abaixo recebe três listas e as comparam e une-as caso um elemento coexistir em duas*/
void compara(tipoLista *Lista1,tipoLista *Lista2, tipoLista *Lista3){
    char str[MAX];
    tipoElemento *q = Lista3->primeiro;
    tipoElemento *p = Lista1->primeiro;
    tipoElemento *aux = Lista1->primeiro;

    if(strcmp(q->nome, p->nome) == 0){
        Lista2->ultimo->prox = Lista1->primeiro;
        Lista1->primeiro = Lista2->primeiro;
        Lista1->ultimo = Lista2->ultimo;
        return;
    }
    else if(strcmp(q->nome, "nao") == 0){
        Lista1->ultimo->prox = Lista2->primeiro;
        return;
    }

    strcpy(str, q->nome);

    while(aux != NULL && strcmp(aux->nome, str)!= 0){
        p = aux;
        aux = aux->prox;
    }
    if(aux == Lista1->primeiro){

        Lista2->ultimo->prox = aux;
    }
    else if(aux){
        Lista2->ultimo->prox = aux; 
        p->prox = Lista2->primeiro;
    }       
}

int main(){
    tipoElemento *comp;
    char n1[MAX],n2[MAX], n3[MAX];
    tipoLista MinhaLista, MinhaLista2, MinhaLista3;

    inicializa(&MinhaLista);
    inicializa(&MinhaLista2);
    inicializa(&MinhaLista3);

    gets(n1);
    char *token1 = strtok(n1, " ");
    while(token1 != NULL){
        insere(&MinhaLista, token1);
        token1 = strtok(NULL, " ");
    }
    gets(n2);
    char *token2 = strtok(n2, " ");
    while(token2 != NULL) {
        insere(&MinhaLista2, token2);
        token2 = strtok(NULL, " ");
    }
    
    gets(n3);
    char *token3 = strtok(n3, " ");
    while(token3 != NULL) {
        insere(&MinhaLista3, token3);
        token3 = strtok(NULL, " ");
    }

    compara(&MinhaLista,&MinhaLista2, &MinhaLista3);

    imprime(&MinhaLista);

    return 0;
}
