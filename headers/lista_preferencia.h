#ifndef LISTA_PREF
#define LISTA_PREF

#include <iostream>
#include <map>
#include <vector>
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
        void ReiniciaProposta(TipoChave elemento);
        int GetTotal();
        ListaPreferencia Rank();
        ListaEncadeada GetLista(TipoChave key);
        std::vector<int> GetListaVector(TipoChave key); //Retorna lista de item antes de uma dada apos
        TipoChave PegaItemNaLista(TipoChave key, TipoChave pos);
        
        
};

#endif