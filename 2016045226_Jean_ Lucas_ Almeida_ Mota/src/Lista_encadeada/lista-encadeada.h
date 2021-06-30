#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include "lista.h"
#include "../headers/tipoitem.h"
#include "tipocelula.h"

class ListaEncadeada : public Lista {
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        void InserePosicaoEApaga(int chave, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
        void Inverte();            
        void AndaProposta();
        void ReiniciaProposta();
        TipoItem GetProposta();
        void ImprimeProposta();
        int PesquisaPos(TipoChave c);
        int Existe(TipoChave c);
        
    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* prox_proposta;
        TipoCelula* Posiciona(int pos, bool antes);
};

#endif