#include "status.h"
#include <unistd.h>
using namespace std;
int main()
{ 
    sv_sem mutex("Mutex");
    sv_sem entraA("EntraA");
    sv_sem entraB("EntraB");
    status *estado;
    sv_shm area("Area_Estado");
    estado = reinterpret_cast<status *>(area.map(sizeof(status)));
    cout<<"Estado="<<*estado<<endl;
    cout<<mutex<<endl<<entraA<<endl<<entraB<<endl;
}