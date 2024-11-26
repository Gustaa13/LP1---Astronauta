# Sistema de Gestão de Astronautas e Voos Espaciais

Este projeto é um sistema simples de gerenciamento de astronautas e voos espaciais, desenvolvido para um estudo inicial em C++ à orientação de objetos. O sistema permite, em  tempo de execução, realizar várias operações relacionadas ao cadastro e gerenciamento de astronautas e suas missões espaciais.

## Funcionalidades Principais

1. **Cadastrar Astronauta**: Permite adicionar novos astronautas ao sistema.
2. **Cadastrar Voo**: Possibilita a criação de novos voos espaciais.
3. **Adicionar Astronauta em Voo**: Insere um astronauta em um voo específico.
4. **Remover Astronauta de um Voo**: Remove um astronauta de um voo.
5. **Realizar um Voo**: Marca um voo como realizado.
6. **Explodir um Voo**: Simula a explosão de um voo.
7. **Finalizar um Voo**: Finaliza um voo que foi realizado com sucesso.
8. **Listar todos os Voos**: Exibe uma lista de todos os voos cadastrados no sistema.
9. **Listar todos os Astronautas Mortos**: Mostra uma lista de todos os astronautas que morreram em serviço.
10. **Listar todos os Astronautas**: Exibe todos os astronautas cadastrados no sistema.

## Estrutura do Projeto

- **main.cpp**: Arquivo principal que contém o menu do sistema e o loop de execução.
- **classes.cpp**: Arquivo que contém as classes e métodos do sistema.
- **funcs.cpp**: Arquivo que contém funcões secundárias para intermediação e auxílio do sistema.
- **funcs.hpp**: Arquivo de cabeçalho contendo as declarações das funções utilizadas no sistema.

## Tecnologias Utilizadas

- **Linguagem de Programação**: C++
- **Biblioteca Padrão do C++** para entrada e saída de dados.

## Como Executar

Para compilar e executar o projeto, siga os seguintes passos:

1. Abra o terminal na pasta do projeto.
2. Compile o código utilizando o comando:
   ```
   g++ main.cpp -o sistema_gestao
3. Execute o programa:
   ```
   ./sistema_gestao