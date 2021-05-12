#!/usr/bin/python3.7
import tkinter
from tkinter import *
import paho.mqtt.client as mqtt
import struct
import os
import subprocess

class gbControl():
    def __init__(self):
        self.estatboto = 0
        self.codi = "12345"
        self.armat = False
        self.p = None

        fons = "SeaGreen"
        fontRotuls = ("Arial", 17, "underline")
        fontText = ("Arial",17)
        #Ventana gràfica per encabir la resta de ginys
        root = tkinter.Tk()
        alto, ancho = root.winfo_screenheight(), root.winfo_screenwidth()
        root.title("Control de GossetBo")
        #Definicio de fonts i colors
        root.geometry("%dx%d+0+0" % (ancho, alto))
        root.configure(bg=fons)

        #Etiqueta rotul de l'estat del sistema de control
        rotulControl = Label(root,text = 'Estat del sistema')
        rotulControl.configure(font = fontRotuls,bg = fons)
        rotulControl.place(x=100,y=150)

        #Etiqueta per a mostrar l'estat del sistema de control
        self.etiqueta = Label(root, text='Sistema desactivat')
        self.etiqueta.pack()
        self.etiqueta.place(x=90,y=190,height = "30",width = "200")
        self.etiqueta.configure(font=fontText)

        #Etiqueta per a mostrar l'estat de conexió
        self.lbConexio = Label(root,text = '')
        self.lbConexio.place(x = ancho-120,y = 30, height = "30",width = "100")        

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
            client.subscribe("sonoff_yo")
            self.lbConexio.configure(bg = "Chartreuse",text = "Connectat")
        else:
            print(f"(Conexió fallida amb codi: {rc}")
            self.lbconexio.configure(bg = "Red",text = "Desconectat")

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
                os.system("sh probaBot/bot.sh")
                client.publish("sonoff_yo","ON")                
                os.system("python3 Camera.py")                
                self.p = subprocess.Popen(['chromium-browser','http://127.0.0.1:8000'])                
                #self.etiqueta.config(text = "Estat del botó: " + msg.payload.decode("utf-8")) #decode per a convertir de bytes a string
        elif msg.topic == "CodiEnviat":
            if msg.payload.decode("utf-8") == self.codi:
                self.etiqueta.config(text = "Sistema desactivat ")
                client.publish("CodiCorrecte","Codi correcte")
                client.publish("sonoff_yo","OFF")
                if self.p != None:
                    self.p.kill()
                self.armat = False                
            else:
                client.publish("CodiCorrecte","Codi incorrecte")
                #self.etiqueta.config(text = "Codi : " + msg.payload.decode("utf-8"))

# Iniciar el programa
gbcontrol = gbControl()




# self.client.username_pw_set("joseantonio", "(Babilon3_X)")
##self.client.connect("192.168.1.75", 1883, 60)
