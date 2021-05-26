#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
#include <unistd.h>

using namespace std;

int main(int argc, char * argv[]){
  
  string nom="P"+to_string(getpid()); 
  string entrada;
  sv_sem matricula("matricula",0);
  sv_sem inventario("inventario",0);
  sv_sem catalogo("catalogo",0);
  cout<<"Consolidador "<<nom<<" busca matricula "<<endl;
  matricula.wait();
  cout<<"Consolidador "<<nom<<" tiene matricula, busca inventario "<<endl;
  inventario.wait();
  cout<<"Consolidador "<<nom<<" tiene matricula, busca catalogo "<<endl;
  catalogo.wait();
  cout<<"Consolidador "<<nom<<" trabajando ..."<<endl;
  cin>>entrada;
  cout<<"Consolidador "<<nom<<" se va"<<endl;
}