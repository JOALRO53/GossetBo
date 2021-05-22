#!/usr/bin/python3.7

from GbSecretTopic import *
from GbGUI import GbGUI
from GbMqtt import GbMqtt
from os import system
import subprocess


class GbControl:
    def __ini__(self):
        self.armat = False
        self.estatboto = 0
        self.p = None
        self.p2 = None
        # Inicialització de la clase GbSecretTopic amb les dades dels topics , codi de desactivacio i ip's
        GbSecretTopic.establirSecrets()
        # Creació de objecte GbGUI
        self.gui = GbGUI()
        # Creacio del objecte GbMqtt subscrit als topic de control
        llistaTopics = [GbSecretTopic.subsboto, GbSecretTopic.subenviamentcodi, GbSecretTopic.subsonoff,
                        GbSecretTopic.codienviat ]
        self.mqttclient = GbMqtt(llistaTopics)
        self.mqttclient.establirUserPassword(GbSecretTopic.username,GbSecretTopic.pwd)
        self.mqttclient.connectarABroker(GbSecretTopic.broker,GbSecretTopic.port,GbSecretTopic.ta)
        self.mqttclient.on_message = self.on_message_rebut
        self.mqttclient.on_connect = self.quan_connectat
        if self.mqttclient.connectat:
            self.gui.lbConexio.configure(bg="Chartreuse", text="Connectat")
        else:
            self.gui.lbConexio.configure(bg="Red", text="Desconnectat")
        self.mqttclient.loop_start()
        self.gui.root.mainloop()


    def on_message_rebut (self, client, userdata, msg):
        """ Métode de gestió del event de rebuda de missatges pel objete mqtt"""
        print(f"{msg.topic}{msg.payload}")
        if msg.topic == GbSecretTopic.estatboto:
            self.estatboto = int(msg.payload)
            if not self.armat and self.estatboto == 1:
                self.armat = True
                self.gui.lbEstat.config(text="Sistema activat")
            elif self.armat and self.estatboto == 0:
                self.gui.lbEstat.config(text="¡¡ WARNING !! ")
                system("sh probaBot/bot.sh")
                self.mqttclient.publish(GbSecretTopic.subsonoff, "ON")

                # Activar la camera i el servidor http en un altre fil
                self.p = subprocess.Popen(['python3', 'gbCamera.py'])
                # Obrir el navegador per veure el contingut de la càmera
                self.p2 = subprocess.Popen(['chromium-browser', 'http://127.0.0.1:8000'])
                #self.p2 = subprocess.Popen(['firefox','http://127.0.0.1:8000'])
                self.armat = False
                # self.etiqueta.config(text = "Estat del botó: " + msg.payload.decode("utf-8")) #decode per a convertir de bytes a string
        elif msg.topic == GbSecretTopic.codienviat:
            if msg.payload.decode("utf-8") == GbSecretTopic.codi:
                self.gui.lbEstat.config(text="Sistema desactivat ")
                self.mqttclient.publish(GbSecretTopic.codiok, "Codi correcte")
                client.publish(GbSecretTopic.sonoff, "OFF")
                if self.p is not None:
                    self.p.kill()
                if self.p2 is not None:
                    self.p2.kill()
                self.armat = False
            else:
                client.publish(GbSecretTopic.codiok, "Codi incorrecte")



    def quan_connectat(self, client, userdata, flags, rc):
        #  Métode de conexió al broker mqtt
        if rc == 0:
            self.mqttclient.subscriureTopics()            
            self.mqttclient.connectat = True
            self.gui.lbConexio.configure(bg="Chartreuse", text="Connectat")
            print("Connectat")
        else:
            print(f"(Conexió fallida amb codi: {rc}")
            self.mqttclient.connectat = False
            self.gui.lbConexio.configure(bg="Red", text="No connectat")












gbcontrol = GbControl()
gbcontrol.__ini__()
