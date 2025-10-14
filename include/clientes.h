#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
    int status; // 1 = ativo, 0 = inativo
} Cliente;

void clientes();
void menuClientes();
void cadastrarCliente();
void listarClientes();
void buscarCliente();
void atualizarCliente();
void deletarCliente();

// funcoes auxiliares
int salvarCliente(Cliente *c);
int carregarClientes(Cliente **clientes, int *quantidade);
int atualizarArquivoClientes(Cliente *clientes, int quantidade);

#endif
