#include <iostream>
#include <map>
#include <set>
#include <string>

#include "../include/afd.h"
#include "../include/gr.h"

Gr Afd::converterParaGR() const {
    Gr gramatica;

    std::map<std::string, std::string> estadoParaNaoTerminal;
    std::set<std::string> naoTerminais;
    char letra = 'A';

    for (const auto& estado : estados) {
        if (estado == estadoInicial) {
            estadoParaNaoTerminal[estado] = "S";
        } else {
            if (letra == 'S') letra++;
            estadoParaNaoTerminal[estado] = std::string(1, letra++);
        }
        naoTerminais.insert(estadoParaNaoTerminal[estado]);
    }

    gramatica.setNaoTerminais(naoTerminais);
    gramatica.setTerminais(alfabeto);
    gramatica.setSimboloInicial(std::string(1, 'S'));

    std::map<std::string, std::set<std::string>> producoes;

    for (const auto& transicao : transicoes) {
        std::string origem = estadoParaNaoTerminal[transicao.first.first];
        char simbolo = transicao.first.second;
        std::string destino = estadoParaNaoTerminal[transicao.second];
        producoes[origem].insert(std::string(1, simbolo) + destino);
    }

    for (const auto& estadoFinal : estadosFinais) {
        std::string naoTerminal = estadoParaNaoTerminal[estadoFinal];
        producoes[naoTerminal].insert("@");
    }

    gramatica.setProducoes(producoes);
    return gramatica;
}

void Gr::imprimirGR() const {
    for (const std::string& nt : naoTerminais) {
        std::cout << nt << " ";
    }

    for (char t : terminais) {
        std::cout << t << " ";
    }

    for (const std::pair<const std::string, std::set<std::string>>& par : producoes) {
        const std::string& naoTerminal = par.first;
        const std::set<std::string>& regras = par.second;

        std::set<std::string>::const_iterator it = regras.begin();
        while (it != regras.end()) {
            std::cout << *it;
            ++it;
            if (it != regras.end()) {
                std::cout << " | ";
            }
        }
    }
}