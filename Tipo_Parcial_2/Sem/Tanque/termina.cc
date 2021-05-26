#include "status.h"
#include <unistd.h>
using namespace std;
int main()
{
    sv_sem mutex("Mutex");
    sv_sem entraA("EntraA");
    sv_sem entraB("EntraB");
    sv_shm area("Area_Estado");
    cout<<"Borrado"<<endl<<mutex<<endl<<entraA<<endl<<entraB<<
        endl<<area<<endl;
    mutex.del();
    entraA.del();
    entraB.del();
    area.del();
}