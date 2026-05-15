#include "Procesos.h"
//#include "Cliente.h"
#include <windows.h>

Procesos::Procesos(Cliente &cliente) : cliente(cliente){

};

void Procesos::Procesar(){

    while (true){
        while (cliente.ObtenerPlacas().size() < 10){
            string nueva_placa = cliente.GenerarPlaca();

            cout << "Generada: " << nueva_placa << endl;
        };
        cliente.MostrarVectores();
        Sleep(5000);
        cliente.EnviarPlaca();

    };
};
