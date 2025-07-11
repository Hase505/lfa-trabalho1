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

    map<string, string> estadoParaNaoTerminal;
    set<string> naoTerminais;
    char letra = 'A';

      for (const auto& estado : estados) {
        if (estado == estadoInicial) {
            estadoParaNaoTerminal[estado] = "S"; 
        } else {
            if (letra == 'S') letra++;
            estadoParaNaoTerminal[estado] = string(1, letra++);
        }
        naoTerminais.insert(estadoParaNaoTerminal[estado]);
    }

    gramatica.setNaoTerminais(naoTerminais);
    gramatica.setTerminais(alfabeto);
    gramatica.setSimboloInicial('S');

    map<string, vector<string>> producoes;

    for (const auto& transicao : transicoes) {
        string origem = estadoParaNaoTerminal[transicao.first.first];
        char simbolo = transicao.first.second;
        string destino = estadoParaNaoTerminal[transicao.second];

        producoes[origem].push_back(string(1, simbolo) + destino);
    }

     for (const auto& estadoFinal : estadosFinais) {
        string naoTerminal = estadoParaNaoTerminal[estadoFinal];
        producoes[naoTerminal].push_back("@");
    }

    gramatica.setProducoes(producoes);
    return gramatica;
}


