#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que va en sentido "Ida" (Izq-> Der)

int main(int argc, char * argv[]){
  string rta;
  sv_sem semEW("SemEW");
  sv_sem semWE("SemWE");
  elSwitch swEW("SwEW");
  cout<<"Voy I->D, espero que no haya transito D->I."<<endl;
    semWE.wait();
    cout<<"Entrando a la ruta compartida I->D."<<swEW<<endl;
    cout<<"Semaforo "<<semEW<<endl;
    swEW.entra(semEW);
  semWE.post();
  cout<< "Circulando E->W"<<endl;
  cin>>rta;
  swEW.sale(semEW);
  cout<<"Saliendo de la ruta compartida I->D."<<swEW<<endl;
  cout<<"semEW "<<semEW<<endl;
 cout<<"Termina."<<endl;
}
