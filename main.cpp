/**
 * @file main.cpp
 * @brief Arquivo principal do programa para manipulação de AFD e GR.
 *
 * Solicita ao usuário o nome do arquivo contendo a definição do AFD,
 * carrega o autômato, converte para gramática regular e executa o menu de interação.
 */

#include "include/menu.h"

#include <iostream>

/**
 * @brief Função principal do programa.
 * @return 0 se executado com sucesso, 1 em caso de erro.
 */
int main() {
    std::string nomeArquivo;

    std::cout << "Informe o nome do arquivo contendo definicao do AFD:\n";
    std::getline(std::cin, nomeArquivo);
    try {
        Afd afd(nomeArquivo);
        Gr gr = afd.converterParaGR();
        Menu menu(afd, gr);
        menu.executar();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar AFD: " << e.what() << '\n';
        return 1;
    }

    return 0;
}