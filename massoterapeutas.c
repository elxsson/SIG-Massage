/*
|=============================================================|
|                  MODULO MASSOTERAPEUTA                      |
| CRUD para a gestao de massoterapeutas do sistema SIG-MASSAGE|
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "massoterapeutas.h"
#include "utils.h"

#define MASSOTERAPEUTAS_FILE "massoterapeutas.dat"


void menuMassoterapeutas() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             MODULO MASSOTERAPEUTA            ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Massoterapeuta                  ║\n");
    printf("║ 2. Listar Massoterapeutas                    ║\n");
    printf("║ 3. Procurar Massoterapeuta                   ║\n");
    printf("║ 4. Atualizar Dados do Massoterapeuta         ║\n");
    printf("║ 5. Excluir Massoterapeuta                    ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}



void massoterapeutas() {
    int opcao;

    do {
        menuMassoterapeutas();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                cadastrarMassoterapeuta(); 
                break;
            case 2: 
                listarMassoterapeutas(); 
                break;
            case 3: 
                buscarMassoterapeuta(); 
                break;
            case 4: 
                atualizarMassoterapeuta(); 
                break;
            case 5: 
                deletarMassoterapeuta(); 
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n"); 
                break;
        
            default:
                limparTela();
                printf("\n Opção inválida! Digite um número entre 0 e 5.\n");
                pausar();
                break;
        }

    } while(opcao != 0);
}