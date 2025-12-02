#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

typedef struct {
    char nome[70];
    char codigo[20];
    float preco;
    int estoque;
    int status;
} Produto;

typedef struct noProduto NoProduto;

struct noProduto{
    Produto dados;
    NoProduto* prox;
};

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