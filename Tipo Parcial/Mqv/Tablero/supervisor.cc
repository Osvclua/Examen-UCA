#include "../Mq-sv/sv_mq.h"
#include "area.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    sv_mq superv("supervisor");
    string nom="P"+to_string(getpid()),res;
    mpdu pido(llegaSuper,nom), *rec;
    
    cout<<"Supervisor "<<nom<<" pide entrar."<<endl;
    pedido.send(pido);
    rec=superv.receive();
    cout<<nom<<" en el tablero..."<<endl;
    cin>>res;
    pido.setHdr(saleSuper);
    pedido.send(pido);
    cout<<"Supervisor "<<nom<<" termina."<<endl;
}
