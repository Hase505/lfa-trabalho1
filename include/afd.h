#ifndef AFD_H
#define AFD_H

#include <map>
#include <set>
#include <string>
#include <vector>

/**
 * @brief Classe que representa um Autômato Finito Determinístico (AFD).
 */
class Afd {
   private:
    /**
     * @brief Alfabeto do AFD.
     */
    std::string alfabeto;

    /**
     * @brief Conjunto de estados do AFD.
     */
    std::set<std::string> estados;

    /**
     * @brief Estado inicial do AFD.
     */
    std::string estadoInicial;

    /**
     * @brief Conjunto de estados finais do AFD.
     */
    std::set<std::string> estadosFinais;

    /**
     * @brief Mapa de transições do AFD.
     */
    std::map<std::pair<std::string, char>, std::string> transicoes;

    /**
     * @brief Imprime o passo atual do processamento da palavra.
     * @param estado Estado atual.
     * @param palavra Palavra restante a ser processada.
     */
    void imprimirPasso(const std::string& estado, const std::string& palavra) const;

    /**
     * @brief Imprime o resultado do processamento (aceita ou rejeita).
     * @param resultado true se aceita, false se rejeita.
     */
    void imprimirResultado(bool resultado) const;

   public:
    /**
     * @brief Construtor padrão.
     */
    Afd() = default;

    /**
     * @brief Construtor que inicializa o AFD a partir de um arquivo.
     * @param nomeArquivo Nome do arquivo de definição do AFD.
     */
    Afd(const std::string& nomeArquivo);

    /**
     * @brief Retorna o alfabeto do AFD.
     * @return Alfabeto como string.
     */
    std::string getAlfabeto() const;

    /**
     * @brief Retorna o conjunto de estados do AFD.
     * @return Conjunto de estados.
     */
    std::set<std::string> getEstados() const;

    /**
     * @brief Retorna o estado inicial do AFD.
     * @return Estado inicial.
     */
    std::string getEstadoInicial() const;

    /**
     * @brief Retorna o conjunto de estados finais do AFD.
     * @return Conjunto de estados finais.
     */
    std::set<std::string> getEstadosFinais() const;

    /**
     * @brief Retorna o mapa de transições do AFD.
     * @return Mapa de transições.
     */
    std::map<std::pair<std::string, char>, std::string> getTransicoes() const;

    /**
     * @brief Define o alfabeto do AFD.
     * @param alfabeto Alfabeto como string.
     */
    void setAlfabeto(const std::string& alfabeto);

    /**
     * @brief Define o conjunto de estados do AFD.
     * @param estados Conjunto de estados.
     */
    void setEstados(const std::set<std::string>& estados);

    /**
     * @brief Define o estado inicial do AFD.
     * @param estadoInicial Estado inicial.
     */
    void setEstadoInicial(const std::string& estadoInicial);

    /**
     * @brief Define o conjunto de estados finais do AFD.
     * @param estadosFinais Conjunto de estados finais.
     */
    void setEstadosFinais(const std::set<std::string>& estadosFinais);

    /**
     * @brief Define o mapa de transições do AFD.
     * @param transicoes Mapa de transições.
     */
    void setTransicoes(const std::map<std::pair<std::string, char>, std::string>& transicoes);

    /**
     * @brief Lê a definição do AFD de um arquivo.
     * @param nomeArquivo Nome do arquivo.
     * @return true se leitura foi bem-sucedida, false caso contrário.
     */
    bool lerDeArquivo(const std::string& nomeArquivo);

    /**
     * @brief Processa uma palavra no AFD, mostrando os passos e resultado.
     * @param palavra Palavra a ser processada.
     */
    void processarPalavra(const std::string& palavra) const;

    /**
     * @brief Converte o AFD para uma Gramática Regular (GR).
     * @return Objeto Gr correspondente.
     */
    class Gr converterParaGR() const;
};

#endif  // AFD_H
