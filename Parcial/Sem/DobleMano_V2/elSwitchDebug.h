#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
using namespace std;
#ifndef _switch_
#define _switch_

typedef struct {int n;} conta;

class elSwitch{
	string clave;
	sv_sem miMutex;
	sv_shm datos;
	conta *p_cont;
	public:
	elSwitch(string k){
		clave=k;
		string clave_mutex=clave+"_mutex";
		string clave_shm=clave+"_shm";
		miMutex=sv_sem(clave_mutex);
		datos=sv_shm(clave_shm);
		p_cont=reinterpret_cast<conta*>(datos.map(sizeof(conta)));
	   // p_cont->n=0; 
		cout<<"Tomado "<<miMutex<<endl;
		cout<< "Tomado "<<datos<<" con valor "<<p_cont->n<<endl;
	}
	void entra(sv_sem semaf){
		string res;
		cout<<"Entra al switch "<<clave<<endl;
		miMutex.wait();
		p_cont->n++;
		cout<< "Soy el numero "<<p_cont->n<<endl;
		if (p_cont->n==1) {
			cout<<"A punto de hacer el wait()..."<<endl;
			cin>>res;
			semaf.wait();
		}
		miMutex.post();
	}
	void sale(sv_sem semaf){
		string res;
		miMutex.wait();
		p_cont->n--;
		cout<< "Soy el numero "<<p_cont->n<<endl;
		if (p_cont->n==0) {
			cout<<"A punto de hacer el wait()..."<<endl;
			cin>>res;
			semaf.post();
		}
		cout<<"Sale del switch "<<clave<<endl;
		miMutex.post();
	}
	void del(){
		cout<<"Borrando "<<miMutex<<endl;
		miMutex.del();
		cout <<"Liberando "<<datos<<endl;
		datos.del();
	}
    friend ostream& operator<<(ostream& os, elSwitch s){
	return os<<"("<<s.clave<<", val="<<s.p_cont->n<<", miMutex= "<<s.miMutex<<")"<<endl;
	}	
};
#endif