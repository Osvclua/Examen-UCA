#ifndef _area_h
#define _area_h
#define entra "AD"
#define llegaSuper "SUPLL"
#define llegaModif "MODLL"
#define saleSuper "SUPSA"
#define saleModif "MODSA"
#define fin "CHAU"
using namespace std;

class estado{
    int mod_esp=0;
    int mod_act=0;
    int sup_esp=0;
    int sup_act=0;
public:
    estado(){};
    void llegaMod(){ mod_esp++;}
    void entraMod(){ mod_esp--; mod_act++;}
    void saleMod(){mod_act--;}
    void llegaSup(){sup_esp++;}
    void entraSup(){sup_esp--,sup_act++;}
    void saleSup(){sup_act--;}
    int getSupEsp(){return sup_esp;}
    bool puedeEntrarSup() {return (mod_act==0) and (sup_esp!=0);}
    bool puedeEntrarMod() {return (mod_act==0) and (sup_act==0) and
            (mod_esp!=0); }
};
#endif