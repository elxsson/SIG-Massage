#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "clientes.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "clientes.dat"

void menuRelatorios() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                MODULO RELATORIOS             ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Listar Clientes                           ║\n");
    printf("║ 2. Listar Agendamentos                       ║\n");
    printf("║ 3. Listar Massoterapeutas                    ║\n");
    printf("║ 4. Listar Produto                            ║\n");
    printf("║ 4. Listar Financeiro                         ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

void listarClientesGeral() {
    FILE *fp;
    Cliente *cliente;

    cliente = (Cliente*)malloc(sizeof(Cliente));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            LISTAR CLIENTES                   ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_CLIENTES, "rb");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado ainda.\n");
        free(cliente);
        pausar();
        return;
    }

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
            printf("──────────────────────────────────────────────\n");
            printf("Nome: %s\n", cliente->nome);
            printf("CPF: %s\n", cliente->cpf);
            printf("Telefone: %s\n", cliente->telefone);
            printf("Email: %s\n", cliente->email);

    }
    printf("──────────────────────────────────────────────\n");

    fclose(fp);
    free(cliente);
    pausar();
}

void relatorios() {
    int opcao;

    do {
        menuRelatorios();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                listarClientesGeral(); 
                break;
            case 2: 
                //listarAgendamentos(); 
                break;
            case 3: 
                //listarMassoterapeutas(); 
                break;
            case 4: 
                //listarProdutos(); 
                break;
            case 5: 
                //listarFinanceiro(); 
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n"); 
                break;
        
            default:
                printf("\n Opção inválida! Digite um número entre 0 e 5.\n");
                pausar();
                break;
        }
 
    } while(opcao != 0);
}