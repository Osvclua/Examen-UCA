#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// inicializa

int main(int argc, char * argv[]){
	sv_sem semSala("SemSala",1);
	cout<<"Creado "<<semSala<<endl;
	elSwitch sala("Sala");
	cout<<"Creado "<<sala<<endl;
}
