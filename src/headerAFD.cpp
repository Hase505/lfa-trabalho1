#ifndef AFD_H
#define AFD_H

#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

/*
    Classe AFD
    Representa um Autômato Finito Determinístico.
    - Lê especificação de arquivo
    - Simula processamento de palavras
    - Converte para Gramática Regular equivalente
*/
class AFD {
private:
    // Alfabeto de entrada, armazenado como string
    // Exemplo: "abc012"
    string alfabeto;

    // Conjunto de estados (ex: q0, q1, q2)
    set<string> estados;

    // Estado inicial (em geral "q0")
    string estadoInicial;

    // Conjunto de estados finais
    set<string> estadosFinais;

    // Função de transições: (estado origem, símbolo) -> estado destino
    map<pair<string, char>, string> transicoes;

protected:
    // Nenhum atributo protected por enquanto

public:
    // Construtor
    AFD();

    /*
        Getters: acesso seguro aos dados privados
    */
    string getAlfabeto() const;
    set<string> getEstados() const;
    string getEstadoInicial() const;
    set<string> getEstadosFinais() const;
    map<pair<string, char>, string> getTransicoes() const;

    /*
        Setters: permitir alteração só onde fizer sentido
        OBS: para atributos carregados do arquivo, geralmente não é necessário setter.
        Incluo aqui apenas para consistência, mas vocês podem omitir setters não usados.
    */
    void setAlfabeto(const string& novoAlfabeto);
    void setEstados(const set<string>& novosEstados);
    void setEstadoInicial(const string& novoEstadoInicial);
    void setTransicoes(const map<pair<string, char>, string>& novasTransicoes);

    /*
        Método para carregar especificação do AFD de um arquivo texto
        Exemplo de formato:
            alfabeto={a,b,c,0,1,2}
            estados={q0,q1,q2}
            finais={q2}
            (q0,a)=q1
    */
    bool carregarDeArquivo(const string& nomeArquivo);

    /*
        Simula o processamento de uma palavra:
        - Verifica se é aceita ou rejeitada
        - Retorna true (aceita) ou false (rejeita)
    */
    bool processarPalavra(const string& palavra);

    /*
        Imprime passo a passo do processamento
        Exemplo (como no enunciado):
            [q0]ab00cb
            [q1]b00cb
            ...
    */
    void imprimirPassoAPasso(const string& palavra);

    /*
        Converte este AFD em uma Gramática Regular equivalente
        Retorna um objeto da classe GR
    */
    class GR converterParaGramaticaRegular() const;
};

#endif // AFD_H
