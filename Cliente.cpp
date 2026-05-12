#include "Cliente.h"

Cliente::Cliente(){
    placa = ""; 
};

string Cliente::GenerarPlaca(){
    placa = "";
    for (int i = 0; i < 3; i++){
        char letra = 'A' + rand() % 26;
        placa += letra;
    };
    for (int i = 0; i < 3; i++){
        char numero = '0' + rand() % 10;
        placa += numero;
    };

    placas.push_back(placa);

    return placa;
};

void Cliente::MostrarPlaca() {
    cout << "Placa: " << placa << endl;
};