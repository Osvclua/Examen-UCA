#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// termina

int main(int argc, char * argv[]){
	sv_sem semWE("SemWE");
	cout<<"Borrando "<<semWE<<endl;
	semWE.del();
	 
	elSwitch sw("Sw");
	cout<<"Borrando "<<sw<<endl;
	sw.del();
	sv_sem semEW("SemEW");
	cout<<"Borrando "<<semEW<<endl;
	semEW.del();
	}
