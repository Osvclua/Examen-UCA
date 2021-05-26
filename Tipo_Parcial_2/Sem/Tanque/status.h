#ifndef status__h
#define status__h
#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"

class status{
	int procA=0;
	int procB=0;
public:
	status(){};
	void inicializa(){
		procA=0; procB=0;
	}
	int getProcA(){return procA;}
	int getProcB(){return procB;}
	void llegaA(){procA++;}  
	void llegaB(){procB++;}
	void entraA(){procA--;}  
	void entraB(){procB--;}
	friend ostream& operator<<(ostream&os, status s){
		return os<<"(procA="<<s.getProcA()<<", procB="<<s.getProcB()<<")";
	}
} ;

#endif