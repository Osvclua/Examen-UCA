#include "../Mq-sv/sv_mq.h"
#include <unistd.h>
using namespace std;

void estado(int e2wEsp, int e2wAct, int w2eEsp, int w2eAct)
{
    cout << "e2wEsp=" << e2wEsp << ", e2wAct=" << e2wAct << endl
         << "w2eEsp=" << w2eEsp << ", w2eAct=" << w2eAct << endl;
}
void entran(int &esp1, int &act1, int &act2, string dir)
{
    if ((esp1 > 0) and ((act1 > 0) or (act2 == 0)))
    {
        sv_mq direccion(dir);
        mpdu siga("GO" + dir, "controlador");
        int n = esp1;
        for (int i = 0; i < n; i++)
        {
            cout <<"Enviado "<< siga<<endl;
            esp1--;act1++;
            direccion.send(siga);
        }
    }
}

int main()
{
    sv_mq pedidos("pedidos");
    cout << "Controlador" << endl
         << pedidos << endl;
    mpdu *pedi;
    int e2wEsp = 0, e2wAct = 0, w2eEsp = 0, w2eAct = 0;
    pedi = pedidos.receive();
    cout << "Recibido " << *pedi;
    string cdo = pedi->getHdr();
    while (cdo != "FIN")
    {
        if (cdo == "E2WLl")
            e2wEsp++;
        if (cdo == "E2WSa")
            e2wAct--;
        if (cdo == "W2ELl")
            w2eEsp++;
        if (cdo == "W2ESa")
            w2eAct--;
        estado(e2wEsp,e2wAct,w2eEsp,w2eAct);
        entran(e2wEsp, e2wAct, w2eAct, "e2w");
        entran(w2eEsp, w2eAct, e2wAct, "w2e");
        cout<<"Despues de operar"<<endl;
        estado(e2wEsp,e2wAct,w2eEsp,w2eAct);
        delete (pedi);
        pedi = pedidos.receive();
        cout << "Recibido " << *pedi;
        cdo = pedi->getHdr();
    }
    cout << "Controlador termina." << endl;
}