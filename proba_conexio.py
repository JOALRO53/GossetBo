#!/usr/bin/python3.8
import tkinter
from tkinter import *
import paho.mqtt.client as mqtt


class ProbaConexio():
    def __init__(self):
        #Ventana gràfica per encabir la resta de ginys
        self.root = tkinter.Tk()
        self.ancho, self.alto = self.root.winfo_screenheight(), self.root.winfo_screenwidth()
        self.root.geometry("%dx%d+0+0" % (self.alto, self.ancho))
        #Etiqueta per a mostrar l'estat del botó trasmés per la placa
        self.etiqueta = Label(self.root, text='')
        self.etiqueta.pack()

        # Creació del objecte mqtt client paho del objecte ProbaConexio
        self.client = mqtt.Client()
        self.client.connect("10.244.59.173", 1883, 60)

        #Assignació dels métodes de conexió i rebuda de missatges del objecte mqtt client
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message

        # Iniciar el procés del loop de treball del objecte mqtt
        self.client.loop_start()
        # Iniciar el procés de loop de la inteficie tkinter ( en un procés diferent al anterior )
        self.root.mainloop()

    def on_connect(self, client, userdata, flags, rc):
        """ Métode de conexió al broker mqtt """
        if rc == 0:
            print("Conectat")
            client.subscribe("EstatBoto")
        else:
            print(f"(Conexion fallida con codigo: {rc}")

    def on_message(self, client, userdata, msg):
        """ Métode de gestió del event de rebuda de missatges pel objete mqtt"""
        print(f"{msg.topic}{msg.payload}")
        self.etiqueta.config(text=msg.payload)

# Iniciar el programa
proebaConexio = ProbaConexio()




# self.client.username_pw_set("joseantonio", "(Babilon3_X)")
##self.client.connect("192.168.1.75", 1883, 60)
