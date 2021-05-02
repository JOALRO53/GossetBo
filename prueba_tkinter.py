import tkinter
from tkinter import *
import paho.mqtt.client as mqtt


class pruebaConexion():
    def __init__(self):
        self.root = tkinter.Tk()
        self.ancho, self.alto = self.root.winfo_screenheight(), self.root.winfo_screenwidth()
        self.root.geometry("%dx%d+0+0" % (self.alto, self.ancho))

        self.etiqueta = Label(self.root, text='')
        self.etiqueta.pack()

        self.client = mqtt.Client()
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.username_pw_set("joseantonio", "(Babilon3_X)")
        self.client.connect("192.168.1.75", 1883, 60)
        self.client.loop_start()

        self.root.mainloop()

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            print("Conectado")
            client.subscribe("hola")
        else:
            print(f"(Conexion fallida con codigo: {rc}")

    def on_message(self, client, userdata, msg):
        print(f"{msg.topic}{msg.payload}")
        self.etiqueta.config(text=msg.payload)


pruebaConexion = pruebaConexion()


