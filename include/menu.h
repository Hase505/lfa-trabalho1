// menu.h
#ifndef MENU_H
#define MENU_H

#include "afd.h"
#include "gr.h"

class Menu {
   private:
    Afd afd;
    Gr gr;

   public:
    Menu(const Afd& afd, const Gr& gr);
    void executar();

   private:
    void inicializarTela();
    void finalizarTela();
    void mostrarMenu() const;
    void testarPalavra();
    int lerOpcao() const;
    void limparTela() const;
    void pausar() const;
};

#endif  // MENU_H
