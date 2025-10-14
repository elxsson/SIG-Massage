#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    char nome[70];
    char codigo[20];
    float preco;
    int estoque;
    int status;
} Produtos;

void produtos();
void menuProdutos();
void cadastrarProduto();
void listarProdutos();
void buscarProduto();
void atualizarProduto();
void deletarProduto();

int salvarProduto(Produto *p);
int carregarProdutos(Produto **produtos, int *quantidade);
int atualizarArquivoProdutos(Produto *produtos, int quantidade);

#endif