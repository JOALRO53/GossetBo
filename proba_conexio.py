#!/usr/bin/python3.8
import tkinter
from tkinter import *
import paho.mqtt.client as mqtt
import struct

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
        self.client.username_pw_set("xadnem", "(Babilon3_X)")
        self.client.connect("10.244.59.173", 1883, 60)
        """
        # Per a probar el sonoff ( pendent de posar usuari i password al broker de la rasp i reconfigurar sonoff )
        self.client2 = mqtt.Client()
        self.client2.username_pw_set("ecat", "clotClot")
        self.client2.connect("formacio.things.cat", 1883, 60)
        self.client2.on_connect = self.on_connect2
        self.client2.on_message = self.on_message2
        self.client2.loop_start()
        """
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
            client.subscribe("CodiEnviat")

            #client.publish("sonoff_yo","OFF")
            client.subscribe("sonoff_yo")
        else:
            print(f"(Conexió fallida amb codi: {rc}")

    def on_message(self, client, userdata, msg):
        """ Métode de gestió del event de rebuda de missatges pel objete mqtt"""
        print(f"{msg.topic}{msg.payload}")
        #self.etiqueta.config(text=msg.payload)
        if msg.topic == "EstatBoto":
            self.etiqueta.config(text = "Estat del botó: " + str(msg.payload))
        elif msg.topic == "CodiEnviat":
            self.etiqueta.config(text = "Codi : " + str(msg.payload))
    """
    def on_connect2(self, client, userdata, flags, rc):
        # Métode de conexió al broker mqtt 
        if rc == 0:
            print("Conectat formacio things")
            self.client2.subscribe("sonoff_yo")
            self.client2.publish("sonoff_yo","OFF")
        else:
            print(f"(Conexion fallida con codigo: {rc}")

    def on_message2(self, client, userdata, msg):
        # Métode de gestió del event de rebuda de missatges pel objete mqtt
        print("{0}  {1}".format(msg.topic,msg.payload))
        #self.etiqueta.config(text=msg.payload)
    """
# Iniciar el programa
proebaConexio = ProbaConexio()




# self.client.username_pw_set("joseantonio", "(Babilon3_X)")
##self.client.connect("192.168.1.75", 1883, 60)
