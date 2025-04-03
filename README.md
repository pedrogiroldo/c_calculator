# c_calculator

Repositório destinado ao meu primeiro programa em C para fins acadêmicos.

## Pré-requisitos

1. **Instalar o MSYS2 (apenas para Windows)**:

   - Baixe o instalador do MSYS2 no site oficial: [https://www.msys2.org/](https://www.msys2.org/).
   - Siga as instruções de instalação fornecidas no site.

2. **Atualizar os pacotes do MSYS2 (apenas para Windows)**:

   - Abra o terminal do MSYS2 e execute os seguintes comandos:
     ```bash
     pacman -Syu
     pacman -Su
     ```

3. **Instalar as dependências necessárias**:

   - **No Windows (MSYS2)**:

     ```bash
     pacman -S mingw-w64-ucrt-x86_64-gcc
     pacman -S mingw-w64-ucrt-x86_64-gtk3
     ```

   - **No Linux/Mac**:
     - Certifique-se de ter o `gcc` e o `pkg-config` instalados.
     - Instale o GTK3 usando o gerenciador de pacotes da sua distribuição:
       - **Ubuntu/Debian**:
         ```bash
         sudo apt update
         sudo apt install build-essential libgtk-3-dev
         ```
       - **Fedora**:
         ```bash
         sudo dnf install gcc gcc-c++ gtk3-devel
         ```
       - **MacOS (Homebrew)**:
         ```bash
         brew install gtk+3
         ```

4. **Adicionar o MSYS2 ao PATH do Windows** (apenas para Windows):
   - Abra as configurações do sistema no Windows e vá até **Configurações Avançadas do Sistema**.
   - Clique em **Variáveis de Ambiente**.
   - Na seção **Variáveis do Sistema**, localize a variável `Path` e clique em **Editar**.
   - Adicione o caminho para o diretório `bin` do MSYS2 UCRT64, por exemplo:
     ```
     C:\msys64\ucrt64\bin
     ```
   - Clique em **OK** para salvar as alterações.

## Compilação e Execução

### No Windows

1. **Clonar o repositório**:

   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd c_calculator
   ```

2. **Compilar o programa**:

   - No terminal do MSYS2 ou no Prompt de Comando do Windows (com o MSYS2 configurado no PATH), execute:
     ```bash
     make
     ```

3. **Executar o programa**:

   ```bash
   ./calculadora.exe
   ```

4. **Limpar os arquivos gerados**:
   ```bash
   make clean
   ```

### No Linux/Mac

1. **Clonar o repositório**:

   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd c_calculator
   ```

2. **Compilar o programa**:

   ```bash
   make
   ```

3. **Executar o programa**:

   ```bash
   ./calculadora
   ```

4. **Limpar os arquivos gerados**:
   ```bash
   make clean
   ```

## Observações

- Certifique-se de estar no ambiente correto ao executar os comandos.
- Caso encontre problemas, verifique se todas as dependências foram instaladas corretamente.
- Adicionar o MSYS2 ao PATH permite que você use os comandos diretamente no Prompt de Comando ou no PowerShell no Windows.
