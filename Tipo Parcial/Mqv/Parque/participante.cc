#include "../Mq-sv/sv_mq.h"
#include "atrac.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    
    string nom = "P"+to_string(getpid());
    cout<<"Llega el participante "<<nom<<endl;
    string res;
    sv_mq pedido("pedido");
    sv_mq participante("participante");
    mpdu pido("",nom), *rec;
    pido.setHdr(llegaPas);
    pedido.send(pido);
    rec = participante.receive();
    delete(rec);
    cout <<nom<< " en la Roller Coaster. String para bajar... "<<endl;
    cin>>res;
    cout << nom << " termina." << endl;
}
