/*
|=============================================================|
|                          UTILS                              |
| Funções utilitárias compartilhadas pelo sistema SIG-MASSAGE |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "clientes.h"
#include "massoterapeutas.h"
#include "agendamentos.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "clientes.dat"
#define ARQUIVO_MASSOTERAPEUTAS "massoterapeutas.dat"
#define ARQUIVO_AGENDAMENTOS "agendamentos.dat"

void pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    system("clear || cls");
}

int validarNome(char *nome) {
    if (strlen(nome) == 0) return 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') return 0;
    }
    return 1;
}

int lerNome(char *nome, int tamanho) {
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nome);
    limparBuffer();
    if (!validarNome(nome)) {
        printf(" Erro: Nome inválido! Use apenas letras e espaços.\n");
        return 0;
    }
    return 1;
}

int validarCPF(char *cpf) {
    int digitos = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) digitos++;
    }
    return (digitos == 11);
}

int lerCPF(char *cpf, int tamanho) {
    printf("Digite o CPF (11 dígitos): ");
    scanf(" %19s", cpf);
    limparBuffer();
    if (!validarCPF(cpf)) {
        printf(" Erro: CPF inválido! Deve conter 11 dígitos.\n");
        return 0;
    }
    return 1;
}

int validarTelefone(char *telefone) {
    int digitos = 0;
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (isdigit(telefone[i])) digitos++;
    }
    return (digitos >= 10 && digitos <= 11);
}

int lerTelefone(char *telefone, int tamanho) {
    printf("Digite o telefone (10 ou 11 dígitos): ");
    scanf(" %19[^\n]", telefone);
    limparBuffer();
    if (!validarTelefone(telefone)) {
        printf(" Erro: Telefone inválido! Deve ter 10 ou 11 dígitos.\n");
        return 0;
    }
    return 1;
}

int validarEmail(char *email) {
    int temArroba = 0, posArroba = -1, temPonto = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            temArroba = 1;
            posArroba = i;
            break;
        }
    }
    if (!temArroba) return 0;
    for (int i = posArroba + 1; email[i] != '\0'; i++) {
        if (email[i] == '.') {
            temPonto = 1;
            break;
        }
    }
    return temPonto;
}

int lerEmail(char *email, int tamanho) {
    printf("Digite o email: ");
    scanf(" %69[^\n]", email);
    limparBuffer();
    if (!validarEmail(email)) {
        printf(" Erro: Email inválido! Deve ter @ e ponto.\n");
        return 0;
    }
    return 1;
}

int validarValor(float valor) {
    return (valor > 0);
}

int lerValor(float *valor) {
    printf("Digite o valor (R$): ");
    if (scanf("%f", valor) != 1) {
        limparBuffer();
        printf(" Erro: Valor inválido!\n");
        return 0;
    }
    limparBuffer();
    if (!validarValor(*valor)) {
        printf(" Erro: Valor deve ser maior que zero!\n");
        return 0;
    }
    return 1;
}

int validarEstoque(int estoque) {
    return (estoque >= 0);
}

int lerEstoque(int *estoque) {
    printf("Digite a quantidade em estoque: ");
    if (scanf("%d", estoque) != 1) {
        limparBuffer();
        printf(" Erro: Valor inválido!\n");
        return 0;
    }
    limparBuffer();
    if (!validarEstoque(*estoque)) {
        printf(" Erro: Estoque não pode ser negativo!\n");
        return 0;
    }
    return 1;
}

int validarCodigo(char *codigo) {
    return (strlen(codigo) > 0);
}

int lerCodigo(char *codigo, int tamanho) {
    printf("Digite o código do produto: ");
    scanf(" %19s", codigo);
    limparBuffer();
    if (!validarCodigo(codigo)) {
        printf(" Erro: Código não pode estar vazio!\n");
        return 0;
    }
    return 1;
}

int validarCrefito(char *crefito) {
    return (strlen(crefito) >= 3);
}

int lerCrefito(char *crefito, int tamanho) {
    printf("Digite o número do CREFITO: ");
    scanf(" %19s", crefito);
    limparBuffer();
    if (!validarCrefito(crefito)) {
        printf(" Erro: CREFITO inválido! Mínimo 3 caracteres.\n");
        return 0;
    }
    return 1;
}

int validarEspecialidade(char *especialidade) {
    return (strlen(especialidade) > 0);
}

int lerEspecialidade(char *especialidade, int tamanho) {
    printf("Digite a especialidade: ");
    scanf(" %49[^\n]", especialidade);
    limparBuffer();
    if (!validarEspecialidade(especialidade)) {
        printf(" Erro: Especialidade não pode estar vazia!\n");
        return 0;
    }
    return 1;
}

int lerTipoMassagem(char *tipoMassagem, int tamanho) {
    printf("Digite a especialidade: ");
    scanf(" %49[^\n]", tipoMassagem);
    limparBuffer();
    if (!validarTipoMassagem(tipoMassagem)) {
        printf(" Erro: Tipo de massagem não pode ser vazio!\n");
        return 0;
    }
    return 1;
}

int validarTipoMassagem(char *tipoMassagem) {
    return (strlen(tipoMassagem) > 0);
}

int validarDescricao(char *descricao) {
    return (strlen(descricao) > 0);
}

int lerDescricao(char *descricao, int tamanho) {
    printf("Digite a descrição: ");
    scanf(" %99[^\n]", descricao);
    limparBuffer();
    if (!validarDescricao(descricao)) {
        printf(" Erro: Descrição não pode estar vazia!\n");
        return 0;
    }
    return 1;
}

char* atribuirData() {

    static char data[11];
    
    time_t agora;
    struct tm *info_data;
    time(&agora);
    info_data = localtime(&agora);
    strftime(data, sizeof(data), "%d/%m/%Y", info_data);
    return data;
}

int atribuirId(const char *nomeArquivo, int tamanhoRegistro) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        return 1;
    }

    // Adaptado da geração automática da IA do Google
    fseek(arquivo, 0, SEEK_END);
    long int bytes = ftell(arquivo);
    int quantidadeExistente = bytes / tamanhoRegistro;
    int novoId = quantidadeExistente + 1;
    fclose(arquivo);

    return novoId;
}

char* getNomeClientePorCPF(const char* cpf){
    FILE *fp;
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    char *nome = malloc(70);
    
    fp = fopen(ARQUIVO_CLIENTES, "rb");
    if (fp == NULL) {
        return("Nenhum cliente cadastrado.\n");
    }
    
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 1 && strcmp(cliente->cpf, cpf) == 0) {
            strcpy(nome, cliente->nome);
            break;
        }
    }
    
    fclose(fp);
    free(cliente);

    return nome;
}

char* getNomeMassoterapeutaPorCrefito(const char* crefito){
    FILE *fp;
    Massoterapeutas *massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));
    char *nome = malloc(70);
    
    fp = fopen(ARQUIVO_MASSOTERAPEUTAS, "rb");
    if (fp == NULL) {
        return("Nenhum Massoterapeuta cadastrado.\n");
    }
    
    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1 && strcmp(massoterapeuta->crefito, crefito) == 0) {
            strcpy(nome, massoterapeuta->nome);
            break;
        }
    }
    
    fclose(fp);
    free(massoterapeuta);
    
    return nome;
}

char* getTipoMassagemPorCrefito(const char* crefito){
    FILE *fp;
    Massoterapeutas *massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));
    char *tipo = malloc(50);
    
    fp = fopen(ARQUIVO_MASSOTERAPEUTAS, "rb");
    if (fp == NULL) {
        return("Nenhum Massoterapeuta cadastrado.\n");
    }
    
    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1 && strcmp(massoterapeuta->crefito, crefito) == 0) {
            strcpy(tipo, massoterapeuta->especialidade);
            break;
        }
    }
    
    fclose(fp);
    free(massoterapeuta);
    
    return tipo;
}