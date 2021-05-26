#include "../Mq-sv/sv_mq.h"

void impStatus(sv_mq mutexA, sv_mq mutexB, int procA, int procB){
  cout<<"mutexA="<<mutexA<<endl<<"mutexB="<<mutexB<<endl;
  cout<<"procA="<<procA<<", procB="<<procB<<endl;
}

int main(){
  mpdu m,*m1;
  string s,ms;
  sv_mq mutexA("/mutexA");
  sv_mq mutexB("/mutexB");
  int procA=0,procB=0;
  sv_mq pedidos("/pedidos");
  m.setHdr("Sigue");
  cout<<"Esperando pedidos"<<endl;
  m1=pedidos.receive();
  cout<<"Recibido "<<*m1<<endl;
  s=m1->getHdr();
  while (s!="Fin"){
    impStatus(mutexA,mutexB,procA,procB);
    if (s=="EntA"){procA++;}
    if (s=="EntB"){procB++;}
    cout<<"Registrado el pedido."<<endl;
    impStatus(mutexA,mutexB,procA,procB);
    if ((procA>1)and (procB>0)){
      cout <<"Entra un grupo. "<<endl;
      mutexA.send(m);mutexB.send(m);mutexA.send(m);
      procA--;procB--;procA--;
      impStatus(mutexA,mutexB,procA,procB);
    }
    cout<<"Esperando pedidos"<<endl;
    delete(m1);
    m1=pedidos.receive();
    cout<<"Recibido "<<*m1<<endl;
    s=m1->getHdr();
  }
  cout<<"termina"<<endl;
}