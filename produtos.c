/*
|=============================================================|
|                      MODULO PRODUTOS                        |
| CRUD para a gestão de produtos do sistema SIG-MASSAGE        |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"
#include "utils.h"

void menuProdutos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                MODULO PRODUTOS               ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Produto                         ║\n");
    printf("║ 2. Listar Produtos                           ║\n");
    printf("║ 3. Procurar Produto                          ║\n");
    printf("║ 4. Atualizar Dados do Produto                ║\n");
    printf("║ 5. Excluir Produto                           ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

void cadastroProduto() {
    char nome[70];
    char codigo[20];
    float preco;
    int estoque;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              CADASTRAR PRODUTO               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do produto: ");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o código do produto: ");
    if (scanf(" %19s", codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o preço do produto: ");
    if (scanf("%f", &preco) != 1) {
        printf("\n Erro: Preço inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite a quantidade em estoque: ");
    if (scanf("%d", &estoque) != 1) {
        printf("\n Erro: Estoque inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Produto %s cadastrado com sucesso!\n", nome);
    pausar();
}
