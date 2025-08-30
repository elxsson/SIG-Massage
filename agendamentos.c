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
