#ifndef PRIORIDADE
#define PRIORIDADE

#include "posto.h"
#include "pessoa.h"
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include "lista_preferencia.h"

class Sistema_Prioridade{
    private:
        int n_postos;
        int n_pessoas;
        std::map<int,Posto> postos;
        std::map<int,Pessoa> pessoas;
        ListaPreferencia a; //lista de pref das pessoas
        std::vector<int> b; //lista de pref das postos (são iguais)
    public:
        Sistema_Prioridade();
        void Leitura();
        void Imprimir();
        float CalculaDistancia(Pessoa p1,Posto p2);
        void ConstruirPreferencias();
        std::vector<std::pair<int, float>> OrdenaInsercaoFloat(std::vector<std::pair<int, float>> v, int n);
        std::vector<std::pair<int, int>> OrdenaInsercaoInt(std::vector<std::pair<int, int>> v, int n);
};

#endif