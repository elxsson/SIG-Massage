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

int validarCPF(char *cpf) {
    int digitos = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) digitos++;
    }
    return (digitos == 11);
}

int lerCPF(char *cpf, int tamanho) {
    printf("Digite o CPF (11 dígitos): ");
    scanf(" %19s", cpf);
    limparBuffer();
    if (!validarCPF(cpf)) {
        printf(" Erro: CPF inválido! Deve conter 11 dígitos.\n");
        return 0;
    }
    return 1;
}

int validarTelefone(char *telefone) {
    int digitos = 0;
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (isdigit(telefone[i])) digitos++;
    }
    return (digitos >= 10 && digitos <= 11);
}

int lerTelefone(char *telefone, int tamanho) {
    printf("Digite o telefone (10 ou 11 dígitos): ");
    scanf(" %19[^\n]", telefone);
    limparBuffer();
    if (!validarTelefone(telefone)) {
        printf(" Erro: Telefone inválido! Deve ter 10 ou 11 dígitos.\n");
        return 0;
    }
    return 1;
}

int lerEmail(char *email, int tamanho) {
    printf("Digite o email: ");
    scanf(" %69[^\n]", email);
    limparBuffer();
    return 1;
}
