#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "clientes.h"
#include "massoterapeutas.h"
#include "produtos.h"
#include "financeiro.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "clientes.dat"
#define MASSOTERAPEUTAS_FILE "massoterapeutas.dat"
#define ARQUIVO_PRODUTOS "produtos.dat"
#define ARQUIVO_FINANCEIRO "financeiro.dat"

void menuRelatorios() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                MODULO RELATORIOS             ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Listar Clientes                           ║\n");
    printf("║ 2. Listar Massoterapeutas                    ║\n");
    printf("║ 3. Listar Produto                            ║\n");
    printf("║ 4. Listar Agendamentos                       ║\n");
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
void listarProdutosGeral() {
    FILE *fp;
    Produto *produto;

    produto = (Produto*)malloc(sizeof(Produto));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               LISTAR PRODUTOS                ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        free(produto);
        pausar();
        return;
    }

    while (fread(produto, sizeof(Produto), 1, fp)) {
            printf("──────────────────────────────────────────────\n");
            printf("Nome: %s\n", produto->nome);
            printf("Código: %s\n", produto->codigo);
            printf("Preço: R$ %.2f\n", produto->preco);
            printf("Estoque: %d\n", produto->estoque);
            printf("Status: %d\n", produto->status);
    }
    printf("──────────────────────────────────────────────\n");

    fclose(fp);
    free(produto);
    pausar();
}
void listarFinanceiroGeral() {
    FILE *fp;
    Movimentacao *mov;

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

    while (fread(mov, sizeof(Movimentacao), 1, fp)) {
        printf("──────────────────────────────────────────────\n");
        printf("Tipo: %s\n", mov->tipo == 'E' ? "ENTRADA" : "SAÍDA");
        printf("Valor: R$ %.2f\n", mov->valor);
        printf("Descrição: %s\n", mov->descricao);
        printf("Status: %d\n", mov->status);
    }
    printf("──────────────────────────────────────────────\n");

    fclose(fp);
    free(mov);
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
                listarProdutosGeral();
                break;
            case 4: 
                //listarAgendamentosGeral(); 
                break;
            case 5: 
                listarFinanceiroGeral(); 
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