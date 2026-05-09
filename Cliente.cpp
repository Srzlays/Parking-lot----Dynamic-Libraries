#include <iostream>
#include <cstring>
#include <string>
#include <ctime>

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

    return placa;
    
};

void Cliente::MostrarPlaca() {
    cout << "Placa: " << placa << endl;
}

int main(){
    srand(time(0));
    Cliente cliente;
    cliente.GenerarPlaca();
    cliente.MostrarPlaca();

    return 0;
};
 