#ifndef CELULA
#define CELULA

#include "../headers/tipoitem.h"
class TipoCelula{
    public:
        TipoCelula();
    private:
        TipoItem item;
        TipoCelula *prox;
        friend class ListaEncadeada;
};

#endif