/*Problema 2381 Beecrowd
Autor: Miguel de Moura Oliveira
Disciplina: Algorítmos e Estrutura de Dados 1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct elemento
{
    char nome[MAX];
    struct elemento *prox; 
} Tipoelemento;

typedef struct Lista
{
    Tipoelemento *primeiro, *ultimo;
    int t;
}TipoLista;

/*O procedimento abaixo recebe uma lista e ajusta seus parâmetros para os iniciais*/
void inicializa(TipoLista *aux){
    aux->primeiro = NULL;
    aux->ultimo = NULL;
    aux->t = 0;
}

/*O procedimento abaixo recebe um elemento a ser inserido em ordem alfabética e sua respectiva lista*/
void insere_ordenado(TipoLista *aux, char *x){
    Tipoelemento *novo, *p, *q;
    novo = malloc(sizeof(Tipoelemento));

    strcpy(novo->nome, x);

    p = aux->primeiro;

    if(aux->t == 0){
        aux->primeiro = novo;
        aux->ultimo = novo;
        novo->prox = NULL;
    }
    else{
        q = p;

        if(strcmp(p->nome, x) > 0){
            novo->prox = p;
            aux->primeiro = novo;
        }
        else{
            while(p != NULL && !(strcmp(p->nome,x) >= 0)){ 
                q = p;
                p = p->prox;
            }   
            if(q->prox != p)
                q = q->prox;    
            q->prox = novo;
            novo->prox = p;
            
        }
    }  

    aux->t++;
}
/*O procedimento abaixo recebe uma lista e imprime seus elementos*/
void imprime(TipoLista *aux){
    Tipoelemento *p = aux->primeiro;

    while(p != NULL){       
        printf("%s ", p->nome);
        p = p->prox;
    }

}
/*A função abaixo recebe a lista e um inteiro x que representa o número da posição do elemento da lista a ser buscado
e retorna o conteúdo deste elemento
*/
char* busca(TipoLista *aux, int x){
    Tipoelemento *p;
    int i = 1;

    p = aux->primeiro;

    while(i < x){
        p = p->prox;
        i++;
    }
    return p->nome;
}
/*O procedimento abaixo recebe uma lista e desaloca seus elementos*/
void libera(TipoLista *aux){
    Tipoelemento *p, *q;
    p = aux->primeiro;

    if(aux->t == 1)
        free(p);
    else{
        while(p->prox != NULL){
            q = p;
            p = p->prox;
            free(q);
        }
        free(p);
    }
}

int main(){
    TipoLista Minhalista;
    char nome[MAX];
    int n,i, num;

    inicializa(&Minhalista);

    scanf("%d %d", &n, &num);

    for(i = 0; i < n; i++){
        scanf("%s", &nome);
        insere_ordenado(&Minhalista, nome);
    }

    printf("%s\n", busca(&Minhalista, num));
    
    libera(&Minhalista);
    
    return 0;
}
