#include "../include/gr.h"
#include "../include/afd.h"


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