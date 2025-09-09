/*
|=============================================================|
|                    MODULO FINANCEIRO                        |
| Controle de entradas (sessões/produtos) e saídas (salários) |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include "financeiro.h"
#include "utils.h"

void menuFinanceiro() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              MÓDULO FINANCEIRO               ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Registrar Entrada de Dinheiro             ║\n");
    printf("║ 2. Registrar Saída de Dinheiro               ║\n");
    printf("║ 3. Listar Movimentações Financeiras          ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

void registrarEntrada() {
    float valor;
    char descricao[100];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║         REGISTRAR ENTRADA DE DINHEIRO        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o valor da entrada (R$): ");
    if (scanf("%f", &valor) != 1) {
        printf("\n Erro: Valor inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    limparBuffer();
    printf("Digite a descrição da entrada (sessão/produto): ");
    if (scanf(" %99[^\n]", descricao) != 1) {
        printf("\n Erro: Descrição inválida!\n");
        pausar();
        return;
    }

    printf("\n Entrada registrada com sucesso!\n");
    printf("Valor: R$ %.2f | Descrição: %s\n", valor, descricao);
    pausar();
}

void registrarSaida() {
    float valor;
    char cpf[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          REGISTRAR SAÍDA DE DINHEIRO         ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o valor do pagamento (R$): ");
    if (scanf("%f", &valor) != 1) {
        printf("\n Erro: Valor inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o CPF do massoterapeuta: ");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Saída registrada com sucesso!\n");
    printf("Valor: R$ %.2f | Pago ao massoterapeuta CPF: %s\n", valor, cpf);
    pausar();
}
