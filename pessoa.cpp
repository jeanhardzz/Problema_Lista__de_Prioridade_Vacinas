#include "headers/pessoa.h"

Pessoa::Pessoa(){   
}

Pessoa::Pessoa(int idade, int x, int y){
    this->idade=idade;
    this->x=x;
    this->y=y;
}

int Pessoa::GetX(){
    return this->x;
}

int Pessoa::GetY(){
    return this->y;            
}

int Pessoa::GetIdade(){
    return this->idade;
}