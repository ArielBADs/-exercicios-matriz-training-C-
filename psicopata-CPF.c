#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define alfa_tam 26

typedef struct {
    char cpf[12];
    char nome[11];
    char senha[11];
} alunos;

int main()
{
    int N;
    int i, j;
    
    scanf("%d", &N);

    alunos *desloc = malloc(N * sizeof(alunos));

    for (i = 0 ; i < N ; i++) {
        scanf(" %s %s", desloc[i].nome, desloc[i].cpf);
        for (j = 0 ; j < strlen(desloc[i].nome); j++) {
            int v = (int) (desloc[i].cpf[j] > 47 && desloc[i].cpf[j] < 58) ? desloc[i].cpf[j] - 48 : -1;
            
            if (desloc[i].nome[j] >= 'a' && desloc[i].nome[j] <= 'z') {
                desloc[i].senha[j] = 'a' + (desloc[i].nome[j] - 'a' + v) % alfa_tam;
            }
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N-1-i; j++){
            if(strcmp(desloc[j].nome, desloc[j+1].nome) > 0){
                alunos aux = desloc[j];
                desloc[j] = desloc[j+1];
                desloc[j+1] = aux;
            }
        }
    }
    
    for (i = 0 ; i < N ; i++){
        printf("%s ", desloc[i].nome);
        printf("%s%c%c\n", desloc[i].senha, desloc[i].cpf[9], desloc[i].cpf[10]);
    }

    free(desloc);
    return 0;
}

