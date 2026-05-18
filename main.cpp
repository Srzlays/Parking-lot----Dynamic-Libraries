//---¡este-main-es-la-envoltura-para-convertir-el-codigo-en-DLL!
#include "Procesos.h"
#include "Cliente.h"
#include <windows.h>
#include <ctime>


using namespace std;

extern "C"{
    _declspec(dllexport) void EjecutarProcesos(){
        srand(time(0));
        Cliente cliente;
        Procesos procesos(cliente);
        procesos.Procesar();
    };
};


/*
int main(){
    srand(time(0));

    Cliente cliente;
    Procesos procesos(cliente);
    procesos.Procesar();
    return 0;
};
*/
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