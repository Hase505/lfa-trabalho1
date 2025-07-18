#ifndef AFD_H
#define AFD_H

#include <map>
#include <set>
#include <string>
#include <vector>

class Afd {
   private:
    std::string alfabeto;
    std::set<std::string> estados;
    std::string estadoInicial;
    std::set<std::string> estadosFinais;
    std::map<std::pair<std::string, char>, std::string> transicoes;

    void imprimirPasso(const std::string& estado, const std::string& palavra) const;
    void imprimirResultado(bool resultado) const;

   public:
    Afd() = default;

    std::string getAlfabeto() const;
    std::set<std::string> getEstados() const;
    std::string getEstadoInicial() const;
    std::set<std::string> getEstadosFinais() const;
    std::map<std::pair<std::string, char>, std::string> getTransicoes() const;

    void setAlfabeto(const std::string& alfabeto);
    void setEstados(const std::set<std::string>& estados);
    void setEstadoInicial(const std::string& estadoInicial);
    void setEstadosFinais(const std::set<std::string>& estadosFinais);
    void setTransicoes(const std::map<std::pair<std::string, char>, std::string>& transicoes);

    bool lerDeArquivo(const std::string& nomeArquivo);
    void processarPalavra(const std::string& palavra) const;
    class Gr converterParaGR() const;
};

#endif  // AFD_H
