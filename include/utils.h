#ifndef UTILS_H
#define UTILS_H

// geral
void pausar();
void limparBuffer();
void limparTela();

// funções de leitura com validação
int lerNome(char *nome, int tamanho);
int lerCPF(char *cpf, int tamanho);
int lerTelefone(char *telefone, int tamanho);
int lerEmail(char *email, int tamanho);
int lerEstoque(int *estoque);
int lerCodigo(char *codigo, int tamanho);
int lerCrefito(char *crefito, int tamanho);
int lerEspecialidade(char *especialidade, int tamanho);
int lerDescricao(char *descricao, int tamanho);
int lerValor(float *valor);

// funções de validação
int validarNome(char *nome);
int validarCPF(char *cpf);
int validarTelefone(char *telefone);
int validarEmail(char *email);
int validarEstoque(int estoque);
int validarCodigo(char *codigo);
int validarCrefito(char *crefito);
int validarEspecialidade(char *especialidade);
int validarDescricao(char *descricao);
int validarValor(float valor);
int lerTipoMassagem(char *tipoMassagem, int tamanho);
int validarTipoMassagem(char *tipoMassagem);
char* atribuirData();
int atribuirId(const char *nomeArquivo, int tamanhoRegistro);
char* getNomeClientePorCPF(const char* cpf);
char* getNomeMassoterapeutaPorCrefito(const char* crefito);
char* getTipoMassagemPorCrefito(const char* crefito);

#endif