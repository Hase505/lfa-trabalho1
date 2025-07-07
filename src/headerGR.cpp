#ifndef GR_H
#define GR_H

#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
    Classe GR (Gramática Regular)
    Representa a gramática equivalente a um AFD.
    - Guarda não-terminais, terminais, produções
    - Permite impressão no formato especificado
*/
class GR {
private:
    // Conjunto de não-terminais (ex: S, A, B, C)
    set<string> naoTerminais;

    // Terminais válidos (ex: a, b, c, 0, 1, 2)
    string terminais;

    // Símbolo inicial da gramática (ex: S)
    string simboloInicial;

    // Mapa de produções:
    // nãoTerminal -> lista de produções (ex: A -> ["aB", "bA", "@"])
    map<string, vector<string>> producoes;

protected:
    // Nenhum atributo protected por enquanto

public:
    // Construtor
    GR();

    /*
        Getters: leitura controlada dos atributos
    */
    set<string> getNaoTerminais() const;
    string getTerminais() const;
    string getSimboloInicial() const;
    map<string, vector<string>> getProducoes() const;

    /*
        Setters: opcionais
        OBS: se a gramática sempre for gerada a partir do AFD,
        não é obrigatório ter setters para tudo.
    */
    void setNaoTerminais(const set<string>& novosNaoTerminais);
    void setTerminais(const string& novosTerminais);
    void setSimboloInicial(const string& novoSimboloInicial);
    void setProducoes(const map<string, vector<string>>& novasProducoes);

    /*
        Adiciona uma produção específica para um não-terminal
        Exemplo: adicionarProducao("A", "aB");
    */
    void adicionarProducao(const string& naoTerminal, const string& producao);

    /*
        Carrega gramática regular de um arquivo texto
        (opcional, caso vocês queiram permitir)
    */
    bool carregarDeArquivo(const string& nomeArquivo);

    /*
        Imprime a gramática regular no formato solicitado
        Exemplo:
            S -> aA
            A -> bA | aB | 0C
            ...
    */
    void imprimirGramatica() const;
};

#endif // GR_H
