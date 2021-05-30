#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// termina

int main(int argc, char * argv[]){
	sv_sem semEW("SemEW");
	cout<<"Borrando "<<semEW<<endl;
	semEW.del();
	sv_sem semWE("SemWE");
	cout<<"Borrando "<<semWE<<endl;
	semWE.del();
	elSwitch swEW("SwEW");
	cout<<"Borrando "<<swEW<<endl;
	swEW.del();
	elSwitch swWE("SwWE");
	cout<<"Borrando "<<swWE<<endl;
	swWE.del();
	}
