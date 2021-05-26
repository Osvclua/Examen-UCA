#include "barrera.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main(int argc, char * argv[]){
  int n=3;
  
  string nomBar("Atraccion");
 	string nom("P"+to_string(getpid())),rta;
  barrera entrada(nomBar);
  cout<<nom<<" entrando a la RC."<<endl<<"Barrera "<<entrada<<endl;
  entrada.entrar();
  cout<<nom<< " Termino, me bajo..."<<endl;
  cin>>rta;
  entrada.salir();
 cout<<nom<<" termina."<<endl;
}
