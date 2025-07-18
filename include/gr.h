#ifndef GR_H
#define GR_H

#include <map>
#include <set>
#include <string>

/**
 * @brief Classe que representa uma Gramática Regular (GR).
 */
class Gr {
   private:
    /**
     * @brief Conjunto de não-terminais da gramática.
     */
    std::set<std::string> naoTerminais;

    /**
     * @brief Conjunto de terminais da gramática.
     */
    std::string terminais;

    /**
     * @brief Símbolo inicial da gramática.
     */
    std::string simboloInicial;

    /**
     * @brief Produções da gramática.
     */
    std::map<std::string, std::set<std::string>> producoes;

   public:
    /**
     * @brief Construtor padrão.
     */
    Gr() = default;

    /**
     * @brief Retorna o conjunto de não-terminais.
     * @return Conjunto de não-terminais.
     */
    std::set<std::string> getNaoTerminais() const;

    /**
     * @brief Retorna o conjunto de terminais.
     * @return Terminais como string.
     */
    std::string getTerminais() const;

    /**
     * @brief Retorna o símbolo inicial da gramática.
     * @return Símbolo inicial.
     */
    std::string getSimboloInicial() const;

    /**
     * @brief Retorna as produções da gramática.
     * @return Mapa de produções.
     */
    std::map<std::string, std::set<std::string>> getProducoes() const;

    /**
     * @brief Define o conjunto de não-terminais.
     * @param naoTerminais Conjunto de não-terminais.
     */
    void setNaoTerminais(const std::set<std::string>& naoTerminais);

    /**
     * @brief Define o conjunto de terminais.
     * @param terminais Terminais como string.
     */
    void setTerminais(const std::string& terminais);

    /**
     * @brief Define o símbolo inicial da gramática.
     * @param simboloInicial Símbolo inicial.
     */
    void setSimboloInicial(const std::string& simboloInicial);

    /**
     * @brief Define as produções da gramática.
     * @param producoes Mapa de produções.
     */
    void setProducoes(const std::map<std::string, std::set<std::string>>& producoes);

    /**
     * @brief Imprime a gramática regular no formato padrão.
     */
    void imprimirGR() const;
};

#endif  // GR_H
