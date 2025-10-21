/*
|=============================================================|
|                    MODULO FINANCEIRO                        |
| Controle de entradas (sessões/produtos) e saídas (salários) |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "financeiro.h"
#include "utils.h"

#define ARQUIVO_FINANCEIRO "financeiro.dat"

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

int salvarMovimentacao(Movimentacao *m) {
    FILE *arquivo = fopen(ARQUIVO_FINANCEIRO, "ab");
    if (arquivo == NULL) {
        return 0;
    }
    size_t escrito = fwrite(m, sizeof(Movimentacao), 1, arquivo);
    fclose(arquivo);
    return (escrito == 1);
}

int carregarMovimentacoes(Movimentacao **movimentacoes, int *quantidade) {
    FILE *arquivo = fopen(ARQUIVO_FINANCEIRO, "rb");
    if (arquivo == NULL) {
        *movimentacoes = NULL;
        *quantidade = 0;
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *quantidade = tamanho / sizeof(Movimentacao);

    if (*quantidade == 0) {
        *movimentacoes = NULL;
        fclose(arquivo);
        return 1;
    }

    *movimentacoes = (Movimentacao*)malloc((*quantidade) * sizeof(Movimentacao));
    if (*movimentacoes == NULL) {
        fclose(arquivo);
        return 0;
    }

    size_t lidos = fread(*movimentacoes, sizeof(Movimentacao), *quantidade, arquivo);
    fclose(arquivo);

    return (lidos == *quantidade);
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

void listarFinanceiro() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║      LISTAR MOVIMENTAÇÕES FINANCEIRAS        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Nenhuma movimentação registrada ainda.\n");
    printf("Use as opções de entrada ou saída para registrar.\n");
    pausar();
}

void financeiro() {
    int opcao;

    do {
        menuFinanceiro();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1:
                registrarEntrada();
                break;
            case 2:
                registrarSaida();
                break;
            case 3:
                listarFinanceiro();
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n");
                break;
            default:
                limparTela();
                printf("\n Opção inválida! Digite um número entre 0 e 3.\n");
                pausar();
                break;
        }

    } while(opcao != 0);
}
