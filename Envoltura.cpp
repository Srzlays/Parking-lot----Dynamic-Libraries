#include "Procesos.h"
#include <ctime>

#ifdef _WIN32
    #define EXPORT extern "C" __declspec(dllexport)
#else
    #define EXPORT extern "C" __attribute__((visibility("default")))
#endif

EXPORT void EjecutarProcesos() {

    srand(time(0));

    Cliente cliente;

    Procesos procesos(cliente);

    procesos.Procesar();
}

