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

void listarProdutos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               LISTAR PRODUTOS                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Nenhum produto cadastrado ainda.\n");
    printf("Para cadastrar um produto, escolha a opção 1 no menu.\n");
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
