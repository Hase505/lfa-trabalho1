#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

#include "../include/afd.h"
#include "../include/gr.h"

using namespace std;

void GR::imprimir() const {
    cout << "Não Terminais: ";
    for (const auto& nt : naoTerminais) {
        cout << nt << " ";
    }
    cout << endl;

    cout << "Terminais: ";
    for (char t : terminais) {
        cout << t << " ";
    }
    cout << endl;

    cout << "Símbolo Inicial: " << simboloInicial << endl;

    cout << "Produções:" << endl;
    for (const auto& par : producoes) {
        const string& naoTerminal = par.first;
        const vector<string>& regras = par.second;

        cout << naoTerminal << " -> ";
        for (size_t i = 0; i < regras.size(); ++i) {
            cout << regras[i];
            if (i != regras.size() - 1) {
                cout << " | ";
            }
        }
        cout << endl;
    }
}
