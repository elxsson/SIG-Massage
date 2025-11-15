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

    if (!lerNome(produto->nome, sizeof(produto->nome))) {
        free(produto);
        pausar();
        return;
    }

    if (!lerCodigo(produto->codigo, sizeof(produto->codigo))) {
        free(produto);
        pausar();
        return;
    }

    if (!lerValor(&produto->preco)) {
        free(produto);
        pausar();
        return;
    }

    if (!lerEstoque(&produto->estoque)) {
        free(produto);
        pausar();
        return;
    }

    produto->status = 1;

    if (salvarProduto(produto)) {
        printf("\n Produto cadastrado com sucesso!\n");
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
            produtosAtivos++;
        }
    }
    
    printf("==========================================================================\n");

    if (produtosAtivos == 0) {
        printf("Nenhum produto ativo encontrado.\n");
    } else {
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

void atualizarProduto() {
    Produto *produtos = NULL;
    int quantidade = 0;
    char codigoBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            ATUALIZAR DADOS DO PRODUTO        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o código do produto a atualizar: ");
    scanf(" %19s", codigoBusca);
    limparBuffer();

    carregarProdutos(&produtos, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0 && produtos[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Produto não encontrado ou inativo!\n");
        free(produtos);
        pausar();
        return;
    }

    printf("\n Produto encontrado. Digite os novos dados:\n\n");

    printf("Digite o nome: ");
    scanf(" %69[^\n]", produtos[indice].nome);
    limparBuffer();

    printf("Digite o preço: ");
    scanf("%f", &produtos[indice].preco);
    limparBuffer();

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produtos[indice].estoque);
    limparBuffer();

    if (atualizarArquivoProdutos(produtos, quantidade)) {
        printf("\n Produto atualizado com sucesso!\n");
    } else {
        printf("\n Erro ao atualizar produto!\n");
    }

    free(produtos);
    pausar();
}

void deletarProduto() {
    Produto *produtos = NULL;
    int quantidade = 0;
    char codigoBusca[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               EXCLUIR PRODUTO                ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o código do produto a deletar: ");
    scanf(" %19s", codigoBusca);
    limparBuffer();

    carregarProdutos(&produtos, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0 && produtos[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Produto não encontrado ou já está inativo!\n");
        free(produtos);
        pausar();
        return;
    }

    printf("\n Produto encontrado:\n");
    printf("Nome: %s\n", produtos[indice].nome);
    printf("Código: %s\n", produtos[indice].codigo);
    printf("\nTem certeza que deseja deletar? (S/N): ");
    scanf(" %c", &confirmacao);
    limparBuffer();

    if (confirmacao == 'S' || confirmacao == 's') {
        produtos[indice].status = 0;

        if (atualizarArquivoProdutos(produtos, quantidade)) {
            printf("\n Produto deletado com sucesso!\n");
        } else {
            printf("\n Erro ao deletar produto!\n");
        }
    } else {
        printf("\n Operação cancelada!\n");
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
