#include<Foco.hpp>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"hola mundo"<<endl;
    Foco foco;
    foco.Encender();
    foco.Apagar();
    cout<<"EstadoFoco:"
    <<foco.LeerEstado()
    <<endl;
    return 0;
}
