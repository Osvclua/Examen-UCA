#include "../Mq-sv/sv_mq.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    sv_mq participante("participante");
    cout<<"Borrando "<<pedido <<endl<<participante<<endl;
    pedido.del();
    participante.del();
}