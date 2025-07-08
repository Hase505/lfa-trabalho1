#ifndef GR_H
#define GR_H

#include <map>
#include <set>
#include <string>
#include <vector>

class GR {
   private:
    std::set<std::string> naoTerminais;
    std::string terminais;
    char simboloInicial;
    std::map<std::string, std::vector<std::string>> producoes;

   public:
    GR();

    std::set<std::string> getNaoTerminais() const;
    std::string getTerminais() const;
    char getSimboloInicial() const;
    std::map<std::string, std::vector<std::string>> getProducoes() const;

    void setNaoTerminais(const std::set<std::string>& novosNaoTerminais);
    void setTerminais(const std::string& novosTerminais);
    void setSimboloInicial(char novoSimboloInicial);
    void setProducoes(const std::map<std::string, std::vector<std::string>>& novasProducoes);

    void imprimirGramatica() const;
};

#endif  // GR_H
