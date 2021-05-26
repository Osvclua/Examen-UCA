#include "../Mq-sv/sv_mq.h"
#include "area.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    sv_mq pedido("pedido");
    mpdu final(fin,"");
    pedido.send(final);
}