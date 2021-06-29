#ifndef LISTA_PREF
#define LISTA_PREF

#include <iostream>
#include <map>
#include "../Lista_encadeada/lista-encadeada.h"


class ListaPreferencia{
    private:
        std::map<TipoChave, ListaEncadeada> g;
        int total;

    public:
        ListaPreferencia();
        void AdicionaPreferencia(TipoChave original,TipoChave pref);                               
        void Imprime(); 
        void ImprimeProposta(TipoChave elemento);       
        void AndaProposta(TipoChave elemento);
        TipoChave PegaProxProposta(TipoChave elemento);
        int GetTotal();
        ListaPreferencia Rank();
        ListaEncadeada GetLista(TipoChave key);
        TipoChave PegaItemNaLista(TipoChave key, TipoChave pos);
        
        
};

#endif