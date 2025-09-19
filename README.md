# SIG-Massage 🌿

**Sistema de Gestão para Serviços de Massagens Terapêuticas**

Um sistema desenvolvido em C para facilitar o gerenciamento completo de clínicas de massoterapia e bem-estar. Desenvolvido com foco na simplicidade e eficiência, o sistema oferece uma interface intuitiva para gerenciar todos os aspectos do negócio.

## Funcionalidades Principais

-  **Gestão de Clientes**: Cadastro completo e controle de histórico
-  **Gestão de Massoterapeutas**: Gerenciamento de profissionais
-  **Gestão de Produtos**: Cadastro de produtos e controle de estoque
-  **Sistema de Agendamentos**: Controle de horários e disponibilidade
-  **Relatórios Detalhados**: Análises e estatísticas do negócio
-  **Controle Financeiro**: Controle de entrada e saída de finanças

## Como Executar

### Pré-requisitos
- Compilador C (GCC recomendado)
- Sistema operacional compatível (Windows/Linux/macOS)

### Compilação e Execução

```bash
# Clone o repositório
git clone [url-do-repositorio]

# Navegue até o diretório
cd sig-massage

# Compile o programa
make

# Execute o sistema
./sig-massage

# Limpe os arquivos gerados na compilação (opcional):
make clean
```

##  Interface do Sistema

O sistema apresenta uma interface em ASCII com navegação por menus:

```bash
        ╔══════════════════════════════════════════════════╗
        ║ SIG-MASSAGE - SISTEMA DE GESTÃO DE MASSAGENS     ║
        ╠══════════════════════════════════════════════════╣
        ║                                                  ║
        ║ ► 1. Módulo Clientes                             ║
        ║ ► 2. Módulo Massoterapeutas                      ║
        ║ ► 3. Módulo Produtos                             ║
        ║ ► 4. Módulo Agendamentos                         ║
        ║ ► 5. Módulo Financeiro                           ║
        ║ ► 6. Módulo Relatórios                           ║
        ║ ► 7. Sobre o SIG-MASSAGE                         ║
        ║ ► 8. Equipe SIG-MASSAGE                          ║
        ║ ► 0. Sair do Sistema                             ║
        ║                                                  ║
        ╚══════════════════════════════════════════════════╝
```

## Status do Desenvolvimento

| Módulo | Status | Descrição |
|--------|--------|-----------|
| 🏠 **Menu Principal** | ✅ Concluído | Interface de navegação |
| 👥 **Clientes** | 🚧 Em desenvolvimento | Cadastro e gestão de clientes |
| 💆 **Massoterapeutas** | 🚧 Em desenvolvimento | Gestão de profissionais |
| 🛠️ **Produtos** | 🚧 Em desenvolvimento | Cadastro de produtos e controle de estoque |
| 📅 **Agendamentos** | 🚧 Em desenvolvimento | Sistema de marcação |
| 📊 **Relatórios** | 🚧 Em desenvolvimento | Análises e estatísticas |
| 💰 **Financeiro** | 🚧 Em desenvolvimento | Controle de entrada e saída |

## Próximos Passos:

- Ajustar estrutura do projeto
- Persistência em arquivos texto
- Tipos abstratos de dados
- Persistência em arquivos binários
- Exclusão lógica e física de dados
- Validação dos dados de entrada

## Desenvolvedores

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Felipe-edu34" target="_blank">
        <img src="https://github.com/Felipe-edu34.png" width="100px;" alt="Felipe Eduardo" style="border-radius:50%;"/>
      </a><br />
      <sub><b>Felipe Eduardo</b></sub>
    </td>
    <td align="center">
      <a href="https://github.com/elxsson" target="_blank">
        <img src="https://github.com/elxsson.png" width="100px;" alt="Elisson Tavares" style="border-radius:50%;"/>
      </a><br />
      <sub><b>Elisson Tavares</b></sub>
    </td>
  </tr>
</table>
