#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
using namespace std;

int main(int argc, char * argv[]){
  sv_sem matricula("matricula",0);
  sv_sem inventario("inventario",0);
  sv_sem catalogo("catalogo",0);
  cout<<"Borrado"<<endl<<matricula<<endl<<catalogo<<endl<<
    inventario<<endl;
  matricula.del();
  inventario.del();
  catalogo.del();
}