import paho.mqtt.client as mqtt

class GbMqtt(mqtt.Client):
    def __init__(self,llistaTopics):
        mqtt.Client.__init__(self)
        # Objecte mqtt client
        #self.client = mqtt.Client()
        self.llistaTopics = llistaTopics
        # Assignació dels métodes de conexió i rebuda de missatges del objecte mqtt client
        #self.on_connect = self.quan_connectat
        #self.client.on_message = self.on_message
        self.connectat = False
        # Iniciar el procés del loop de treball del objecte mqtt
        #self.client.loop_forever()
        #self.client.loop_start()


    def establirUserPassword(self,user,pwd):
        self.username_pw_set(user, pwd)

    def connectarABroker(self,broker,port,timealive):
        self.connect(broker, port, timealive)

    """
    def quan_connectat(self, client, userdata, flags, rc):
        #  Métode de conexió al broker mqtt 
        if rc == 0:
            for topic in self.llistaTopics:
                self.subscribe(topic)
            self.connectat = True
            print("Connectat")
        else:
            print(f"(Conexió fallida amb codi: {rc}")
            self.connectat = False
    """

