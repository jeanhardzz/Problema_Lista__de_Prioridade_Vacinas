#include <iostream>
#include "headers/sistema_prioridade.h"
#include "Lista_encadeada/lista-encadeada.h"

int main(){
  Sistema_Prioridade sistema;
  sistema.Leitura();  
  sistema.ConstruirPreferencias();    
  //sistema.Imprimir();
  sistema.Matching();
  sistema.Imprimir();
  

  /*
  std::map<int,ListaEncadeada> visitei;
  for(int i=0;i<10;i++){
        visitei[i].InsereFinal(0);
        visitei[i].InsereFinal(0);
    }

  std::cout<<"\n\tPESSOAS VISITADAS\n";
    for(int i=0;i<10;i++){
        std::cout << i << " : " ;
        visitei[i].Imprime();
    }

  std::cout<<"\n\tONDE EXISTE 0\n";
  for(int i=0;i<=10;i++){       
    if(visitei[i].Existe(0)==1){ //Existe alguem nao visitado?
      std::cout << i << " " ;
    }       
    std::cout <<"\n" ;
   }
   */
  return 0;
}
