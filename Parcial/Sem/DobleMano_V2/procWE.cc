#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que va en sentido "Vuelta" (Der-> Izq)

int main(int argc, char * argv[]){
  string rta;
  sv_sem semEW("SemEW");
  sv_sem semWE("SemWE");
  elSwitch swWE("SwWE");
  cout<<"Voy D->I, espero que no haya transito I->D."<<endl;
  semEW.wait();   // por si esta funcionando en el otro sentido
    cout<<"Entrando a la ruta compartida D->I."<<swWE<<endl;
    cout<<"Semaforo "<<semWE<<endl;
    swWE.entra(semWE);
  semEW.post();
  cout<< "Circulando W->E"<<endl;
  cin>>rta;
  swWE.sale(semWE);
  cout<<"Saliendo de la ruta compartida D->I."<<swWE<<endl;
  cout<<"semWE "<<semWE<<endl;
 cout<<"Termina."<<endl;
}
