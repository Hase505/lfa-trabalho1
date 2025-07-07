#include <algorithm>
#include <iostream>   
#include <fstream>   
#include <sstream>   
#include <string>     
#include <set>        
#include <map>        
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


// metodo para ler um automato finito deterministico de um arquivo texto
void Afd::lerDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    std::string linha;
    int linhaAtual = 0;

    while (std::getline(arquivo, linha)) {
        linhaAtual++;

        if (linhaAtual == 1) {
            auto inicio = linha.find('{') + 1;
            auto fim = linha.find('}');
            std::string conteudo = linha.substr(inicio, fim - inicio);

            for (char c : conteudo) {
                if (c != ',') {
                    alfabeto += c;
                }
            }
        }

        else if (linhaAtual == 2) {
            auto inicio = linha.find('{') + 1;
            auto fim = linha.find('}');
            std::string conteudo = linha.substr(inicio, fim - inicio);

            std::stringstream ss(conteudo);
            std::string estado;
            while (std::getline(ss, estado, ',')) {
                estados.insert(estado);
            }
        }

        else if (linhaAtual == 3) {
            auto inicio = linha.find('{') + 1;
            auto fim = linha.find('}');
            std::string conteudo = linha.substr(inicio, fim - inicio);
            std::stringstream ss(conteudo);
            std::string estado;
            while (std::getline(ss, estado, ',')) {
                estadosFinais.insert(estado);
            }
        }

        else {
            auto pos1 = linha.find('(');
            auto pos2 = linha.find(',');
            auto pos3 = linha.find(')');
            auto pos4 = linha.find('=') + 1;
            std::string origem = linha.substr(pos1 + 1, pos2 - pos1 - 1);
            char simbolo = linha[pos2 + 1];
            std::string destino = linha.substr(pos4 + 1);
            while (destino[0] == ' ') destino.erase(0, 1); 
            transicoes[{origem, simbolo}] = destino;
        }
    }
    estadoInicial = "q0"; 
}
