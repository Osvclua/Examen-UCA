#include "barrera.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]){
  int n=0;
  if (argc<2) {
    cerr<<"Uso: "<<argv[0]<<"<Nombre del carro> "<<endl;
    exit(1);
  }
  string nomBar("Atraccion");
 	string nom(argv[1]),rta;
  barrera entrada(nomBar,n);
  cout<<nom<<" entrando a la seccion critica."<<entrada<<endl;
  entrada.entrar();
  cout<<nom<< " en la seccion critica..."<<endl;
  cin>>rta;
  entrada.salir();
 cout<<nom<<" termina."<<endl;
}
