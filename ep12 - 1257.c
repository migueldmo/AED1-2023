/*Miguel de Moura Oliveira 
159327
*/
#include <stdio.h>

int soma(char *linha, int j) {
    int k, total = 0;
    for (k = 0; linha[k] != '\0'; k++)
        total += linha[k] - 'A' + j + k;
    return total;
}

int main() {
    int n, i, j, l, k, tot;
    char linha[51];
    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d%*c", &l);
        tot = 0; 

        for (j = 0; j < l; j++) {
            scanf("%[^\n]%*c", linha);
            tot += soma(linha, j);
        }

        printf("%d\n", tot);
    }

    return 0;
}
