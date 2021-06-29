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
    std::cout<<"\tPostos\n";        
    for(auto &item : this->postos){
        std::cout <<"Posto "<< item.first << " : "<<item.second.GetCapacidade()<<" "<<item.second.GetX()<<" "<<item.second.GetY()<<std::endl;        
    }

    std::cout<<"\tPessoas \n";        
    for(auto &item : this->pessoas){
        std::cout <<"Pessoa "<< item.first << " : "<<item.second.GetIdade()<<" "<<item.second.GetX()<<" "<<item.second.GetY()<<std::endl;        
    }

    //std::cout<<"\tdistancia: "<<CalculaDistancia(pessoas[0],postos[0]);
}

float Sistema_Prioridade::CalculaDistancia(Pessoa p1,Posto p2){
    float x; 
    float y; 
    x = p1.GetX() - p2.GetX();
    y = p1.GetY() - p2.GetY();
    x = pow(x,2.0);
    y= pow(y,2.0);

    return sqrt(x+y);
}


void Sistema_Prioridade::ConstruirPreferencias(){     
    
    //Montando lista de preferencia das PESSOAS
    //Uso um vetor de pares<posto,distancia> para cada pessoa
    //ordeno as distancias, depois so adiciono na lista pref na ordem 
    for(auto &pes : this->pessoas){        
        std::vector<std::pair<int, float>> vet;
        float aux;        
        //std::cout<<"\n\tPessoa -"<<pes.first<<"\n";                  
        for(auto &post : this->postos){            
            aux = this->CalculaDistancia(pes.second,post.second);
            //std::cout<< "aux : " << aux <<std::endl;
            vet.push_back(std::make_pair(post.first,aux));            
        }
        //std::cout<<"\nVETOR - "<<pes.first<<"\n";
        vet = OrdenaInsercaoFloat(vet,n_postos);
        for(int j=0;j<n_postos;j++){                        
            //std::cout << vet[j].first <<" : "<<vet[j].second <<" ";
            a.AdicionaPreferencia(pes.first,vet[j].first);
        }
        
    }
    std::cout<<"\n\tLISTA PREF PESSOAS\n";
    a.Imprime();
    //----------------------------------------------//

    //Montando lista de preferencia dos POSTOS
    //Uso um vetor de pares<pessoa,idade> para cada posto
    //ordeno as idades, depois so adiciono na lista de pref na ordem 
           
    std::vector<std::pair<int, int>> vet_po;
                                       
    for(auto &pes : this->pessoas){                                    
        vet_po.push_back(std::make_pair(pes.first,pes.second.GetIdade()));            
    }            
    vet_po = OrdenaInsercaoInt(vet_po,n_pessoas);
    for(int j=n_pessoas-1;j>=0;j--){                                
        b.push_back(vet_po[j].first);        
    }
        
    
    std::cout<<"\n\tLISTA PREF POSTOS\n";
    for(int j=0;j<n_pessoas;j++){
        std::cout << b[j] <<" ";
    }
}

std::vector<std::pair<int, float>> Sistema_Prioridade::OrdenaInsercaoFloat(std::vector<std::pair<int, float>> v, int n){
    //PESSOAS
    int i,j;
    std::pair<int, float> aux;
   
    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (( j >= 0 ) && ( (aux.second < v[j].second) || ((aux.second == v[j].second) && ((aux.first < v[j].first))) ) ){    
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;        
    }

    return v;
}


std::vector<std::pair<int, int>> Sistema_Prioridade::OrdenaInsercaoInt(std::vector<std::pair<int, int>> v, int n){
    //POSTOS
    int i,j;
    std::pair<int, int> aux;
   
    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (( j >= 0 ) && ( (aux.second < v[j].second) || ((aux.second == v[j].second) && ((aux.first > v[j].first))) ) ){    
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;        
    }

    return v;
}