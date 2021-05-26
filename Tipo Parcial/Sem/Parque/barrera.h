#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
#ifndef _barrerah
#define _barrerah

using namespace std;
class vals{;
	int grupo;
	int en_cola;
	int adentro;
  public:
  	vals():adentro(0),en_cola(0),grupo(0){};
	int getAdentro(){return adentro;}
   	int getEnCola(){return en_cola;}
    int getGrupo(){return grupo;}  
	bool hayGrupo(){return en_cola>=grupo;}
	bool hayLugar(){return hayGrupo() and adentro==0;}	
	void encolar(){en_cola++;}
	void pasar(){en_cola-=grupo; adentro=grupo;}	
	void salir(){adentro--;}
    void inicializa(int c=0, int q=0, int a=0){
		grupo=c; en_cola=q; adentro=a;
		cout<<"vals inicializado "<<grupo<<","<<adentro<<","<<en_cola<<endl;
	}	
	friend ostream& operator<<(ostream& os, vals v){
		return os<<"("<<v.getGrupo()<<", "<<v.getEnCola()<<", "<<v.getAdentro()<<")";
	}
};

class barrera {
	string clave;
	sv_sem semBar ;
	sv_sem mutex;
	sv_shm memBar ;
	vals *p_vals;
  private:
	void abre(){
		for(int i=0; i<p_vals->getGrupo();i++){
			semBar.post();
		}
		p_vals->pasar();
	}	
  public:
	barrera(string cla, int num=0)
	{
	clave=cla;
	semBar= sv_sem(clave,0);  // barrera cerrada
	mutex= sv_sem(clave+"_mutex",1);  // mutex abierto
	memBar=sv_shm(clave);   
	p_vals=reinterpret_cast<vals*>(memBar.map(sizeof(vals)));
	if ((num!=0)and 
   			 (p_vals->getGrupo()!=num)) p_vals->inicializa(num,0,0);  // grupos de num
			};
	sv_sem getSem(){return semBar;}
	sv_shm getShm(){return memBar;}
	vals getVals() {return *p_vals;}
	void entrar(){
		mutex.wait();
		p_vals->encolar();
		if (p_vals->hayLugar()) {
			abre();
		}
		mutex.post();
		semBar.wait();
	}
	void salir(){
		mutex.wait();
		p_vals->salir();
		if (p_vals->hayLugar()){
			abre();
			}
		mutex.post();
	}
	void del(){
		cout<<"Borrando "<<semBar<<endl;
		semBar.del();
		cout<<"Borrando "<<memBar<<endl;
		memBar.del();
		cout<<"Borrando "<<mutex<<endl;
		mutex.del();
		
	}
		friend ostream& operator<<(ostream& os, barrera b){
		return os<<b.clave<<"=("<< b.getSem()<<","<<b.getShm()<<", (grupo,en_cola,adentro)= "<<b.getVals()<<")";
	}
};
#endif
