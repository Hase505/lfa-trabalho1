#include "../include/menu.h"

#include <cstdlib>
#include <iostream>
#include <limits>

Menu::Menu(const Afd& afd, const Gr& gr) {
    this->afd = afd;
    this->gr = gr;
}

void Menu::executar() {
    limparTela();

    int opcao = -1;
    do {
        limparTela();
        mostrarMenu();
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                testarPalavra();
                break;
            case 2:
                gr.imprimirGR();
                pausar();
                break;
            case 0:
                std::cout << "Encerrando o programa...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                pausar();
                break;
        }
    } while (opcao != 0);
}

void Menu::mostrarMenu() const {
    std::cout << "-----------------------------\n";
    std::cout << "|            MENU           |\n";
    std::cout << "-----------------------------\n";
    std::cout << "| 1 - Testar palavra        |\n";
    std::cout << "| 2 - Exibir GR equivalente |\n";
    std::cout << "| 0 - Sair                  |\n";
    std::cout << "-----------------------------\n";
    std::cout << "Escolha uma opcao: ";
}

void Menu::testarPalavra() {
    std::string palavra;
    std::cout << "Digite a palavra: ";
    std::getline(std::cin, palavra);
    afd.processarPalavra(palavra);
    pausar();
}

void Menu::limparTela() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::pausar() const {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.get();  // Espera o ENTER
}

int Menu::lerOpcao() const {
    std::string linha;
    std::getline(std::cin, linha);
    try {
        int opcao = std::stoi(linha);
        return opcao;
    } catch (...) {
        return -1;
    }
}
