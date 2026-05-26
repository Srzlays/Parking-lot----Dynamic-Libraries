import streamlit as st
import pandas as pd
import json
import os
from streamlit_autorefresh import st_autorefresh
import time

st.set_page_config(
    page_title="Parqueadero",
    layout="wide"
)

st.title("Parqueadero en Tiempo Real")

#---¡refresca-cada-2-segundos-el-estreamlit-para-que-se-actualice!
st_autorefresh(interval=2000, key="datos")

def leer_json_seguro():
    max_intentos = 3
    for intento in range(max_intentos):
        try:
            #---¡Esperar-si-hay-un-archivo-de-bloqueo¡
            #---¡esta-fue-una-sugerencia-de-la-IA-para-evitar-corupcion-del-JSON!
            while os.path.exists("parqueadero.lock"):
                time.sleep(0.1)
            
            with open("parqueadero.json", "r") as f:
                datos = json.load(f)
            
            if datos:  #---¡Solo-retornar-si-hay-datos!
                return datos
                
        except (json.JSONDecodeError, FileNotFoundError):
            time.sleep(0.2)
    
    return None

try:
    datos = leer_json_seguro()
    
    if datos:
        df = pd.DataFrame(datos)
        st.dataframe(df, use_container_width=True)
    else:
        st.warning("Esperando datos...")
        
except Exception as e:
    st.warning(f"Esperando datos... ({str(e)})")

