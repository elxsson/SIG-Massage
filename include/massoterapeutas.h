#ifndef MASSOTERAPEUTA_H
#define MASSOTERAPEUTA_H

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
    char crefito[20];
    char especialidade[50];
    int status;
} Massoterapeutas;

typedef enum {
    Relaxante = 1,
    Terapeutica = 2,
    Esportiva = 3,
    Quiropratica = 4,
    Ayurvedica = 5
} Especialidade;

void massoterapeutas();
void menuMassoterapeutas();
void cadastrarMassoterapeuta();
void listarMassoterapeutas();
void buscarMassoterapeuta();
void atualizarMassoterapeuta();
void deletarMassoterapeuta();

int salvarMassoterapeuta(Massoterapeutas *m);
int carregarMassoterapeutas(Massoterapeutas **massoterapeutas, int *quantidade);
int atualizarArquivoMassoterapeutas(Massoterapeutas *massoterapeutas, int quantidade);

#endif