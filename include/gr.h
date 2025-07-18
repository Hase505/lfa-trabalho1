#ifndef GR_H
#define GR_H

#include <map>
#include <set>
#include <string>

class Gr {
   private:
    std::set<std::string> naoTerminais;
    std::string terminais;
    std::string simboloInicial;
    std::map<std::string, std::set<std::string>> producoes;

   public:
    Gr() = default;

    std::set<std::string> getNaoTerminais() const;
    std::string getTerminais() const;
    std::string getSimboloInicial() const;
    std::map<std::string, std::set<std::string>> getProducoes() const;

    void setNaoTerminais(const std::set<std::string>& naoTerminais);
    void setTerminais(const std::string& terminais);
    void setSimboloInicial(const std::string& simboloInicial);
    void setProducoes(const std::map<std::string, std::set<std::string>>& producoes);

    void imprimirGR() const;
};

#endif  // GR_H
