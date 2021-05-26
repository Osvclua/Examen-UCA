#include "../Mq-sv/sv_mq.h"
#include "area.h"
#include <iostream>
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    sv_mq modif("modificador");
    sv_mq super("supervisor");
    cout<<"Borrando colas "<<pedido<<endl<<modif<<endl
        <<super<<endl;
    pedido.del();
    super.del();
    modif.del();
}