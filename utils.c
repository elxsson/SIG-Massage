/*
|=============================================================|
|                          UTILS                              |
| Funções utilitárias compartilhadas pelo sistema SIG-MASSAGE |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int validarNome(char *nome) {
    if (strlen(nome) == 0) return 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') return 0;
    }
    return 1;
}

int lerNome(char *nome, int tamanho) {
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nome);
    limparBuffer();
    if (!validarNome(nome)) {
        printf(" Erro: Nome inválido! Use apenas letras e espaços.\n");
        return 0;
    }
    return 1;
}

int lerCPF(char *cpf, int tamanho) {
    printf("Digite o CPF (apenas números ou com pontos/traços): ");
    scanf(" %19s", cpf);
    limparBuffer();
    return 1;
}

int lerTelefone(char *telefone, int tamanho) {
    printf("Digite o telefone (ex: (84) 99999-9999): ");
    scanf(" %19[^\n]", telefone);
    limparBuffer();
    return 1;
}

int lerEmail(char *email, int tamanho) {
    printf("Digite o email: ");
    scanf(" %69[^\n]", email);
    limparBuffer();
    return 1;
}
