#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif

#include "Servidor.h"

#include <algorithm>
#include <cstring>

//#include <sys/socket.h>
//#include <arpa/inet.h>
#include <unistd.h>

#include <fstream>
#include <ctime>

string Servidor::ObtenerHoraActual() {

    time_t ahora = time(0);

    tm *tiempo = localtime(&ahora);

    char buffer[10];

    strftime(
        buffer,
        sizeof(buffer),
        "%H:%M:%S",
        tiempo
    );

    return string(buffer);
}

void Servidor::GuardarJSON() {
    // Crear archivo de bloqueo
    ofstream lockFile("parqueadero.lock");
    lockFile.close();
    
    ofstream archivo("parqueadero.json");
    archivo << "[\n";
    
    for (size_t i = 0; i < parqueadero.size(); i++) {
        archivo << "  {\n";
        archivo << "    \"placa\": \"" << parqueadero[i].placa << "\",\n";
        archivo << "    \"celda\": \"" << parqueadero[i].celda << "\",\n";
        archivo << "    \"horaEntrada\": \"" << parqueadero[i].horaEntrada << "\",\n";
        archivo << "    \"horaSalida\": \"" << parqueadero[i].horaSalida << "\"\n";
        archivo << "  }";
        
        if (i < parqueadero.size() - 1) {
            archivo << ",";
        }
        archivo << "\n";
    }
    
    archivo << "]\n";
    archivo.close();
    
    remove("parqueadero.lock");
}



void Servidor::Iniciar() {


#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
#endif

    int servidor_fd, cliente_fd;

    sockaddr_in direccion;

    char buffer[1024] = {0};

    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);

    direccion.sin_family = AF_INET;

    direccion.sin_addr.s_addr = INADDR_ANY;

    direccion.sin_port = htons(8080);

    bind(servidor_fd, (sockaddr*)&direccion, sizeof(direccion));

    listen(servidor_fd, 3);

    cout << "Servidor iniciado\n";

    while (true) {

        cliente_fd =
            accept(
                servidor_fd,
                nullptr,
                nullptr
            );

        memset(buffer, 0, sizeof(buffer));

        //read(cliente_fd, buffer, 1024);

        //string placa(buffer);
        //string datos(buffer);
        //int bytesRecibidos = read(cliente_fd, buffer, 1024);
    #ifdef _WIN32
            int bytesRecibidos = recv(cliente_fd, buffer, 1024, 0);
    #else
            int bytesRecibidos = read(cliente_fd, buffer, 1024);
    #endif
        if (bytesRecibidos <= 0){
            cout << "Error al recibir datos\n";

    #ifdef _WIN32
            closesocket(cliente_fd);
    #else
            close(cliente_fd);
                //close(cliente_fd);
    #endif
            continue;
        }

        string datos(buffer, bytesRecibidos);

        
        size_t separador = datos.find("|");
        if(separador == string::npos){
            cout << "Formato incorrecto: " << datos << endl;

            close(cliente_fd);
            continue;
        }

        string placa = datos.substr(0, separador);

        string celda = datos.substr(separador + 1);


        cout << "\nRecibida: " << placa << endl;
        
        cout << "Celda: " << celda << endl;

        auto it = find_if(
            parqueadero.begin(),
            parqueadero.end(),
            [&](Vehiculo &v) {

              return v.placa == placa;
            }
          );

        if (it == parqueadero.end()) {

          Vehiculo v;
          v.placa = placa;
          v.celda = celda;
          v.horaEntrada = ObtenerHoraActual();
          v.horaSalida = "";
          parqueadero.push_back(v);
          GuardarJSON();
          cout << "ENTRO\n";
          cout << "Hora entrada: " << v.horaEntrada << endl;

        } else {

            it->horaSalida = ObtenerHoraActual();
            cout << "SALIO\n";
            cout << "Hora salida: " << it->horaSalida << endl;
            
            Vehiculo vehiculoSalida = *it;
            GuardarJSON();
            parqueadero.erase(it);
        }

        //close(cliente_fd);
        #ifdef _WIN32
            closesocket(cliente_fd);
        #else
            close(cliente_fd);
        #endif
    }

    //close(servidor_fd);
    #ifdef _WIN32
        closesocket(servidor_fd);
        WSACleanup();
    #else
        close(servidor_fd);
    #endif

}
