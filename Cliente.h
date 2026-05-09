#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//---¡clase-parqueader!
class Cliente{
    private:
        string placa;
    public:
        Cliente();
        string GenerarPlaca();
        void MostrarPlaca();
};
 
#endif

