#include "Cliente.h"


using namespace std;

int main(){
    srand(time(0));
    Cliente cliente;
    cliente.GenerarPlaca();
    cliente.MostrarPlaca();

    return 0;
};