#include <stdio.h>
#include <string.h>

int main() {
    int n, num;
    char v1[21], v2[21];
    int ingles;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &num);
        scanf(" %s", v1);
        num--;
        ingles = 0;
        strcpy(v2, v1);

        while (num--) {
            if (strcmp(v1, v2) != 0 && !ingles) {
                ingles = 1;
            } else {
                strcpy(v2, v1);
            }
            scanf(" %s", v1);
        }

        if (ingles) {
            printf("ingles\n");
        } else {
            printf("%s\n", v1);
        }
    }

    return 0;
}
