#include "../Mq-sv/sv_mq.h"
#include <unistd.h>
using namespace std;

int main(){
    sv_mq pedidos("pedidos");
    sv_mq e2w("w2e");
    string nom="W2E-"+to_string(getpid()),res;
    cout<<nom<<" comienza."<<endl;
    mpdu pedi("W2ELl",nom),*rta;
    pedidos.send(pedi);
    rta=e2w.receive();
    delete (rta);
    cout<<nom<<" en camino W-->E..."<<endl;
    cin>>res;
    pedi.setHdr("W2ESa");
    pedidos.send(pedi);
    cout<<nom<<" termina."<<endl;
}