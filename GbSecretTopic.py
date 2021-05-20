import configparser

class GbSecretTopic:
    codi = username = pwd = broker = subsboto = subenviamentcodi = subsonoff = estatboto = codienviat =\
        codiok = sonoff = ""
    ruta = '/home/xadnem/config.ini'
    port = ta = 0

    @classmethod
    def establirSecrets (cls,):
        config = configparser.ConfigParser()
        config.read(GbSecretTopic.ruta)
        GbSecretTopic.codi = config['GBCONTROL']['CODI']
        GbSecretTopic.username = config['MQTT']['USER']
        GbSecretTopic.pwd = config['MQTT']['PWD']
        GbSecretTopic.broker = config['MQTT']['BROKER']
        GbSecretTopic.port = int(config['MQTT']['PORT'])
        GbSecretTopic.ta = int(config['MQTT']['KEEPALIVE'])
        GbSecretTopic.subsboto = config['SUBCRIPTIONS']['BOTO']
        GbSecretTopic.subenviamentcodi = config['SUBCRIPTIONS']['ENVIAMENTCODI']
        GbSecretTopic.subsonoff = config['SUBCRIPTIONS']['SONOFF']
        GbSecretTopic.estatboto = config['SUBCRIPTIONS']['BOTO']
        GbSecretTopic.codienviat = config['SUBCRIPTIONS']['ENVIAMENTCODI']
        GbSecretTopic.codiok = config['SUBCRIPTIONS']['CONFIRMACODI']
        GbSecretTopic.sonoff = config['SUBCRIPTIONS']['SONOFF']
        
    @classmethod
    def canviarCodi(cls,noucodi):        
        config = configparser.ConfigParser()
        config.read(GbSecretTopic.ruta)
        config.set('GBCONTROL', 'CODI', noucodi)        
        try:
            with open(GbSecretTopic.ruta, 'w') as configfile:
                    config.write(configfile)
            GbSecretTopic.codi = noucodi
        except Exception as e:
            print(str(e))
            return False      
        return True
                
        


