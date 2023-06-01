#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel{
  char x;
  struct cel *dir;
  struct cel *esq;
};
typedef struct cel no;

no* insere(no *aux, char k){
  if(aux == NULL){
    no *novo = malloc(sizeof(no));
    novo->x = k;
    novo->dir = novo->esq = NULL;
    return novo;
  }
  else 
    if(strcmp(aux->x, k) < 0)
      aux->esq = insere(aux->esq, k);
    else
      aux->dir = insere(aux->dir, k);
    return aux;
}

no* busca (no *aux, char k){
  if(aux == NULL || strcmp(aux->x, k) == 0)
    return aux;
  if(strcmp(aux->x, k) > 0)
    return busca(aux->esq, k);
  else
    return busca(aux->dir, k);
}
void imprimeIN(no *aux){
  if(aux != NULL){
    imprimeIN(aux->esq);
    printf("%s", aux->x);
    imprimeIN(aux->dir);
  }
}
void imprimePRE(no *aux){
  if(aux != NULL){
    printf("%s", aux->x);
    imprimePRE(aux->esq);
    imprimePRE(aux->dir);
  }
}
void imprimePOS(no *aux){
  if(aux != NULL){
    imprimePOS(aux->esq);
    imprimePOS(aux->dir);
    printf("%s", aux->x);
  }
}
int main(void) {
  no *arvore = NULL, *novo;
  
  char A, op;
  scanf("%c %c", &op, &A);
  while(scanf("%c", &A) != EOF){
    if(strcmp(op, "I") == 0)
      novo = insere(arvore, A);
    if(strcmp(op, "P") == 0){
      if(busca(arvore, A) != NULL)
        printf("%c existe\n", A);
      else
        printf("%c nao existe\n", A);
    }
    if(strcmp(op, "INFIXA") == 0)
      imprimeIN(arvore);
    if(strcmp(op, "POSFIXA") == 0)
      imprimePOS(arvore);
    if(strcmp(op, "PREFIXA") == 0)
      imprimePRE(arvore);
  }
}