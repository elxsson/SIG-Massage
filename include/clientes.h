#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
    int status;
} Cliente;

typedef struct noCliente NoCliente;

struct noCliente{
    Cliente dados;
    NoCliente* prox;
};

void clientes();
void menuClientes();
void cadastrarCliente();
void listarClientes();
void buscarCliente();
void atualizarCliente();
void deletarCliente();
int salvarCliente(Cliente *c);
int carregarClientes(Cliente **clientes, int *quantidade);
int atualizarArquivoClientes(Cliente *clientes, int quantidade);

#endif
