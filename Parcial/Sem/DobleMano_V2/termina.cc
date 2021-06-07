#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// termina

int main(int argc, char * argv[]){
	sv_sem semPuente("SemPuente");
	cout<<"Borrando "<<semPuente<<endl;
	semPuente.del();
	 
	elSwitch swEW("SwEW");
	cout<<"Borrando "<<swEW<<endl;
	swEW.del();
	elSwitch swWE("SwWE");
	cout<<"Borrando "<<swWE<<endl;
	swWE.del();
	}
