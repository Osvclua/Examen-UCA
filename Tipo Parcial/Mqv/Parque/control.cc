#include "../Mq-sv/sv_mq.h"
#include "atrac.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    sv_mq participante("participante");
    mpdu sale, *rec;
    sale.setHdr(salePas);
    cout<<"Control "<<endl<<pedido<<endl<<participante<<endl;
    int cant=0;
    rec=pedido.receive();
    cout<<"Control. Recibido "<<*rec<<endl;
    while (rec->getHdr() != fin){
        cant=cant+1;
        cout<<"Recibido "<<rec<<" hay "<<cant<<" participantes."<<endl;
        delete(rec);
        if (cant ==3){
            cout<< "habilitando paseo."<<endl;
            for (int i=0; i<3;i++){
                participante.send(sale);
            }
            cant=0;
        }
         rec=pedido.receive();
    }
    cout<<"Control termina"<<endl;
}