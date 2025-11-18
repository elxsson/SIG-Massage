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
    printf("║ 6. Filtrar Clientes por Letra                ║\n");
    printf("║ 7. Filtrar Produtos por Faixa de Preço       ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

// Funções de listagem
void listarClientesGeral() {
    FILE *fp;
    Cliente *cliente;
    int count = 0;

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

    printf("====================================================================================\n");
    printf("Nome                     CPF              Telefone       Email\n");
    printf("====================================================================================\n");

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 1) {
            printf("%-24s %-16s %-14s %s\n",
                   cliente->nome,
                   cliente->cpf,
                   cliente->telefone,
                   cliente->email);
            count++;
        }
    }

    printf("====================================================================================\n");
    printf("Total: %d clientes ativos\n", count);

    fclose(fp);
    free(cliente);
    pausar();
}

void listarMassoterapeutasGeral() {
    FILE *fp;
    Massoterapeutas *massoterapeuta;
    int count = 0;

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

    printf("========================================================================================================\n");
    printf("Nome                     CPF              Telefone       Email                  CREFITO\n");
    printf("========================================================================================================\n");

    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1) {
            printf("%-24s %-16s %-14s %-22s %s\n",
                   massoterapeuta->nome,
                   massoterapeuta->cpf,
                   massoterapeuta->telefone,
                   massoterapeuta->email,
                   massoterapeuta->crefito);
            count++;
        }
    }
    
    printf("========================================================================================================\n");
    printf("Total: %d massoterapeutas ativos\n", count);

    fclose(fp);
    free(massoterapeuta);
    pausar();
}
void listarProdutosGeral() {
    FILE *fp;
    Produto *produto;
    int count = 0;

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

    printf("==========================================================================\n");
    printf("Nome                     Código       Preço       Estoque\n");
    printf("==========================================================================\n");

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto->status == 1) {
            printf("%-24s %-12s R$ %-9.2f %d\n",
                   produto->nome,
                   produto->codigo,
                   produto->preco,
                   produto->estoque);
            count++;
        }
    }
    
    printf("==========================================================================\n");
    printf("Total: %d produtos ativos\n", count);

    fclose(fp);
    free(produto);
    pausar();
}

void listarFinanceiroGeral() {
    FILE *fp;
    Movimentacao *mov;
    int count = 0;
    float saldo = 0;

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

    printf("================================================================================\n");
    printf("Tipo         Valor        Descrição\n");
    printf("================================================================================\n");

    while (fread(mov, sizeof(Movimentacao), 1, fp)) {
        if (mov->status == 1) {
            char *tipo = mov->tipo == 'E' ? "ENTRADA" : "SAÍDA";
            char sinal = mov->tipo == 'E' ? '+' : '-';
            
            printf("%-12s %cR$ %-9.2f %s\n",
                   tipo,
                   sinal,
                   mov->valor,
                   mov->descricao);
            count++;
            
            if (mov->tipo == 'E') {
                saldo += mov->valor;
            } else {
                saldo -= mov->valor;
            }
        }
    }
    
    printf("================================================================================\n");
    printf("Total: %d movimentações | Saldo: R$ %.2f\n", count, saldo);

    fclose(fp);
    free(mov);
    pausar();
}

// Funções de Filtragem

void filtrarClientesPorLetra() {
    FILE *fp;
    Cliente *cliente;
    int count = 0;
    char letra;

    cliente = (Cliente*)malloc(sizeof(Cliente));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║        FILTRAR CLIENTES POR LETRA INICIAL    ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite a letra inicial para filtrar: ");
    scanf(" %c", &letra);
    limparBuffer();

    fp = fopen(ARQUIVO_CLIENTES, "rb");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado ainda.\n");
        free(cliente);
        pausar();
        return;
    }

    printf("\n====================================================================================\n");
    printf("Clientes que começam com '%c'\n", letra);
    printf("====================================================================================\n");
    printf("Nome                     CPF              Telefone       Email\n");
    printf("====================================================================================\n");

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 1 && cliente->nome[0] == letra) {
            printf("%-24s %-16s %-14s %s\n",
                   cliente->nome,
                   cliente->cpf,
                   cliente->telefone,
                   cliente->email);
            count++;
        }
    }

    printf("====================================================================================\n");
    
    if (count == 0) {
        printf("Nenhum cliente encontrado com a letra '%c'.\n", letra);
    } else {
        printf("Total: %d cliente(s) com a letra '%c'\n", count, letra);
    }

    fclose(fp);
    free(cliente);
    pausar();
}

void filtrarProdutosPorPreco() {
    FILE *fp;
    Produto *produto;
    int count = 0;
    float precoMin, precoMax;

    produto = (Produto*)malloc(sizeof(Produto));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║         FILTRAR PRODUTOS POR PREÇO          ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o preço mínimo: R$ ");
    scanf("%f", &precoMin);
    printf("Digite o preço máximo: R$ ");
    scanf("%f", &precoMax);
    limparBuffer();

    if (precoMin < 0 || precoMax < 0) {
        printf("Erro: Preços não podem ser negativos!\n");
        free(produto);
        pausar();
        return;
    }

    if (precoMin > precoMax) {
        printf("Erro: Preço mínimo não pode ser maior que preço máximo!\n");
        free(produto);
        pausar();
        return;
    }

    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        free(produto);
        pausar();
        return;
    }

    printf("\n==========================================================================\n");
    printf("Produtos entre R$ %.2f e R$ %.2f\n", precoMin, precoMax);
    printf("==========================================================================\n");
    printf("Nome                     Código       Preço       Estoque\n");
    printf("==========================================================================\n");

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto->status == 1 && 
            produto->preco >= precoMin && 
            produto->preco <= precoMax) {
            printf("%-24s %-12s R$ %-9.2f %d\n",
                   produto->nome,
                   produto->codigo,
                   produto->preco,
                   produto->estoque);
            count++;
        }
    }

    printf("==========================================================================\n");
    
    if (count == 0) {
        printf("Nenhum produto encontrado na faixa de R$ %.2f a R$ %.2f.\n", precoMin, precoMax);
    } else {
        printf("Total: %d produto(s) na faixa de preço\n", count);
    }

    fclose(fp);
    free(produto);
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
            case 6:
                filtrarClientesPorLetra();
                break;
            case 7:
                filtrarProdutosPorPreco();
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