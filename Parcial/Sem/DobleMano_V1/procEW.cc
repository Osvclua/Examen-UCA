#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que va en sentido "EW" 

int main(int argc, char * argv[]){
  string rta;
  sv_sem semPuente("SemPuente");
  elSwitch swEW("SwEW");
  cout<<"Entrando a la ruta compartida E->W."<<swEW<<endl;
  cout<<"Semaforo "<<semPuente<<endl;
  swEW.entra(semPuente);
  cout<< "Circulando E->W"<<endl;
  cin>>rta;
  swEW.sale(semPuente);
  cout<<"Saliendo de la ruta compartida E->W."<<swEW<<endl;
  cout<<"semPuente "<<semPuente<<endl;
  cout<<"Termina."<<endl;
}
