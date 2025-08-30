#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void menuAgendamentos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              MODULO AGENDAMENTOS             ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. novo agendamento                          ║\n");
    printf("║ 2. Listar Agendamentos                       ║\n");
    printf("║ 3. Atualizar Agendamento                     ║\n");
    printf("║ 4. Excluir Agendamento                       ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}



void novoAgendamento() {
    int diaSemana, hora;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               NOVO AGENDAMENTO               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Hora     Segunda     Terca     Quarta     Quinta     Sexta     Sabado\n");
    printf("------------------------------------------------------------------------\n");

    printf("08h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("09h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("10h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("11h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("12h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("13h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("14h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("15h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("16h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("17h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");
    printf("18h      [   ]       [   ]     [   ]      [   ]      [   ]     [   ]\n");

    printf("===============================================\n");

    printf("escolha o dia da semana (1-6): ");
    if (scanf("%d", &diaSemana) != 1 || diaSemana < 1 || diaSemana > 6) {
        printf("\n Erro: Dia da semana inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Escolha a hora (8-18): ");
    if (scanf("%d", &hora) != 1 || hora < 8 || hora > 18) {
        printf("\n Erro: Hora inválida!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Agendamento criado com sucesso para o dia %d às %dh!\n", diaSemana, hora);
    pausar();
}



void listarAgendamentos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              LISTAR AGENDAMENTOS             ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Nenhum agendamento encontrado.\n");
    pausar();
}



void atualizarAgendamento() {
    int id;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            ATUALIZAR AGENDAMENTO             ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o ID do agendamento a ser atualizado: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\n Erro: ID inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Agendamento com ID %d atualizado com sucesso!\n", id);
    pausar();
}



void excluirAgendamento() {
    int id;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             EXCLUIR AGENDAMENTO              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o ID do agendamento a ser excluído: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\n Erro: ID inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Agendamento com ID %d excluído com sucesso!\n", id);
    pausar();
}
