#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// inicializa

int main(int argc, char * argv[]){
	sv_sem semPuente("SemPuente",1);
	cout<<"Creado "<<semPuente<<endl;	
	elSwitch swEW("SwEW");
	cout<<"Creado "<<swEW<<endl;
	elSwitch swWE("SwWE");
	cout<<"Creado "<<swWE<<endl;
}
