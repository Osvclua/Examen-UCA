#include "elSwitchDebug.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que va en sentido "WE" 

int main(int argc, char * argv[]){
  string rta;

  sv_sem semPuente("SemPuente");
  elSwitch swWE("SwWE");
  cout<<"Entrando a la ruta compartida W->E."<<swWE<<endl;
  cout<<"Semaforo "<<semPuente<<endl;
  swWE.entra(semPuente);
  cout<< "Circulando W->E"<<endl;
  cin>>rta;
  swWE.sale(semPuente);
  cout<<"Saliendo de la ruta compartida W->E."<<swWE<<endl;
  cout<<"semPuente "<<semPuente<<endl;
  cout<<"Termina."<<endl;
}
