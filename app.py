import streamlit as st
import pandas as pd
import json
from streamlit_autorefresh import st_autorefresh

st.set_page_config(
    page_title="Parqueadero",
    layout="wide"
)

st.title("Parqueadero en Tiempo Real")

# refresca cada 2 segundos
st_autorefresh(interval=2000, key="datos")

try:

    with open("parqueadero.json", "r") as f:

        datos = json.load(f)

    df = pd.DataFrame(datos)

    st.dataframe(
        df,
        use_container_width=True
    )

except:

    st.warning("Esperando datos...")
