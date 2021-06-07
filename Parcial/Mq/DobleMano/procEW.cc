#include "../Mq-sv/sv_mq.h"
#include <unistd.h>
using namespace std;

int main(){
    sv_mq pedidos("pedidos");
    sv_mq e2w("e2w");
    string nom="E2W-"+to_string(getpid()),res;
    cout<<nom<<" comienza."<<endl;
    mpdu pedi("E2WLl",nom),*rta;
    pedidos.send(pedi);
    rta=e2w.receive();
    delete(rta);
    cout<<nom<<" en camino E-->W..."<<endl;
    cin>>res;
    pedi.setHdr("E2WSa");
    pedidos.send(pedi);
    cout<<nom<<" termina."<<endl;
}