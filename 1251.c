/*Miguel de Moura Oliveira
RA: 159327
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct No {
    char* palavra;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(const char* palavra) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->palavra = strdup(palavra);
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, const char* palavra) {
    if (raiz == NULL) {
        return criarNo(palavra);
    }
    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp < 0) {
        raiz->esq = inserirNo(raiz->esq, palavra);
    } else if (cmp > 0) {
        raiz->dir = inserirNo(raiz->dir, palavra);
    }
    return raiz;
}

void libera(No* raiz) {
    if (raiz != NULL) {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz->palavra);
        free(raiz);
    }
}

void imprime(No* raiz, const char* palavraAnterior) {
    if (raiz != NULL) {
        imprime(raiz->esq, palavraAnterior);
        if (palavraAnterior == NULL || strcmp(raiz->palavra, palavraAnterior) != 0) {
            printf("%s\n", raiz->palavra);
        }
        imprime(raiz->dir, raiz->palavra);
    }
}

int main() {
    No* raiz = NULL;

    char linha[200];
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
       
        for (int i = 0; linha[i]; i++) {
            if (!isalpha(linha[i]) && !isspace(linha[i])) {
                linha[i] = ' ';
            }
        }

        char* token = strtok(linha, " \t\n");
        while (token != NULL) {
            
            char* palavra = token;
            int tamanhoPalavra = strlen(palavra);
            int j = 0;
            for (int i = 0; i < tamanhoPalavra; i++) {
                if (!isspace(palavra[i])) {
                    palavra[j++] = tolower(palavra[i]);
                }
            }
            palavra[j] = '\0';

            if (j > 0) {
                // Inserir palavra na árvore
                raiz = inserirNo(raiz, palavra);
            }
            token = strtok(NULL, " \t\n");
        }
    }

    imprime(raiz, NULL);

    libera(raiz);

    return 0;
}
