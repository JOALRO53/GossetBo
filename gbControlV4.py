#!/usr/bin/python3.7
import tkinter
from tkinter import *
import paho.mqtt.client as mqtt
import struct
import os
import subprocess
#import gbCamera
import threading
import configparser

class gbControl():
    def __init__(self):
        self.config = configparser.ConfigParser()
        self.config.read('/home/xadnem/config.ini')
        self.estatboto = 0
        self.codi = self.config['GBCONTROL']['CODI']
        self.armat = False
        self.p = None
        self.p2 = None

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

        username = self.config['MQTT']['USER']
        pwd = self.config['MQTT']['PWD']
        broker = self.config['MQTT']['BROKER']
        port = int(self.config['MQTT']['PORT'])
        ta = int(self.config['MQTT']['KEEPALIVE'])
        self.client.username_pw_set(username,pwd)
        self.client.connect(broker, port, ta)
        #os.system("sudo chmod 777 /dev/vchiq")

        #Assignació dels métodes de conexió i rebuda de missatges del objecte mqtt client
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message

        # Iniciar el procés del loop de treball del objecte mqtt
        self.client.loop_start()

        # Iniciar el procés de loop de la inteficie tkinter ( en un procés diferent al anterior )
        root.mainloop()

    def on_connect(self, client, userdata, flags, rc):
        print("Linia 71")
        """ Métode de conexió al broker mqtt """
        if rc == 0:            
            subsboto = self.config['SUBCRIPTIONS']['BOTO']
            client.subscribe(subsboto)
            subenviamentcodi = self.config['SUBCRIPTIONS']['ENVIAMENTCODI']
            client.subscribe(subenviamentcodi)
            subsonoff = self.config['SUBCRIPTIONS']['SONOFF']
            client.subscribe(subsonoff)
            self.lbConexio.configure(bg = "Chartreuse",text = "Connectat")
        else:
            print(f"(Conexió fallida amb codi: {rc}")
            self.lbconexio.configure(bg = "Red",text = "Desconectat")

    def on_message(self, client, userdata, msg):
        """ Métode de gestió del event de rebuda de missatges pel objete mqtt"""
        filcamera = None        
        print(f"{msg.topic}{msg.payload}")
        estatboto = self.config['SUBCRIPTIONS']['BOTO']
        codienviat = self.config['SUBCRIPTIONS']['ENVIAMENTCODI']
        if msg.topic == estatboto:
            self.estatboto = int(msg.payload)
            if not self.armat and self.estatboto == 1:
                self.armat = True
                self.etiqueta.config(text = "Sistema activat")
            elif self.armat and self.estatboto == 0:
                self.etiqueta.config(text = "¡¡ WARNING !! ")
                os.system("sh probaBot/bot.sh")
                subsonoff = self.config['SUBCRIPTIONS']['SONOFF']
                client.publish(subsonoff,"ON")
                #Activar la camera i el servidor http en un altre process
                self.p2 = subprocess.Popen(['python3','gbCamera.py'])
                #Obrir el navegador per veure el contingut de la càmera
                self.p = subprocess.Popen(['chromium-browser','http://127.0.0.1:8000'])                
                #self.p = subprocess.Popen(['firefox','http://127.0.0.1:8000'])                
                self.armat = False
                #self.etiqueta.config(text = "Estat del botó: " + msg.payload.decode("utf-8")) #decode per a convertir de bytes a string
        elif msg.topic == codienviat:
            codiok = self.config['SUBCRIPTIONS']['CONFIRMACODI']
            sonoff = self.config['SUBCRIPTIONS']['SONOFF']
            if msg.payload.decode("utf-8") == self.codi:
                self.etiqueta.config(text = "Sistema desactivat ")
                client.publish(codiok,"Codi correcte")
                client.publish(sonoff,"OFF")                
                if self.p != None:
                    self.p.kill()
                if self.p2 != None:
                    self.p2.kill()
                self.armat = False                
            else:
                client.publish(codiok,"Codi incorrecte")

# Iniciar el programa
gbcontrol = gbControl()