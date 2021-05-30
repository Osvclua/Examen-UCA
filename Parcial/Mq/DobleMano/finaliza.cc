#include "../Mq-sv/sv_mq.h"
#include <unistd.h>
using namespace std;

int main(){
    sv_mq pedidos("pedidos");
    mpdu chau("FIN","");
    pedidos.send(chau);
}