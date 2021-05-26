#include "../Mq-sv/sv_mq.h"
#include "area.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    sv_mq modif("modificador");
    sv_mq super("supervisor");
    mpdu *rec, adentro(entra, "");
    estado stat;
    cout << "Control," << pedido << endl
         << modif << endl
         << super << endl;
    rec = pedido.receive();
    cout << "Pedido recibido " << *rec << endl;
    string pido = rec->getHdr();
    while (pido != fin)
    {
        if (pido == llegaSuper)
            stat.llegaSup();
        if (pido == llegaModif)
            stat.llegaMod();
        if (pido == saleSuper)
            stat.saleSup();
        if (pido == saleModif)
            stat.saleMod();
        if (stat.puedeEntrarSup())
        {

            int cant = stat.getSupEsp();
            cout << "Entran " << cant << " Supervisor(es)" << endl;
            for (int i = 0; i < cant; i++)
            {
                super.send(adentro);
                stat.entraSup();
            }
        }
        if (stat.puedeEntrarMod())
        {
            stat.entraMod();
            cout << "Entra un Modificador" << endl;
            modif.send(adentro);
        }
        delete (rec);
        rec = pedido.receive();
        cout << "Pedido recibido " << *rec << endl;
        pido = rec->getHdr();
    }
    cout << "Control termina" << endl;
}
