#include "barrera.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]){ 
  if (argc<2) {
    cerr<<"Uso: "<<argv[0]<<" <Nombre-Barrera>"<<endl;
    exit(1);
  }

  barrera entrada(argv[1]);
  cout<<"Borrando "<<entrada<<endl;
  entrada.del();
  }