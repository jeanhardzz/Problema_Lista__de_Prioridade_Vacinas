#include "headers/sistema_prioridade.h"

Sistema_Prioridade::Sistema_Prioridade(){

}

void Sistema_Prioridade::Leitura(){
    std::string linha;
    std::stringstream s1;              
    std::stringstream s2; 

    getline(std::cin, linha); 
    s1 << linha;
    s1 >> n_postos;

    for(int i=0;i<n_postos;i++){
        int c,x,y;
        std::stringstream ss;

        getline(std::cin, linha);
        ss << linha;
        ss >> c;
        ss >> x;
        ss >> y;

        Posto p(c,x,y);

        postos[i]=p;
    }
    
    getline(std::cin, linha); 
    s2 << linha;
    s2 >> n_pessoas;

    for(int i=0;i<n_pessoas;i++){
        int id,x,y;
        std::stringstream ss;

        getline(std::cin, linha);
        ss << linha;
        ss>>id;
        ss>>x;
        ss>>y;

        Pessoa p(id,x,y);

        pessoas[i]=p;
    }
    
}

void Sistema_Prioridade::Imprimir(){
    printf("\tPostos\n");        
    for(auto &item : this->postos){
        std::cout <<"Posto "<< item.first << " : "<<item.second.GetCapacidade()<<" "<<item.second.GetX()<<" "<<item.second.GetY()<<std::endl;        
    }

    printf("\tPessoas \n");        
    for(auto &item : this->pessoas){
        std::cout <<"Pessoa "<< item.first << " : "<<item.second.GetIdade()<<" "<<item.second.GetX()<<" "<<item.second.GetY()<<std::endl;        
    }
}