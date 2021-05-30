#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// inicializa

int main(int argc, char * argv[]){
	sv_sem semEW("SemEW",1);
	cout<<"Creado "<<semEW<<endl;
	sv_sem semWE("SemWE",1);
	cout<<"Creado "<<semWE<<endl;
	elSwitch swEW("SwEW");
	cout<<"Creado "<<swEW<<endl;
	elSwitch swWE("SwWE");
	cout<<"Creado "<<swWE<<endl;
}
