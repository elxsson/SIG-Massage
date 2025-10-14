/*
|=============================================================|
|                          UTILS                              |
| Funções utilitárias compartilhadas pelo sistema SIG-MASSAGE |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    system("clear || cls");
}

int lerNome(char *nome, int tamanho) {
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nome);
    limparBuffer();
    return 1;
}

int lerCPF(char *cpf, int tamanho) {
    printf("Digite o CPF (apenas números ou com pontos/traços): ");
    scanf(" %19s", cpf);
    limparBuffer();
    return 1;
}
