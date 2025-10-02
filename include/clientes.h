#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
} Cliente;

void clientes();
void menuClientes();
void cadastrarCliente();
void listarClientes();
void buscarCliente();
void atualizarCliente();
void deletarCliente();

#endif
