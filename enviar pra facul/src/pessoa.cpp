#include "headers/pessoa.h"

Pessoa::Pessoa(){   
}

Pessoa::Pessoa(int idade, float x, float y){
    this->idade=idade;
    this->x=x;
    this->y=y;
}

float Pessoa::GetX(){
    return this->x;
}

float Pessoa::GetY(){
    return this->y;            
}

int Pessoa::GetIdade(){
    return this->idade;
}