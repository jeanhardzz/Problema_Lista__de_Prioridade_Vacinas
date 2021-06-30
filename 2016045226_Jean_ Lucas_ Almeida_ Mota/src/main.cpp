#include <iostream>
#include "headers/sistema_prioridade.h"
#include "Lista_encadeada/lista-encadeada.h"

int main(){
  Sistema_Prioridade sistema;
  sistema.Leitura();  
  sistema.ConstruirPreferencias();      
  sistema.Matching();
  sistema.Imprimir();
  
  return 0;
}
