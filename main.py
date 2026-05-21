import ctypes

so = ctypes.CDLL("./libprocesos.so")

so.EjecutarProcesos()

'''
import ctypes

dll = ctypes.CDLL(r"./procesos.dll")

dll.EjecutarProcesos()
'''