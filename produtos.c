/*
|=============================================================|
|                      MODULO PRODUTOS                        |
| CRUD para a gestão de produtos do sistema SIG-MASSAGE        |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "produtos.h"
#include "utils.h"

#define PRODUTOS_FILE "produtos.csv"


void salvarProduto(Produtos produto) {
    FILE *fp = fopen(PRODUTOS_FILE, "a");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo de produtos");
        return;
    }

    // Converte para lowercase
    for (int i = 0; produto.nome[i]; i++) produto.nome[i] = tolower((unsigned char)produto.nome[i]);
    for (int i = 0; produto.codigo[i]; i++) produto.codigo[i] = tolower((unsigned char)produto.codigo[i]);

    fprintf(fp, "%s;%s;%.2f;%d\n", produto.nome, produto.codigo, produto.preco, produto.estoque);
    fclose(fp);
}

void menuProdutos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                MODULO PRODUTOS               ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Produto                         ║\n");
    printf("║ 2. Listar Produtos                           ║\n");
    printf("║ 3. Buscar Produto                            ║\n");
    printf("║ 4. Atualizar Dados do Produto                ║\n");
    printf("║ 5. Excluir Produto                           ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

void cadastrarProduto() {
    Produtos produto;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              CADASTRAR PRODUTO               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do produto: ");
    if (scanf(" %69[^\n]", produto.nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o código do produto: ");
    if (scanf(" %19s", produto.codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o preço do produto: ");
    if (scanf("%f", &produto.preco) != 1) {
        printf("\n Erro: Preço inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite a quantidade em estoque: ");
    if (scanf("%d", &produto.estoque) != 1) {
        printf("\n Erro: Estoque inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    salvarProduto(produto);

    printf("\n Produto %s cadastrado com sucesso!\n", produto.nome);
    pausar();
}

void listarProdutos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               LISTAR PRODUTOS                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    FILE *fp = fopen(PRODUTOS_FILE, "r");
    if (fp == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        pausar();
        return;
    }

    Produtos produto;
    while (fscanf(fp, " %69[^;];%19[^;];%f;%d\n",
                  produto.nome, produto.codigo, &produto.preco, &produto.estoque) == 4) {
        printf("Nome: %s | Código: %s | Preço: R$ %.2f | Estoque: %d\n",
               produto.nome, produto.codigo, produto.preco, produto.estoque);
    }

    fclose(fp);
    pausar();
}

void buscarProduto() {
    char nome[70];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                PROCURAR PRODUTO              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o nome do produto que deseja buscar: \n");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Função de busca de produto ainda não implementada.\n");
    pausar();
}

void atualizarProduto() {
    char codigo[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          ATUALIZAR DADOS DO PRODUTO          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o código do produto que deseja atualizar: \n");
    if (scanf(" %19s", codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    printf("Função de atualização de produto ainda não implementada.\n");
    pausar();
}

void deletarProduto() {
    char codigo[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               EXCLUIR PRODUTO                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o código do produto que deseja deletar: ");
    if (scanf(" %19s", codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Tem certeza que deseja excluir? (s/N): ");
    limparBuffer();
    scanf("%c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        printf("\n Função de exclusão de produto ainda não implementada.\n");
        printf("Produto que seria excluído: %s\n", codigo);
    } else {
        printf("\n Operação cancelada pelo usuário.\n");
    }
    
    pausar();
}

void produtos() {
    int opcao;

    do {
        menuProdutos();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                cadastrarProduto(); 
                break;
            case 2: 
                listarProdutos(); 
                break;
            case 3: 
                buscarProduto(); 
                break;
            case 4: 
                atualizarProduto(); 
                break;
            case 5: 
                deletarProduto(); 
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
