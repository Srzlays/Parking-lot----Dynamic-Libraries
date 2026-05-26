#ifndef PROCESOS_H
#define PROCESOS_H

#include "Cliente.h"

class Procesos {

    private:
        Cliente &cliente;

    public:
        Procesos(Cliente &cliente);
        void Procesar();
};

#endif

