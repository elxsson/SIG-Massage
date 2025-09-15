/*
|=============================================================|
|                    MODULO AGENDAMENTOS                      |
| CRUD para a gestao de clientes do sistema SIG-MASSAGE       |
|=============================================================|
*/


#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "agendamentos.h"

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
    int diaSemana, hora, tipoMassagem;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              NOVO AGENDAMENTO                ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║              TIPOS DE MASSAGEM               ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  1) Relaxante        5) Ayurvédica           ║\n");
    printf("║  2) Terapêutica      6) Reflexologia         ║\n");
    printf("║  3) Esportiva        7) Pedras Quentes       ║\n");
    printf("║  4) Shiatsu          8) Drenagem Linfática   ║\n");
    printf("║  9) Massagem Facial                          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
    if (scanf("%d", &tipoMassagem) != 1 || tipoMassagem < 1 || tipoMassagem > 9) {
        printf("\n Erro: Tipo de massagem inválido!\n");
        limparBuffer();
        pausar();
        return;
    }



    

    printf("Hora     Segunda     Terca     Quarta     Quinta     Sexta     Sabado\n");
    printf("--------------------------------------------------------------------\n");

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
    printf("====================================================================\n");

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
    char confirmacao;
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

    printf("Tem certeza que deseja excluir? (s/N): ");
    limparBuffer();
    scanf("%c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        printf("\n Função de exclusão de agendamento ainda não implementada.\n");
        printf("ID que seria excluído: %i\n",id);
    } else {    
        printf("\n Operação cancelada pelo usuário.\n");
    }
    
    pausar();

    printf("\n Agendamento com ID %d excluído com sucesso!\n", id);
    pausar();
}



void agendamentos() {
    int opcao;
    do {
        menuAgendamentos();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Entrada inválida!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch (opcao) {
            case 1:
                novoAgendamento();
                break;
            case 2:
                listarAgendamentos();
                break;
            case 3:
                atualizarAgendamento();
                break;
            case 4:
                excluirAgendamento();
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n");
                break;
            default:
                printf("\n Erro: Opção inválida!\n");
                pausar();
        }

    } while (opcao != 0);

}

 