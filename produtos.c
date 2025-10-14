/*
|=============================================================|
|                      MODULO PRODUTOS                        |
| CRUD para a gestão de produtos do sistema SIG-MASSAGE        |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"
#include "utils.h"

#define ARQUIVO_PRODUTOS "produtos.dat"


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

int salvarProduto(Produto *p) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "ab");
    if (arquivo == NULL) return 0;
    
    size_t escrito = fwrite(p, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
    return (escrito == 1);
}

int carregarProdutos(Produto **produtos, int *quantidade) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo == NULL) {
        *produtos = NULL;
        *quantidade = 0;
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *quantidade = tamanho / sizeof(Produto);

    if (*quantidade == 0) {
        *produtos = NULL;
        fclose(arquivo);
        return 1;
    }

    *produtos = (Produto*)malloc((*quantidade) * sizeof(Produto));
    size_t lidos = fread(*produtos, sizeof(Produto), *quantidade, arquivo);
    fclose(arquivo);

    return (lidos == *quantidade);
}

int atualizarArquivoProdutos(Produto *produtos, int quantidade) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "wb");
    if (arquivo == NULL) return 0;
    
    size_t escritos = fwrite(produtos, sizeof(Produto), quantidade, arquivo);
    fclose(arquivo);
    return (escritos == quantidade);
}

void cadastrarProduto() {
    Produto *produto = (Produto*)malloc(sizeof(Produto));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              CADASTRAR PRODUTO               ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o nome do produto: ");
    if (scanf(" %69[^\n]", produto->nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        free(produto);
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o código do produto: ");
    if (scanf(" %19s", produto->codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        free(produto);
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o preço do produto: ");
    if (scanf("%f", &produto->preco) != 1 || produto->preco <= 0) {
        printf("\n Erro: Preço inválido!\n");
        free(produto);
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite a quantidade em estoque: ");
    if (scanf("%d", &produto->estoque) != 1 || produto->estoque < 0) {
        printf("\n Erro: Estoque inválido!\n");
        free(produto);
        limparBuffer();
        pausar();
        return;
    }

    // Converte para lowercase
    for (int i = 0; produto->nome[i]; i++) produto->nome[i] = tolower(produto->nome[i]);
    for (int i = 0; produto->codigo[i]; i++) produto->codigo[i] = tolower(produto->codigo[i]);

    produto->status = 1;

    if (salvarProduto(produto)) {
        printf("\n Produto %s cadastrado com sucesso!\n", produto->nome);
    } else {
        printf("\n Erro ao salvar produto!\n");
    }

    free(produto);
    pausar();
}

void listarProdutos() {
    FILE *fp;
    Produto *produto;
    int produtosAtivos = 0;

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
        if (produto->status == 1) {
            printf("──────────────────────────────────────────────\n");
            printf("Nome: %s\n", produto->nome);
            printf("Código: %s\n", produto->codigo);
            printf("Preço: R$ %.2f\n", produto->preco);
            printf("Estoque: %d\n", produto->estoque);
            produtosAtivos++;
        }
    }

    if (produtosAtivos == 0) {
        printf("Nenhum produto ativo encontrado.\n");
    } else {
        printf("──────────────────────────────────────────────\n");
        printf("\nTotal de produtos ativos: %d\n", produtosAtivos);
    }

    fclose(fp);
    free(produto);
    pausar();
}

void buscarProduto() {
    Produto *produtos = NULL;
    int quantidade = 0;
    char codigoBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                BUSCAR PRODUTO                ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o código do produto: ");
    scanf(" %19s", codigoBusca);
    limparBuffer();

    // converte para lowercase
    for (int i = 0; codigoBusca[i]; i++) codigoBusca[i] = tolower(codigoBusca[i]);

    carregarProdutos(&produtos, &quantidade);

    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0 && produtos[i].status == 1) {
            printf("\n Produto encontrado:\n");
            printf("──────────────────────────────────────────────\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Código: %s\n", produtos[i].codigo);
            printf("Preço: R$ %.2f\n", produtos[i].preco);
            printf("Estoque: %d\n", produtos[i].estoque);
            printf("──────────────────────────────────────────────\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n Produto não encontrado ou inativo!\n");
    }

    free(produtos);
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
