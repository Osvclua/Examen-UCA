#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;
// Proceso que quiere acceso exclusivo

int main(int argc, char * argv[]){
  string rta;
  string nom("P"+to_string(getpid()));
  sv_sem semTablero("SemTablero");
  cout<<nom<<" entrando al Tablero."<<semTablero<<endl;
  semTablero.wait();
  cout<<nom<<" en el tablero..."<<endl;
  cin>>rta;
  semTablero.post();
 cout<<nom<<" termina."<<endl;
}
