#include "../include/gr.h"

#include <iostream>
#include <map>
#include <set>
#include <string>

void Gr::imprimirGR() const {
    auto itS = producoes.find("S");
    if (itS != producoes.end()) {
        std::cout << "S -> ";
        const std::set<std::string>& regrasS = itS->second;

        auto it = regrasS.begin();
        while (it != regrasS.end()) {
            std::cout << *it;
            ++it;
            if (it != regrasS.end()) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
    }

    for (const auto& par : producoes) {
        const std::string& naoTerminal = par.first;
        if (naoTerminal == "S") continue;

        const std::set<std::string>& regras = par.second;
        std::cout << naoTerminal << " -> ";

        auto it = regras.begin();
        while (it != regras.end()) {
            std::cout << *it;
            ++it;
            if (it != regras.end()) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
    }
}

std::set<std::string> Gr::getNaoTerminais() const {
    return naoTerminais;
}

std::string Gr::getTerminais() const {
    return terminais;
}

std::string Gr::getSimboloInicial() const {
    return simboloInicial;
}

std::map<std::string, std::set<std::string>> Gr::getProducoes() const {
    return producoes;
}

void Gr::setNaoTerminais(const std::set<std::string>& naoTerminais) {
    this->naoTerminais = naoTerminais;
}

void Gr::setTerminais(const std::string& terminais) {
    this->terminais = terminais;
}

void Gr::setSimboloInicial(const std::string& simboloInicial) {
    this->simboloInicial = simboloInicial;
}

void Gr::setProducoes(const std::map<std::string, std::set<std::string>>& producoes) {
    this->producoes = producoes;
}