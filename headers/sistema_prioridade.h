#ifndef PRIORIDADE
#define PRIORIDADE

#include "posto.h"
#include "pessoa.h"
#include <map>
#include <iostream>
#include <sstream>

class Sistema_Prioridade{
    private:
        int n_postos;
        int n_pessoas;
        std::map<int,Posto> postos;
        std::map<int,Pessoa> pessoas;
    public:
        Sistema_Prioridade();
        void Leitura();
        void Imprimir();
};

#endif