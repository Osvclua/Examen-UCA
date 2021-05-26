#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
using namespace std;

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
      
  sv_sem matricula("matricula",0);
  sv_sem inventario("inventario",0);
  sv_sem catalogo("catalogo",0);
  
  for (int i=0; i<ip; i++) matricula.post();
  for (int i=0; i<it; i++) inventario.post();
  for (int i=0; i<ifo; i++) catalogo.post();

}