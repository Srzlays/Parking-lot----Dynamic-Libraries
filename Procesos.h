#ifndef PROCESOS_H
#define PROCESOS_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

#include "Cliente.h"

class Procesos{
    private:
        Cliente &cliente;
    public:
        Procesos(Cliente &cliente);
        void Procesar();
};



#endif