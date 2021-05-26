#include "status.h"
#include <unistd.h>
using namespace std;
int main()
{ // 2 unidades de A por cada unidad de B
    sv_sem mutex("Mutex",1);
    sv_sem entraA("EntraA",0);
    sv_sem entraB("EntraB",0);
    status *estado;
    sv_shm area("Area_Estado");
    estado = reinterpret_cast<status *>(area.map(sizeof(status)));
    string nom = "A-" + to_string(getpid());
    cout<<nom<<" intenta entrar."<<endl;
    mutex.wait();
    estado->llegaA(); // se anota
    if ((estado->getProcB() > 0) and
        (estado->getProcA() > 1)) // puede entrar un grupo
    {
        estado->entraB(); // descuenta B
        estado->entraA(); // y a dos A's
        estado->entraA();
        entraB.post(); // abre las puertas
        entraA.post();
        entraA.post();
    }
    mutex.post();
    cout<<nom<<" en la vávula de entrada."<<endl;
    entraA.wait();
    cout<<nom<<" en el tanque t termina"<<endl;
}