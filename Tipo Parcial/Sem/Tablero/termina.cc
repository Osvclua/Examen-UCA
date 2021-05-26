#include "elSwitch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// termina

int main(int argc, char * argv[]){
	    sv_sem semSala("SemSala");
		cout<<"Borrando "<<semSala<<endl;
		semSala.del();
		elSwitch sala("Sala");
		cout<<"Borrando "<<sala<<endl;
		sala.del();
	}
