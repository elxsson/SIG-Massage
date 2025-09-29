#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    char nome[70];
    char codigo[20];
    float preco;
    int estoque;
} Produtos;

void produtos();
void menuProdutos();
void cadastroProduto();
void listarProdutos();
void buscarProduto();
void atualizarProduto();
void deletarProduto();

#endif