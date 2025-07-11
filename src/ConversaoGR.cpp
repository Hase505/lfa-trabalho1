#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

#include "../include/afd.h"
#include "../include/gr.h"

using namespace std;

GR AFD::converterParaGR() const {
    GR gramatica;

    gramatica.setNaoTerminais(estados);
    gramatica.setTerminais(alfabeto);

    if (!estadoInicial.empty()) {
        gramatica.setSimboloInicial(estadoInicial[0]); 
    }

    map<string, vector<string>> producoes;
    for (const auto& transicao : transicoes) {
        string origem = transicao.first.first;
        char simbolo = transicao.first.second;
        string destino = transicao.second;

        producoes[origem].push_back(string(1, simbolo) + destino);
    }

    for (const auto& estadoFinal : estadosFinais) {
        producoes[estadoFinal].push_back("@");
    }

    gramatica.setProducoes(producoes);
    return gramatica;
}

void GR::imprimirGramatica() const {
    cout << "Gramática regular equivalente:\n";
    for (const auto& par : producoes) {
        cout << par.first << " -> ";
        for (size_t i = 0; i < par.second.size(); ++i) {
            cout << par.second[i];
            if (i < par.second.size() - 1) {
                cout << " | ";
            }
        }
        cout << endl;
    }
}
