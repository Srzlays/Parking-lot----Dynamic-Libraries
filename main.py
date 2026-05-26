import ctypes
import platform

if platform.system() == "Windows":
    lib = ctypes.CDLL("./procesos.dll")
else:
    lib = ctypes.CDLL("./libprocesos.so")

lib.EjecutarProcesos()
