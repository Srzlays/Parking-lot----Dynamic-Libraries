#include "Procesos.h"
#include <unistd.h>

Procesos::Procesos(Cliente &cliente)
    : cliente(cliente) {
}

void Procesos::Procesar() {

    while (true) {
        /*
        while (
            cliente.ObtenerPlacas().size() < 10
        ) {

            string nueva_placa =
                cliente.GenerarPlaca();

            cout << "Generada: "
                 << nueva_placa
                 << endl;
        }
        */
        string nueva_placa = cliente.GenerarPlaca();

        cout << "Generada: " << nueva_placa << endl;
        //cliente.MostrarVectores();
        cliente.MostrarVectores();
        cliente.EnviarPlaca();
        usleep(5000000);

        //cliente.EnviarPlaca();
    }
}

