#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "clientes.h"
#include "massoterapeutas.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "clientes.dat"
#define MASSOTERAPEUTAS_FILE "massoterapeutas.dat"

void menuRelatorios() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                MODULO RELATORIOS             ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Listar Clientes                           ║\n");
    printf("║ 2. Listar Massoterapeutas                    ║\n");
    printf("║ 3. Listar Agendamentos                       ║\n");
    printf("║ 4. Listar Produto                            ║\n");
    printf("║ 5. Listar Financeiro                         ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

// Funções de listagem
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
            printf("Status: %d\n", cliente->status);

    }
    printf("──────────────────────────────────────────────\n");

    fclose(fp);
    free(cliente);
    pausar();
}
void listarMassoterapeutasGeral() {
    FILE *fp;
    Massoterapeutas *massoterapeuta;

    massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             LISTAR MASSOTERAPEUTAS           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    fp = fopen(MASSOTERAPEUTAS_FILE, "rb");
    if (fp == NULL) {
        printf("Nenhum massoterapeuta cadastrado ainda.\n");
        free(massoterapeuta);
        pausar();
        return;
    }

    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
            printf("──────────────────────────────────────────────\n");
            printf("Nome: %s\n", massoterapeuta->nome);
            printf("CPF: %s\n", massoterapeuta->cpf);
            printf("Telefone: %s\n", massoterapeuta->telefone);
            printf("Email: %s\n", massoterapeuta->email);
            printf("CREFITO: %s\n", massoterapeuta->crefito);
            printf("Especialidade: %s\n", massoterapeuta->especialidade);
            printf("Status: %d\n", massoterapeuta->status);
    }
    printf("──────────────────────────────────────────────\n");

    fclose(fp);
    free(massoterapeuta);
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
                listarMassoterapeutasGeral();
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