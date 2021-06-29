#include <iostream>
#include "headers/sistema_prioridade.h"

int main(){
  Sistema_Prioridade sistema;
  sistema.Leitura();
  sistema.Imprimir();
  sistema.ConstruirPreferencias();
  return 0;
}
