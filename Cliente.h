#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Cliente {

    private:
        string placa;
        vector<string> placas_fuera;
        vector<string> placas_dentro;
        map<string, string> placas_celdas;

    public:
        Cliente();
        string GenerarPlaca();
        string GenerarCelda();
        void EnviarPlaca();
        void MostrarVectores();
        vector<string>& ObtenerPlacas();
};

#endif


