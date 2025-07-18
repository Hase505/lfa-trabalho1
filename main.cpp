#include "include/menu.h"

#include <iostream>

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