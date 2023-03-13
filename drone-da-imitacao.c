#include <stdio.h>
#include <string.h>

int palindromo(char *str, int len) {
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char matriz[n][n+1];
    for (int i = 0; i < n; i++) {
        scanf(" %s", matriz[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Verifica palindromo horizontal
            if (j <= n-k) {
                char palavra[k+1];
                for (int l = 0; l < k; l++) {
                    palavra[l] = matriz[i][j+l];
                }
                palavra[k] = '\0';

                if (palindromo(palavra, k)) {
                    printf("(%d, %d)\n", i, j);
                    return 0;
                }
            }

            // Verifica palindromo vertical
            if (i <= n-k) {
                char palavra[k+1];
                for (int l = 0; l < k; l++) {
                    palavra[l] = matriz[i+l][j];
                }
                palavra[k] = '\0';

                if (palindromo(palavra, k)) {
                    printf("(%d, %d)\n", i, j);
                    return 0;
                }
            }
        }
    }

    printf("(-1, -1)\n");
    return 0;
}
