#include "Procesos.h"
#include "Cliente.h"
#include <windows.h>



using namespace std;

int main(){
    srand(time(0));

    Cliente cliente;
    Procesos procesos(cliente);
    procesos.Procesar();
    return 0;
};

/*
int main(){
    srand(time(0));
    Cliente cliente;
    
    while (true){
        cliente.GenerarPlaca();
        cliente.MostrarPlaca();
    
        Sleep(5000);
    };
    
    return 0;
};
*/