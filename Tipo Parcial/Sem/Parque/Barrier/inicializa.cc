#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
#include "barrera.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char*argv[]){
   int proc=getpid();
   string nomBar ("Atraccion");
   int participantes=3;
   barrera b(nomBar,participantes);
   cout<<"Creada la barrera "<<b<<endl;
}