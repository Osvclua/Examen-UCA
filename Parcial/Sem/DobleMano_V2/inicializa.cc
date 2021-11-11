#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// inicializa

int main(int argc, char * argv[]){
	sv_sem semEW("SemEW",1);
	sv_sem semWE("SemWE",1);
	elSwitch sw("Sw");
	cout<<"Creado "<<sw<<endl<<semEW<<endl<<semWE<<endl;
	
}
