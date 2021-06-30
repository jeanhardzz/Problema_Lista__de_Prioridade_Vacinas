#include "headers/lista_preferencia.h"

ListaPreferencia::ListaPreferencia(){
    this->total=0;
}

int ListaPreferencia::GetTotal(){
    return this->total;
}

/*
*Adiciona a preferencia em ordem decrescente
*Nao testa se a preferencia ja existe
*/
void ListaPreferencia::AdicionaPreferencia(TipoChave original,TipoChave pref){
    
    auto aux = g.find(original);
    if(aux == g.end()){ //Se o no nao existe no grafo        
        this->total++;
    }

    this->g[original].InsereFinal(pref);
}
  

void ListaPreferencia::Imprime(){
    for(auto &item : g){
        std::cout << item.first << " : " ;
        item.second.Imprime();        
    }
    
    //https://www.delftstack.com/pt/howto/cpp/how-to-iterate-over-map-in-cpp/
}

void ListaPreferencia::ImprimeProposta(TipoChave elemento){    
    g[elemento].ImprimeProposta();
}

void ListaPreferencia::AndaProposta(TipoChave elemento){
    g[elemento].AndaProposta();
}

TipoChave ListaPreferencia::PegaProxProposta(TipoChave elemento){
    return g[elemento].GetProposta().GetChave();
}

void ListaPreferencia::ReiniciaProposta(TipoChave elemento){
    g[elemento].ReiniciaProposta();
}


ListaPreferencia ListaPreferencia::Rank(){
    ListaPreferencia rank;
    for(auto &item : g){
        for(int i=1;i<=item.second.GetTamanho();i++){
            rank.AdicionaPreferencia(item.first,item.second.PesquisaPos(i));
        }
    }
    return rank;
}

ListaEncadeada ListaPreferencia::GetLista(TipoChave key){
    return g[key];
}

std::vector<int> ListaPreferencia::GetListaVector(TipoChave key){
    std::vector<int> r;
    for(int i=1;i<=g[key].GetTamanho();i++){
        r.push_back(g[key].GetItem(i).GetChave());
    }
    return r;
}

TipoChave ListaPreferencia::PegaItemNaLista(TipoChave key, TipoChave pos){
    return g[key].GetItem(pos).GetChave();
}





