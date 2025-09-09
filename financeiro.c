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
