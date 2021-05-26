#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// proceso que puede entrar de a muchos 

int main(int argc, char * argv[]){
  string rta;
  string nom("P"+to_string(getpid()));
  sv_sem semTablero("SemTablero");
  elSwitch Tablero("Tablero");
  cout<<nom<<" entrando al Tablero."<<Tablero<<endl;
  cout<<"Semaforo "<<semTablero<<endl;
  Tablero.entra(semTablero);
  cout<<nom<<" En el Tablero..."<<endl;
  cin>>rta;
  Tablero.sale(semTablero);
  cout<<nom<<" Saliendo del Tablero."<<Tablero<<endl;
  cout<<"SemTablero "<<semTablero<<endl;
 cout<<nom<<" termina."<<endl;
}
