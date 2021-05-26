#include "includes.h"

int main(int argc, char * argv[]){
  
  
  sv_mq matricula("/matricula");
  sv_mq inventario("/inventario");
  sv_mq catalogo("/catalogo");
  
  cout<<"Eliminando "<<matricula<<endl;
  matricula.del();
  cout<<"Eliminando "<<inventario<<endl;
  inventario.del();
  cout<<"Eliminando "<<catalogo<<endl;
  catalogo.del();



}