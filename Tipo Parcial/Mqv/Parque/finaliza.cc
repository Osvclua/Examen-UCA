#include "../Mq-sv/sv_mq.h"
#include "atrac.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    mpdu chau(fin,"");
    pedido.send(chau);
    cout<<"Enviado el fin al control.";
}