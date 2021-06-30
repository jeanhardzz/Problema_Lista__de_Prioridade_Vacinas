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
#include "../Lista_encadeada/lista-encadeada.h"

class Sistema_Prioridade{
    private:
        int n_postos;
        int n_pessoas;
        std::map<int,Posto> postos;
        std::map<int,Pessoa> pessoas;
        ListaPreferencia a; //lista de pref das pessoas
        std::vector<int> b; //lista de pref das postos (são iguais)
        std::map<int,std::vector<int>> visitei; //coloco uma pessoa e recebo a lista de postos visitados
        std::map<int,int> m_posto; //Coloco a pessoa e tenho o posto ou -1
        std::map<int,std::vector<int>> m_pessoa; //Coloco o posto e tenho a lista de pessoas 
        
    public:
        Sistema_Prioridade();
        void Leitura();
        void Imprimir();
        float CalculaDistancia(Pessoa p1,Posto p2);
        void ConstruirPreferencias();
        std::vector<std::pair<int, float>> OrdenaInsercaoFloat(std::vector<std::pair<int, float>> v, int n);
        std::vector<std::pair<int, int>> OrdenaInsercaoInt(std::vector<std::pair<int, int>> v, int n);
        std::vector<int> OrdenaVector(std::vector<int> v, int n);        
        int Teste();
        int TesteRank(int pessoa, std::vector<int> l_pessoa,int rank[],int *p_i, int *p2);
        void Matching();
};

#endif