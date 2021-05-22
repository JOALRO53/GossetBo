import paho.mqtt.client as mqtt

class GbMqtt(mqtt.Client):
    def __init__(self,llistaTopics):
        mqtt.Client.__init__(self)       
        self.llistaTopics = llistaTopics                
        self.connectat = False
        
    def establirUserPassword(self,user,pwd):
        self.username_pw_set(user, pwd)

    def connectarABroker(self,broker,port,timealive):
        self.connect(broker, port, timealive)
        
    def subscriureTopics(self):
        for topic in self.llistaTopics:
            self.subscribe(topic)

    

