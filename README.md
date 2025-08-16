# SIG-Massage 🌿

**Sistema de Gestão para Serviços de Massagens Terapêuticas**

Um sistema desenvolvido em C para facilitar o gerenciamento completo de clínicas de massoterapia e bem-estar. Desenvolvido com foco na simplicidade e eficiência, o sistema oferece uma interface intuitiva para gerenciar todos os aspectos do negócio.

## Funcionalidades Principais

-  **Gestão de Clientes**: Cadastro completo e controle de histórico
-  **Cadastro de Massoterapeutas**: Gerenciamento de profissionais
-  **Controle de Serviços**: Catálogo de massagens e terapias oferecidas
-  **Sistema de Agendamentos**: Controle de horários e disponibilidade
-  **Relatórios Detalhados**: Análises e estatísticas do negócio

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
gcc -o sig_massage main.c

# Execute o sistema
./sig_massage
```

### No Windows:
```cmd
gcc -o sig_massage.exe main.c
sig_massage.exe
```

###  Interface do Sistema

O sistema apresenta uma interface em ASCII com navegação por menus:

```bash
╔══════════════════════════════════════════════════╗
║ SIG-MASSAGE - SISTEMA DE GESTÃO DE MASSAGENS     ║
╠══════════════════════════════════════════════════╣
║                                                  ║
║ ► 1. Módulo Clientes                             ║
║ ► 2. Módulo Massoterapeutas                      ║
║ ► 3. Módulo Serviços                             ║
║ ► 4. Módulo Agendamentos                         ║
║ ► 5. Módulo Relatórios                           ║
║ ► 0. Sair do Sistema                             ║
║                                                  ║
╚══════════════════════════════════════════════════╝
```

### Status do Desenvolvimento

| Módulo | Status | Descrição |
|--------|--------|-----------|
| 🏠 **Menu Principal** | ✅ Concluído | Interface de navegação |
| 👥 **Clientes** | 🚧 Em desenvolvimento | Cadastro e gestão de clientes |
| 💆 **Massoterapeutas** | 🚧 Em desenvolvimento | Gestão de profissionais |
| 🛠️ **Serviços** | 🚧 Em desenvolvimento | Catálogo de serviços |
| 📅 **Agendamentos** | 🚧 Em desenvolvimento | Sistema de marcação |
| 📊 **Relatórios** | 🚧 Em desenvolvimento | Análises e estatísticas |
