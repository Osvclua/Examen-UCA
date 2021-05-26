#include "../Mq-sv/sv_mq.h"
#include "unistd.h"

int main(){
  mpdu m,*m1;
  string s,nom;
  nom="A-"+to_string(getpid());
  sv_mq mutex("/mutexA");
  sv_mq pedidos("/pedidos");
  cout<<"Usando cola "<<mutex<<endl;
  cout<<"Intento entrar"<<endl;
  m.setHdr("EntA");
  m.setSdu(nom);
  pedidos.send(m);
  cout<<"Enviado "<<m<<endl;
  m1=mutex.receive();
  delete (m1);
  cout<<"... en el Tanque ..."<<endl;
  cin>>s;
  m.setHdr("ChauA");
  pedidos.send(m);
  cout<< "terminando"<<endl;
}