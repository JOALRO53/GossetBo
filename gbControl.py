#!/usr/bin/python3.8
import tkinter
from tkinter import *
import paho.mqtt.client as mqtt
import struct

class gbControl():
    def __init__(self):
        self.estatboto = 0
        self.codi = "12345"
        self.armat = False

        #Ventana gràfica per encabir la resta de ginys
        root = tkinter.Tk()
        ancho, alto = root.winfo_screenheight(), root.winfo_screenwidth()
        root.title("Control de GossetBo")
        root.geometry("%dx%d+0+0" % (alto, ancho))

        #Etiqueta per a mostrar missatges
        self.etiqueta = Label(root, text='')
        self.etiqueta.pack()

        # Creació del objecte mqtt client paho del objecte ProbaConexio
        self.client = mqtt.Client()
        self.client.username_pw_set("xadnem", "(Babilon3_X)")
        self.client.connect("10.244.59.173", 1883, 60)

        #Assignació dels métodes de conexió i rebuda de missatges del objecte mqtt client
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message

        # Iniciar el procés del loop de treball del objecte mqtt
        self.client.loop_start()

        # Iniciar el procés de loop de la inteficie tkinter ( en un procés diferent al anterior )
        root.mainloop()

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

        if msg.topic == "EstatBoto":
            self.estatboto = int(msg.payload)
            if not self.armat and self.estatboto == 1:
                self.armat = True
                self.etiqueta.config(text = "Sistema activat")
            elif self.armat and self.estatboto == 0:
                self.etiqueta.config(text = "¡¡ WARNING !! ")
            #self.etiqueta.config(text = "Estat del botó: " + msg.payload.decode("utf-8")) #decode per a convertir de bytes a string
        elif msg.topic == "CodiEnviat":
            if msg.payload.decode("utf-8") == self.codi:
                self.etiqueta.config(text = "Sistema desactivat ")
                self.armat = False
            #self.etiqueta.config(text = "Codi : " + msg.payload.decode("utf-8"))

# Iniciar el programa
gbcontrol = gbControl()




# self.client.username_pw_set("joseantonio", "(Babilon3_X)")
##self.client.connect("192.168.1.75", 1883, 60)
