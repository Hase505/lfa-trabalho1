#include "../include/afd.h"
#include "../include/gr.h"

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>

Afd::Afd(const std::string& nomeArquivo) {
    if (!lerDeArquivo(nomeArquivo)) {
        throw std::ios_base::failure("Erro ao abrir o arquivo \"" + nomeArquivo + "\"");
    }
}

void Afd::imprimirPasso(const std::string& estado, const std::string& palavra) const {
    std::cout << '[' << estado << ']' << palavra << "\n";
}

void Afd::imprimirResultado(bool resultado) const {
    std::cout << (resultado ? "ACEITA" : "REJEITA") << '\n';
}

void Afd::processarPalavra(const std::string& palavra) const {
    std::string estadoAtual = this->estadoInicial;

    // Caso especial: palavra vazia
    if (palavra.empty()) {
        imprimirPasso(estadoAtual, "@");
        imprimirResultado(estadosFinais.count(estadoAtual) > 0);
        return;
    }

    for (size_t i = 0; i < palavra.length(); i++) {
        imprimirPasso(estadoAtual, palavra.substr(i));

        // Verifica se há uma transição válida, dado o estado e o símbolo atuais
        auto chave = std::make_pair(estadoAtual, palavra[i]);
        if (transicoes.find(chave) == transicoes.end()) {
            imprimirResultado(false);
            return;
        }
        estadoAtual = transicoes.at(chave);
    }

    imprimirPasso(estadoAtual, "");
    imprimirResultado(estadosFinais.count(estadoAtual) > 0);
}

bool Afd::lerDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        return false;
    }

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

    return true;
}

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

std::string Afd::getAlfabeto() const {
    return alfabeto;
}

std::set<std::string> Afd::getEstados() const {
    return estados;
}

std::string Afd::getEstadoInicial() const {
    return estadoInicial;
}

std::set<std::string> Afd::getEstadosFinais() const {
    return estadosFinais;
}

std::map<std::pair<std::string, char>, std::string> Afd::getTransicoes() const {
    return transicoes;
}

void Afd::setAlfabeto(const std::string& alfabeto) {
    this->alfabeto = alfabeto;
}

void Afd::setEstados(const std::set<std::string>& estados) {
    this->estados = estados;
}

void Afd::setEstadoInicial(const std::string& estadoInicial) {
    this->estadoInicial = estadoInicial;
}

void Afd::setEstadosFinais(const std::set<std::string>& estadosFinais) {
    this->estadosFinais = estadosFinais;
}

void Afd::setTransicoes(const std::map<std::pair<std::string, char>, std::string>& transicoes) {
    this->transicoes = transicoes;
}
