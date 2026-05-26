#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Vehiculo{
    string placa;
    string celda;
    string horaEntrada;
    string horaSalida;
};

class Servidor {

  private:
    vector<Vehiculo> parqueadero;
    void GuardarJSON();

  public:
    void Iniciar();
    string ObtenerHoraActual();
};

#endif
