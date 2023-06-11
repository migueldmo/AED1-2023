/*Beecrowd 1256
Miguel de Moura Oliveira
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
  int num;
  struct Lista *prox;
}Lista;

int indiceTabela(int x, int y) { return x % y; }

void insere(Lista **tabela, int x, int y) {
  int i = indiceTabela(x, y);

  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->num = x;
  novo->prox = NULL;

  if (tabela[i] == NULL) {
    tabela[i] = novo;
  } else {
    Lista *aux = tabela[i];
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

void imprime(Lista **tabela, int x) {
  int i;
  for (i = 0; i < x; i++) {
    printf("%d -> ", i);
    Lista *aux = tabela[i];
    while (aux != NULL) {

      printf(" %d -> ", aux->num);
      aux = aux->prox;
    }
    printf("\\\n");
  }
}

void libera(Lista **tabela, int x) {
  int i;
  for (i = 0; i < x; i++) {
    Lista *aux = tabela[i];
    while (aux != NULL) {
      Lista *p = aux;
      aux = aux->prox;
      free(p);
    }
  }
  free(tabela);
}

int main() {
  int N, X, M, C, i;
  scanf("%d", &N);

  while (N--) {

    scanf("%d %d", &M, &C);

    Lista **tabela = (Lista **)malloc(M * sizeof(Lista *));
    for (i = 0; i < M; i++) {
      tabela[i] = NULL;
    }

    for (int i = 0; i < C; i++) {

      scanf("%d", &X);
      insere(tabela, X, M);
    }

    imprime(tabela, M);
    libera(tabela, M);
  }

  return 0;
}
