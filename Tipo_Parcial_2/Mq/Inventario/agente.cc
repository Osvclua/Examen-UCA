#include "includes.h"

int main(int argc, char * argv[]){
  if (argc < 4) {
      cerr<<"Uso: "<<argv[0]<<" matricula inventario catalogo"<<endl;
      exit(2);
  }
  string p=argv[1], t=argv[2], f=argv[3]; 
  string entrada;
  int ip=atoi(p.c_str());
  int it=atoi(t.c_str());
  int ifo=atoi(f.c_str());
  cout<<"Agente pone "<<ip<<" matricula, "<<it<<" inventario y "
      <<ifo<<" catalogo."<<endl;
      
  sv_mq matricula("/matricula");
  sv_mq inventario("/inventario");
  sv_mq catalogo("/catalogo");
  mpdu m;
  for (int i=0; i<ip; i++) matricula.send(m);
  for (int i=0; i<it; i++) inventario.send(m);
  for (int i=0; i<ifo; i++) catalogo.send(m);

}