#ifndef MASSOTERAPEUTA_H
#define MASSOTERAPEUTA_H

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
    char crefito[20];
    char especialidade[50];
} Massoterapeutas;

void massoterapeutas();
void menuMassoterapeutas();
void cadastrarMassoterapeuta();
void listarMassoterapeutas();
void buscarMassoterapeuta();
void atualizarMassoterapeuta();
void deletarMassoterapeuta();

#endif