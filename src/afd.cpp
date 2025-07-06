#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

#include "../include/afd.h"

void Afd::processarPalavra(const std::string& palavra) const {
    std::string estadoAtual = this->estadoInicial;

    for (int i = 0; i <= palavra.length(); i++) {
        // Se for símbolo vazio, subpalavra armazena "@"
        std::string subpalavra = (i < palavra.length()) ? palavra.substr(i) : "@";

        // Imprime o estado atual e o restante da palavra a ser processada
        std::cout << '[' << estadoAtual << ']' << subpalavra << "\n";

        if (i < palavra.length()) {
            // Verifica se há uma transição válida, dado o estado e o símbolo atuais
            auto chave = std::make_pair(estadoAtual, palavra[i]);
            if (transicoes.find(chave) == transicoes.end()) {
                std::cout << "REJEITA\n";
                break;
            }

            estadoAtual = transicoes.at(chave);
        }
    }

    // Verifica se o estado final encontrado está no conjunto de aceitação
    if (estadosFinais.count(estadoAtual) > 0)
        std::cout << "ACEITA\n";
    else
        std::cout << "REJEITA\n";
}
