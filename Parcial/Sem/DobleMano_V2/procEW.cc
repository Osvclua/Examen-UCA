#include "elSwitchDebug.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que va en sentido "EW" 
//
//    No fuciona. correr con elSwitchDebug.h
//

int main(int argc, char * argv[]){
  string rta;
  sv_sem semEW("SemEW");
  sv_sem semWE("SemWE");
  elSwitch sw("Sw");
  cout<<"Voy E->W, espero que no haya transito W->E."<<endl;
  semWE.wait();
  cout<<"Entrando a la ruta compartida E->W."<<sw<<endl;
  cout<<"Semaforo "<<semEW<<endl;
  sw.entra(semEW);
  semWE.post();
  cout<< "Circulando E->W"<<endl;
  cin>>rta;
  sw.sale(semEW);
  cout<<"Saliendo de la ruta compartida E->W."<<sw<<endl;
  cout<<"semEW "<<semEW<<endl;
  cout<<"Termina."<<endl;
}
