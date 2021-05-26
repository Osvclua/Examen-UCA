#include "../Mq-sv/sv_mq.h"
#include "area.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    sv_mq modif("modificador");
    string nom="P"+to_string(getpid()),res;
    mpdu pido(llegaModif,nom), *rec;
    
    cout<<"Modificador "<<nom<<" pide entrar."<<endl;
    pedido.send(pido);
    rec=modif.receive();
    cout<<nom<<" en el tablero..."<<endl;
    cin>>res;
    pido.setHdr(saleModif);
    pedido.send(pido);
    cout<<"Modificaddor "<<nom<<" termina."<<endl;
}


