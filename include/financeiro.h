#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct {
    char tipo;          // 'E' = entrada, 'S' = saida
    float valor;
    char descricao[100];
    char cpf[20];       // CPF do massoterapeuta (saida)
    int status;
} Movimentacao;

void financeiro();
void menuFinanceiro();
void registrarEntrada();
void registrarSaida();
void listarFinanceiro();

int salvarMovimentacao(Movimentacao *m);
int carregarMovimentacoes(Movimentacao **movimentacoes, int *quantidade);
int atualizarArquivoMovimentacoes(Movimentacao *movimentacoes, int quantidade);

#endif