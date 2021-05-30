#include "../Mq-sv/sv_mq.h"
#include <unistd.h>
using namespace std;

int main(){
    sv_mq pedidos("pedidos");
    sv_mq e2w("e2w");
    sv_mq w2e("w2e");
    cout<<"Borrado"<<endl<<pedidos<<endl<<e2w<<endl<<w2e<<endl;
    pedidos.del();
    e2w.del();
    w2e.del();
}