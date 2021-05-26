#include "barrera.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]){ 
  
  barrera entrada("Atraccion");
  cout<<"Borrando "<<entrada<<endl;
  entrada.del();
  }