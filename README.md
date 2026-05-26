## Parking Lot -- Dynamics Libraries.
![WIKI](https://github.com/Srzlays/Parking-lot----Dynamic-Libraries/wiki)
In this project, the simulation of a parking system will be implemented using dynamic libraries using the Python and C++ programming languages. 

## Requeriments
You need to install streamlit, it is recommended to install a virtual environment
1. Virtual enviroment in ubuntu 24.04. Move to path
```bash
python3 -m venv venv_enviroment
```
To activate enviroment
```bash
source venv/bin/activate
```
To deactivate enviroment
```bash
deactivate
```
2. Virtual enviromente in windows 11. Move to path
```bash
python -m venv venv_enviroment
```
to activate enviroment
```bash
.\venv\Scripts\Activate.ps1
```
to dectivate enviroment
```bash
.\venv\Scripts\Activate.ps1
```
3. Install streamlit and streamli_autorefresh.
In ubuntu 24.04
```bash
pip3 install streamlit
pip3 install streamlit_autorefresh
```
In windows 11
```bash
pip install streamlit
pip install streamlit_autorefresh
```

## Excution and Compilation
### From ubuntu 24.04
1. Generate the compiled .so libary
```bash
g++ -shared -f -fPIC Envolruta.cpp Procesos.cpp Cliente.cpp -o libprocesos.so
```
2. Generaare the servidor executable
```bash
g++ Server.cpp main_server.cpp -o server
```
3. Run server in terminal 1
```bash
./servidor
```
4. Run Cliente in terminal 2
```bash
python3 main.py
```
5. Run app in terminal 3
```bash
streamlit run app.py
```

### from windows 11
1. Generate the compiled .dll libary
```bash
g++ -shared -o procesos.dll Envoltura.cpp Procesos.cpp Cliente.cpp -lws2_32 -static -static-libgcc -static-libstdc++
```
2. Generaare the servidor.exe executable
```bash
g++ -o servidor.exe servidor_main.cpp Servidor.cpp -lws2_32 
```
3. Run server in terminal 1
```bash
.\servidor
```
4. Run Cliente in terminal 2
```bash
python .\main.py
```
5. Run app in terminal 3
```bash
streamlit run .\app.py
```

