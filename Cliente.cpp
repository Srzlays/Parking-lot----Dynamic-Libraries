#include "Cliente.h"

#include <ctime>
#include <cstdlib>
#include <algorithm>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

Cliente::Cliente() {
    placa = "";
}

string Cliente::GenerarPlaca() {

    do {

        placa = "";

        for (int i = 0; i < 3; i++) {

            char letra = 'A' + rand() % 26;

            placa += letra;
        }

        for (int i = 0; i < 3; i++) {

            char numero = '0' + rand() % 10;

            placa += numero;
        }

    } while (

        find(placas_fuera.begin(), placas_fuera.end(), placa) != placas_fuera.end()
    );

    placas_fuera.push_back(placa);

    placas_celdas[placa] = GenerarCelda();

    return placa;
}


string Cliente::GenerarCelda(){
    int numero = 1 + rand() % 15;
    return "A" + to_string(numero);
}

void Cliente::EnviarPlaca() {

    bool entrada;

    string placaEnviar;

    if (
        placas_fuera.empty() &&
        placas_dentro.empty()
    ) {

        cout << "No hay placas\n";

        return;
    }

    /*
      ¿Decide aleatoriamente: entrada o salida? parece que si
    */
    if (
        !placas_fuera.empty() &&
        (
            placas_dentro.empty() ||
            rand() % 2 == 0
        )
    ) {

        entrada = true;

        int indice = rand() % placas_fuera.size();

        placaEnviar = placas_fuera[indice];

        placas_dentro.push_back(placaEnviar);

        placas_fuera.erase(placas_fuera.begin() + indice);

    } else {

        entrada = false;

        int indice = rand() % placas_dentro.size();

        placaEnviar = placas_dentro[indice];

        placas_fuera.push_back(placaEnviar);

        placas_dentro.erase(placas_dentro.begin() + indice);
    }

    string celda = placas_celdas[placaEnviar];

    string mensaje = placaEnviar + "|" + celda;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr));

    send(sock, mensaje.c_str(), mensaje.size(), 0);

    if (entrada) {

        cout << "ENTRANDO: ";

    } else {

        cout << "SALIENDO: ";
    }

    cout << mensaje << endl;

    close(sock);
}


void Cliente::MostrarVectores() {

    cout << "\nFUERA ("
         << placas_fuera.size()
         << ")\n";

    for (auto &p : placas_fuera) {

        cout << p << endl;
    }

    cout << "\nDENTRO ("
         << placas_dentro.size()
         << ")\n";

    for (auto &p : placas_dentro) {

        cout << p << endl;
    }
}

vector<string>& Cliente::ObtenerPlacas() {

    return placas_fuera;
}

