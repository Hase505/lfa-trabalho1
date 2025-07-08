#ifndef GR_H
#define GR_H

#include <map>
#include <set>
#include <string>
#include <vector>

class Gr {
   private:
    std::string naoTerminais;
    std::string terminais;
    char simboloInicial;
    std::map<char, std::set<std::string>> producoes;

   public:
    Gr();

    std::string getNaoTerminais() const;
    std::string getTerminais() const;
    char getSimboloInicial() const;
    std::map<char, std::set<std::string>> getProducoes() const;

    void setNaoTerminais(const std::string& naoTerminais);
    void setTerminais(const std::string& terminais);
    void setSimboloInicial(const char simboloInicial);
    void setProducoes(const std::map<std::string, std::set<std::string>>& producoes);

    void imprimirGR() const;
};

#endif  // GR_H
