#ifndef MENU_H
#define MENU_H

#include "afd.h"
#include "gr.h"

/**
 * @brief Classe responsável pelo menu de interação do programa.
 */
class Menu {
   private:
    /**
     * @brief Autômato Finito Determinístico utilizado pelo menu.
     */
    Afd afd;

    /**
     * @brief Gramática Regular utilizada pelo menu.
     */
    Gr gr;

   public:
    /**
     * @brief Construtor da classe Menu.
     * @param afd Referência para o objeto Afd.
     * @param gr Referência para o objeto Gr.
     */
    Menu(const Afd& afd, const Gr& gr);

    /**
     * @brief Executa o menu principal do programa.
     */
    void executar();

   private:
    /**
     * @brief Mostra as opções do menu na tela.
     */
    void mostrarMenu() const;

    /**
     * @brief Testa uma palavra no AFD.
     */
    void testarPalavra();

    /**
     * @brief Lê a opção escolhida pelo usuário.
     * @return A opção escolhida.
     */
    int lerOpcao() const;

    /**
     * @brief Limpa a tela do console.
     */
    void limparTela() const;

    /**
     * @brief Pausa a execução até o usuário pressionar uma tecla.
     */
    void pausar() const;
};

#endif  // MENU_H
