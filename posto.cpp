#include "headers/posto.h"

Posto::Posto(){

}

Posto::Posto(int capacidade, float x, float y){
    this->capacidade=capacidade;
    this->x=x;
    this->y=y;
}

float Posto::GetX(){
    return this->x;
}

float Posto::GetY(){
    return this->y;            
}

int Posto::GetCapacidade(){
    return this->capacidade;
}