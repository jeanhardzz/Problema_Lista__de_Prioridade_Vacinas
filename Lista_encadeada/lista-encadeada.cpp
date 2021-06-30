#include <iostream>
#include "lista-encadeada.h"

ListaEncadeada::ListaEncadeada() : Lista() {
    primeiro = new TipoCelula();
    ultimo = primeiro;    
}

ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}

TipoItem ListaEncadeada::GetProposta(){
    return prox_proposta->prox->item;
}
void ListaEncadeada::AndaProposta(){
    prox_proposta = prox_proposta->prox;
}

void ListaEncadeada::ReiniciaProposta(){    
    prox_proposta = primeiro;
}

void ListaEncadeada::ImprimeProposta(){
    prox_proposta->prox->item.Imprime();
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
        p = p->prox;
    return p;

    prox_proposta = primeiro;
}

TipoItem ListaEncadeada::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
}
void ListaEncadeada::SetItem(TipoItem item, int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if(nova->prox == 0)
        ultimo = nova;
    
    prox_proposta = primeiro;
};

void ListaEncadeada::InsereFinal(TipoItem item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    if(tamanho==0){
        primeiro->prox = nova;
    }
    tamanho++;

    prox_proposta = primeiro;
};

void ListaEncadeada::InserePosicao(TipoItem item, int pos) {
    TipoCelula *p, *nova;
    p = Posiciona(pos,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    if(nova->prox == 0)
        ultimo = nova;
    
    prox_proposta = primeiro;
};

void ListaEncadeada::InserePosicaoEApaga(int chave, int pos){
    TipoItem item;
    item.SetChave(chave);
    TipoCelula *p, *nova;
    p = Posiciona(pos,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox->prox;
    p->prox = nova;

    if(nova->prox == 0)
        ultimo = nova;

    delete p->prox;
}

TipoItem ListaEncadeada::RemoveInicio() {;
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == 0)
        ultimo = primeiro;
    aux = p->item;
    delete p;
    return aux;

    prox_proposta = primeiro;
}

TipoItem ListaEncadeada::RemoveFinal() {
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->prox = 0;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    return aux;

    prox_proposta = primeiro;
}

TipoItem ListaEncadeada::RemovePosicao(int pos) {;
    TipoItem aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == 0)
        ultimo = p;
    return aux;

    prox_proposta = primeiro;
}

TipoItem ListaEncadeada::Pesquisa(TipoChave c) {
    TipoItem aux;
    TipoCelula *p;
    aux.SetChave(-1);

    if (tamanho == 0)
        return aux;
        
    p = primeiro->prox;    
    while (p!=0) {
        if (p->item.GetChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
}

int ListaEncadeada::Existe(TipoChave c) {    
    TipoCelula *p;    

    if (tamanho == 0)
        return 0;
        
    p = primeiro->prox;    
    while (p!=0) {
        if (p->item.GetChave() == c) {            
            return 1;
        }
        p = p->prox;
    }
    return 0;
}

int ListaEncadeada::PesquisaPos(TipoChave c) {
    int aux=0;
    TipoCelula *p;    

    if (tamanho == 0)
        return 0;
        
    p = primeiro->prox;    
    while (p!=0) {
        aux++;
        if (p->item.GetChave() == c) {            
            return aux;
        }
        p = p->prox;
    }
    return aux;
}

void ListaEncadeada::Imprime() {
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=0) {
        p->item.Imprime();
        p = p->prox;
    }
    std::cout<<"\n";
}

void ListaEncadeada::Limpa() {
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;

    prox_proposta = primeiro;
}

void ListaEncadeada::Inverte(){
    TipoCelula *p;
    TipoCelula *frente=NULL;
    TipoCelula *tras=NULL;
    TipoCelula *aux=NULL;

    p = primeiro->prox;
    frente= p->prox;
    
    while (frente!=NULL){ 
        aux=frente->prox;       
        frente->prox=p;
        p->prox=tras;
        primeiro->prox=frente;

        tras=p;
        p= frente;
        frente=aux;                
        
    }
    prox_proposta = primeiro;
    //Complexidade O(n)
    
}


