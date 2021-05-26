#include "includes.h"

int main(int argc, char * argv[]){
  string nom,auxrta;
  nom="consolidador-"+to_string(getpid());
  cout<<nom<<endl;
  mpdu *m1;
  sv_mq matricula("/matricula");
  sv_mq inventario("/inventario");
  sv_mq catalogo("/catalogo");
  cout<<"Busco matricula"<<endl;
  m1=matricula.receive();
  delete(m1);
  cout<<"Busco inventario"<<endl;
  m1=inventario.receive();
  delete(m1);
  cout<<"Busco catalogo"<<endl;
  m1=catalogo.receive();
  delete(m1);
  cout<<"Trabajando."<<endl;
}

