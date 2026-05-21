## Parking Lot -- Dynamics Libraries. (¡aun en construccion!)

In this project, the simulation of a parking system will be implemented using dynamic libraries using the Python and C++ programming languages. 

## Ejecución
1. Generar la librería compilada .so
```bash
g++ -shared -f
```
2. Generar el ejecutable server
```bash
g++ Server.cpp main_server.cpp -o server
```
3. Ejecutar el server en la terminal 1
```bash
./server
```
4. Ejecutar el cliente en la terminal 2
```bash
python3 main.py
```
5. Ejecutar la app en la terminal 3
```bash
streamlit run app.py
```



