import ctypes

dll = ctypes.CDLL(r"./procesos.dll")

dll.EjecutarProcesos()
