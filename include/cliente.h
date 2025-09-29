#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
} Cliente;

void menucliente();
void cliente();
void cadastroCliente();
void listarClientes();
void buscarCliente();
void atualizarCliente();
void deletarCliente();

#endif
