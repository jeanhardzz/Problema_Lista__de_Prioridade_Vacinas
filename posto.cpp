#include "headers/posto.h"

Posto::Posto(){

}

Posto::Posto(int capacidade, int x, int y){
    this->capacidade=capacidade;
    this->x=x;
    this->y=y;
}

int Posto::GetX(){
    return this->x;
}

int Posto::GetY(){
    return this->y;            
}

int Posto::GetCapacidade(){
    return this->capacidade;
}