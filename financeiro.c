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

int atualizarArquivoMovimentacoes(Movimentacao *movimentacoes, int quantidade) {
    FILE *arquivo = fopen(ARQUIVO_FINANCEIRO, "wb");
    if (arquivo == NULL) {
        return 0;
    }
    size_t escritos = fwrite(movimentacoes, sizeof(Movimentacao), quantidade, arquivo);
    fclose(arquivo);
    return (escritos == quantidade);
}

void registrarEntrada() {
    Movimentacao *mov = (Movimentacao*)malloc(sizeof(Movimentacao));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║         REGISTRAR ENTRADA DE DINHEIRO        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    if (!lerValor(&mov->valor)) {
        free(mov);
        pausar();
        return;
    }

    if (!lerDescricao(mov->descricao, sizeof(mov->descricao))) {
        free(mov);
        pausar();
        return;
    }

    mov->tipo = 'E';
    strcpy(mov->cpf, "");
    mov->status = 1;

    if (salvarMovimentacao(mov)) {
        printf("\n Entrada registrada com sucesso!\n");
        printf("Valor: R$ %.2f | Descrição: %s\n", mov->valor, mov->descricao);
    } else {
        printf("\n Erro ao salvar entrada!\n");
    }

    free(mov);
    pausar();
}

void registrarSaida() {
    Movimentacao *mov = (Movimentacao*)malloc(sizeof(Movimentacao));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          REGISTRAR SAÍDA DE DINHEIRO         ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    if (!lerValor(&mov->valor)) {
        free(mov);
        pausar();
        return;
    }

    if (!lerCPF(mov->cpf, sizeof(mov->cpf))) {
        free(mov);
        pausar();
        return;
    }

    if (!lerDescricao(mov->descricao, sizeof(mov->descricao))) {
        free(mov);
        pausar();
        return;
    }

    mov->tipo = 'S';
    mov->status = 1;

    if (salvarMovimentacao(mov)) {
        printf("\n Saída registrada com sucesso!\n");
        printf("Valor: R$ %.2f | CPF: %s\n", mov->valor, mov->cpf);
    } else {
        printf("\n Erro ao salvar saída!\n");
    }

    free(mov);
    pausar();
}

void listarFinanceiro() {
    FILE *fp;
    Movimentacao *mov;
    int movAtivas = 0;
    float totalEntradas = 0.0;
    float totalSaidas = 0.0;

    mov = (Movimentacao*)malloc(sizeof(Movimentacao));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║      LISTAR MOVIMENTAÇÕES FINANCEIRAS        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_FINANCEIRO, "rb");
    if (fp == NULL) {
        printf("Nenhuma movimentação registrada ainda.\n");
        printf("Use as opções de entrada ou saída para registrar.\n");
        free(mov);
        pausar();
        return;
    }

    printf("========================================================================================\n");
    printf("Tipo         Valor        Descrição                                  CPF Massoterapeuta\n");
    printf("========================================================================================\n");

    while (fread(mov, sizeof(Movimentacao), 1, fp)) {
        if (mov->status == 1) {
            char *tipo = mov->tipo == 'E' ? "ENTRADA" : "SAÍDA";
            char sinal = mov->tipo == 'E' ? '+' : '-';
            char cpfDisplay[20] = "-";
            
            if (mov->tipo == 'S' && strlen(mov->cpf) > 0) {
                strcpy(cpfDisplay, mov->cpf);
            }
            
            printf("%-12s %cR$ %-9.2f %-40s %s\n",
                   tipo,
                   sinal,
                   mov->valor,
                   mov->descricao,
                   cpfDisplay);
            
            if (mov->tipo == 'E') {
                totalEntradas += mov->valor;
            } else {
                totalSaidas += mov->valor;
            }
            movAtivas++;
        }
    }
    
    printf("========================================================================================\n");

    if (movAtivas == 0) {
        printf("Nenhuma movimentação ativa encontrada.\n");
    } else {
        printf("\n=== RESUMO FINANCEIRO ===\n");
        printf("Total de Entradas: R$ %.2f\n", totalEntradas);
        printf("Total de Saídas: R$ %.2f\n", totalSaidas);
        printf("Saldo: R$ %.2f\n", totalEntradas - totalSaidas);
        printf("\nTotal de movimentações: %d\n", movAtivas);
    }

    fclose(fp);
    free(mov);
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
