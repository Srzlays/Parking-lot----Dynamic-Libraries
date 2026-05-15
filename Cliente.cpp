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

    if(placas.size()<10){
        placas.push_back(placa);
    };

    return placa;
};

void Cliente::EnviarPlaca(){
    if(placas.empty()){
        cout << "No hay placas disponible\n";
        return;
    };
    int indice = rand() % placas.size();
    string placaEnviada = placas[indice];
    placas_enviar.push_back(placaEnviada);
    placas.erase(placas.begin() + indice);

    cout << "\nPlaca enviada: " << placaEnviada << endl;

};

void Cliente::MostrarVectores(){
    cout << "n\nPLACA(" << placas.size() << "):\n";
    for (auto &p: placa){
        cout << p << endl;
    };

    cout << "n\nPLACA(" << placas_enviar.size() << "):\n";
    for (auto &p: placas_enviar){
        cout << p << endl;
    };
    
};

void Cliente::MostrarPlaca() {
    cout << "Placa: " << placa << endl;
};

vector<string>& Cliente::ObtenerPlacas(){
    return placas;
};
