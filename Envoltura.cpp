#include "Procesos.h"

#include <ctime>

extern "C" {

__attribute__((visibility("default")))
void EjecutarProcesos() {

    srand(time(0));

    Cliente cliente;

    Procesos procesos(cliente);

    procesos.Procesar();
}

}

