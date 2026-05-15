#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//---¡clase-parqueader!
class Cliente{
    private:
        string placa;
        vector <string> placas;
        vector <string> placas_enviar;
    public:
        Cliente();
        string GenerarPlaca();
        void EnviarPlaca();
        void MostrarVectores();
        void MostrarPlaca();
        vector<string>& ObtenerPlacas();
};
 
#endif

