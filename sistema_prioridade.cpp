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
    /*
    std::cout<<"\tPostos\n";        
    for(auto &item : this->postos){
        std::cout <<"Posto "<< item.first << " : "<<item.second.GetCapacidade()<<" "<<item.second.GetX()<<" "<<item.second.GetY()<<std::endl;        
    }

    std::cout<<"\tPessoas \n";        
    for(auto &item : this->pessoas){
        std::cout <<"Pessoa "<< item.first << " : "<<item.second.GetIdade()<<" "<<item.second.GetX()<<" "<<item.second.GetY()<<std::endl;        
    }

    //std::cout<<"\tdistancia: "<<CalculaDistancia(pessoas[0],postos[0]);
    std::cout<<"\n\tLISTA PREF PESSOAS\n";
    a.Imprime();

    std::cout<<"\n\tLISTA PREF POSTOS\n";
    for(int j=0;j<n_pessoas;j++){
        std::cout << b[j] <<" ";
    }


    std::cout<<"\n\tMatching Pessoas\n";
    for(auto &item : this->m_posto){
        std::cout <<"Pessoa "<< item.first <<" : "<< item.second<<" Posto"<<std::endl;        
    }

    */
    
    //std::cout<<"\n\tMatching Posto\n";
    unsigned int n = 0;
    for(auto &item : this->m_pessoa){
        n++;
        std::cout << item.first <<"\n";        
        for(unsigned int i=0;i<item.second.size();i++){
            if(i!=item.second.size()-1){
                std::cout<<item.second[i]<<" ";
            }else{
                std::cout<<item.second[i];
            }
            
        }
        /*
        if(n!=m_pessoa.size()){
            std::cout<<"\n";
        }
        */
       std::cout<<"\n";
        
    }
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
            //std::cout<<"Pessoa "<<pes.first<< " distancia ate o posto " <<post.first<<" : "<< aux <<std::endl;
            vet.push_back(std::make_pair(post.first,aux));            
        }
        //std::cout<<"\nVETOR - "<<pes.first<<"\n";
        vet = OrdenaInsercaoFloat(vet,n_postos);
        for(int j=0;j<n_postos;j++){                                 
            //std::cout << "helou1";   
            a.AdicionaPreferencia(pes.first,vet[j].first);
            //std::cout << vet[j].first <<" : "<<vet[j].second <<" ";            
            //std::cout << "helou2";   
        }
        
    }
    
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

void Sistema_Prioridade::Matching(){
    //Criando rank de pessoas para os postos
    //so precisa de um rank pq todos os postos tem as mesmas preferencias    
    int rank[this->n_pessoas];
    for(int i=0;i<this->n_pessoas;i++){        
        rank[b[i]]=i;
    }

    
    std::cout<<"\n\tRANK POSTOS\n";
    for(int j=0;j<n_pessoas;j++){
        std::cout << rank[j] <<" ";
    }
    

    //Preenchendo os match de pessoa com -1
    //o de posto nao precisa pois para testar se o posto tem vaga
    //farei if(capacidade==tamanho) 
    //std::cout<<"\n\tMATCHING PESSOAS\n";
    for(int i=0;i<=this->n_pessoas;i++){
        this->m_posto[i]=-1;        
        //std::cout << i <<":"<<m_posto[i]<<" ";
    }
    
    

    //Preenchendo o map visitei com 0 -> (nao visistado)  
    //Cada pessoa tem q visitar todos os postos da sua lista  
    for(int i=0;i<this->n_pessoas;i++){
        for(int j=0;j<this->n_postos;j++){
            this->visitei[i].push_back(0);
        }                
    }
   
 

   /*Enquanto houver uma pessoa sem par E que nao propos para todos
    * os postos, faça:
    */

   int k;    
   int aux_p2_i = 0; //indice da pessoa que perdeu o match na lista de match dos postos
   int aux_p2 = 0; //pessoa que perdeu o match
   int aux_posto=-1;   
   k = Teste();
   while(k>=0){
       std::cout << "LOOP k=" << k <<"\n";
       aux_posto = a.PegaProxProposta(k);
       std::cout << "posto que ela quer " << aux_posto;
       if((int)m_pessoa[aux_posto].size()<postos[aux_posto].GetCapacidade()){           
           //std::cout << " ta livre"<<"\n";
           m_posto[k]=aux_posto;
           m_pessoa[aux_posto].push_back(k);
           std::cout << "Pessoa " << k <<" no Posto "<<m_posto[k]<<"\n";
           std::cout << "Posto " << aux_posto <<" com a Pessoa ";
           /*
           for(unsigned int i=0;i<m_pessoa[aux_posto].size();i++){
               std::cout<<m_pessoa[aux_posto][i];
           }
           */
           //std::cout << "\n";
       }else if((TesteRank(k,m_pessoa[aux_posto],rank,&aux_p2_i,&aux_p2))!=0){
           std::cout << " nao ta livre, ocupado por: "<<aux_p2<<" com indice "<<aux_p2_i<<"\n";
           m_posto[aux_p2]=-1;

           m_posto[k]=aux_posto;          
           m_pessoa[aux_posto][aux_p2_i] = k;

            
            //resetar as visistas e a proposta da pessoa aux_p2 que perdeu o match            
            for(int j=0;j<this->n_postos;j++){
                this->visitei[aux_p2][j]=0;
            }
            a.ReiniciaProposta(aux_p2);

           //std::cout << "Pessoa " << k <<" no Posto "<<m_posto[k]<<"\n";
           //std::cout << "Posto " << aux_posto <<" com a Pessoa ";
           /*
           for(unsigned int i=0;i<m_pessoa[aux_posto].size();i++){
               std::cout<<m_pessoa[aux_posto][i];
           }
           std::cout << "\n"; 
           */          
       }else{

       }
       //std::cout << "morre aqui\n";
       visitei[k][aux_posto]=1;
       //std::cout << "ou morre aqui\n";
        a.AndaProposta(k);
       
       k = Teste();       
   }

   //ordenar m_pessoas
   
   for(auto &item : this->m_pessoa){
       m_pessoa[item.first] = OrdenaVector(m_pessoa[item.first],(int)m_pessoa[item.first].size());
   }      
   

}

std::vector<int> Sistema_Prioridade::OrdenaVector(std::vector<int> v, int n){
    //Pessoa p = pessoas[v[1]];
    int i,j;
    int aux;
    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (( j >= 0 ) && (pessoas[aux].GetIdade() > pessoas[v[j]].GetIdade())) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
    return v;
}

int Sistema_Prioridade::Teste(){
    //Enquanto houver uma pessoa sem par E que nao propos para todos
    //os postos, faça:
    
   for(int i=0;i<=this->n_pessoas;i++){
       if(m_posto[i]==-1){ //Teste sem par, pega pessoa sem par
            /*
            // teste de instabilidade
            // Se houver alguem sem par que dentro do seus postos
            // de preferencia, um posto que esta com alguem que prefere
            // menos quem ele ta do que eu, entao zera a proposta e 
            // faça a proposta.
            for(int k=0;k<n_postos;k++){ 
                int aux;
                aux = a.PegaItemNaLista(i,k);
                if((int)m_pessoa[aux].size()<postos[aux].GetCapacidade()){
                    *aux_p=aux;
                    return i;
                }else{
                    for(unsigned int j=0;j<m_pessoa[aux].size();j++){
                        if(rank[i]<rank[m_pessoa[aux][j]]){
                            *aux_p = aux;
                            return i;
                        }
                    }
                }                
            }
            */                        
            for(unsigned int j=0;j<visitei[i].size();j++){
                if(visitei[i][j]==0){ //Existe alguem nao visitado?
                    return i;
                }
            }
            
            
       }
   }
   //depois de ter resolvido boa parte dos casamentos
   //vou testar a estabilidade percorrendo os as pessoas   
   //Uma pessoa p1 esta alocada para um posto β, mas ha um posto α mais proximo
   //que possui vagas disponıveis ou esta alocando uma pessoa p2 de menor idade.




    /*

   for(int i=0;i<n_pessoas;i++){       
       if(m_posto[i]!=-1){
           int p_i = m_posto[i];
           std::vector<int> l_pref = a.GetListaVector(i);
           std::cout << "\nPessoa " << i << "Prefere os postos: ";
           for(unsigned int j=0;j<l_pref.size();j++){
               std::cout << l_pref[j] << " ";
           }
           std::cout <<"\n";
       }
   }
   */
    /*
   for(int p_j=0;p_j<n_postos;p_j++){
                if(p_i!=p_j){
                    for(unsigned int j=0;j<m_pessoa[p_j].size();j++){
                        if(m_pessoa[p_i][i]!=m_pessoa[p_j][j]){
                            if(rank[m_pessoa[p_i][i]]<rank[m_pessoa[p_j][j]]){
                                std::cout << "\nPessoa " << m_pessoa[p_j][i] <<" esta com o Posto "<<p_j<<" mas prefere o Posto "<<p_i<<"\n";
                                //resetar as visistas e a proposta da pessoa l porque é um par instavel
                                for(int l=0;l<this->n_postos;l++){
                                    this->visitei[m_pessoa[p_j][j]][l]=0;
                                }
                                a.ReiniciaProposta(m_pessoa[p_j][j]);
                                return m_pessoa[p_j][j];
                            }
                        }
                    }
                }
            }
            */
    return -1;
}

int Sistema_Prioridade::TesteRank(int pessoa, std::vector<int> l_pessoa,int rank[],int *p_i, int *p2){
    for(unsigned int i=0;i<l_pessoa.size();i++){
        //std::cout << "\nOlhando Pessoa " << pessoa <<" em relação a "<<l_pessoa[i]<<"\n";
        if(rank[pessoa]<rank[l_pessoa[i]]){ 
            //std::cout << "entrei\n";           
            *p2 = l_pessoa[i];
            *p_i = i;
            return 1;
        }
    }
    return 0;
}

/*
int Sistema_Prioridade::Teste(int rank[], int *aux_p, int *caso,int *pessoa_perdeu,int *pessoa_perdeu_i){
    for(int i=0;i<=this->n_pessoas;i++){
            if(m_posto[i]==-1){ //Teste sem par, pega pessoa sem par
                    // teste de instabilidade
                    // Se houver alguem sem par que dentro do seus postos
                    // de preferencia, um posto que esta com alguem que prefere
                    // menos quem ele ta do que eu, entao zera a proposta e 
                    // faça a proposta.
                    for(int l=0;l<n_postos;l++){ 
                        int aux;
                        aux = a.PegaItemNaLista(i,l);
                        if((int)m_pessoa[aux].size()<postos[aux].GetCapacidade()){
                            *aux_p=aux;
                            *caso = 1;
                            return i;                                                        
                        }else{
                            for(unsigned int j=0;j<m_pessoa[aux].size();j++){
                                if(rank[i]<rank[m_pessoa[aux][j]]){
                                    *aux_p = aux;
                                    *caso = 2;
                                    *pessoa_perdeu = m_pessoa[aux][j];
                                    *pessoa_perdeu_i = j;                                                                        
                                    return i;
                                }
                            }
                        }                
                    }                                    
            }
        }
    return -1;

}
*/


