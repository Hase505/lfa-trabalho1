#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

#include "../include/afd.h"
#include "../include/gr.h"

using namespace std;

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