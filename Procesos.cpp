#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif
#include "Procesos.h"

//#include <unistd.h>

Procesos::Procesos(Cliente &cliente)
    : cliente(cliente) {
}

void Procesos::Procesar() {

    while (true) {
        string nueva_placa = cliente.GenerarPlaca();

        cout << "Generada: " << nueva_placa << endl;
        //cliente.MostrarVectores();
        cliente.MostrarVectores();
        cliente.EnviarPlaca();
        //usleep(5000000);
#ifdef _WIN32
        Sleep(5000);
#else
        usleep(5000000);
#endif

        //cliente.EnviarPlaca();
    }
}


