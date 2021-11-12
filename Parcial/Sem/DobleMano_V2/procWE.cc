#include "elSwitchDebug.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que va en sentido WE
//
//    No fuciona. correr con elSwitchDebug.h
//


int main(int argc, char * argv[]){
  string rta;
  sv_sem semEW("SemEW");
  sv_sem semWE("SemWE");
  elSwitch sw("Sw");
  cout<<"Voy W->E, espero que no haya transito E->W."<<endl;
  semEW.wait();   // por si esta funcionando en el otro sentido
    cout<<"Entrando a la ruta compartida W->E."<<sw<<endl;
    cout<<"Semaforo "<<semWE<<endl;
    sw.entra(semWE);
  semEW.post();
  cout<< "Circulando W->E"<<endl;
  cin>>rta;
  sw.sale(semWE);
  cout<<"Saliendo de la ruta compartida W->E."<<sw<<endl;
  cout<<"semWE "<<semWE<<endl;
  cout<<"Termina."<<endl;
}
