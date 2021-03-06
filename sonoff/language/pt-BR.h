/*
  pt-BR.h - localization for Portuguese - Brazil for Sonoff-Tasmota

  Copyright (C) 2018  Fabiano Bovo

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _LANGUAGE_PT_BR_H_
#define _LANGUAGE_PT_BR_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v5.13.0
\*********************************************************************/

//#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)

// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "pt"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "DomSegTerQuaQuiSexSab"
#define D_MONTH3LIST "JanFevMarAbrMaiJunJulAgoSepOutNovDez"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR ","

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Qualidade do Ar"
#define D_AP "Pondo de acesso"                    // Ponto de Acesso
#define D_AS "como"
#define D_AUTO "Auto"
#define D_BLINK "Pulsar"
#define D_BLINKOFF "Pulsar desligado"
#define D_BOOT_COUNT "Contagem de inicializa????o"
#define D_BRIGHTLIGHT "Brilho"
#define D_BUTTON "Bot??o"
#define D_BY "por"                    // Write by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CO2 "Di??xido de Carbono"
#define D_CODE "C??digo"                // Button code
#define D_COLDLIGHT "Luz Fria"
#define D_COMMAND "Comando"
#define D_CONNECTED "Ligado"
#define D_COUNT "Contagem"
#define D_COUNTER "Contador"
#define D_CURRENT "Corrente"          // As in Voltage and Current
#define D_DATA "Dados"
#define D_DARKLIGHT "Luz Escura"
#define D_DEBUG "Depurar"
#define D_DISABLED "Desabilitado"
#define D_DISTANCE "Dist??ncia"
#define D_DNS_SERVER "Servidor DNS"
#define D_DONE "Conclu??do"
#define D_DST_TIME "DST"
#define D_ECO2 "eCO2"
#define D_EMULATION "Emula????o"
#define D_ENABLED "Habilitado"
#define D_ERASE "Apagar"
#define D_ERROR "Erro"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Falha"
#define D_FALLBACK "Retornar"
#define D_FALLBACK_TOPIC "T??pico para retornar"
#define D_FALSE "Falso"
#define D_FILE "Arquivo"
#define D_FREE_MEMORY "Mem??ria Livre"
#define D_FREQUENCY "Frequency"
#define D_GAS "G??s"
#define D_GATEWAY "Gateway"
#define D_GROUP "Grupo"
#define D_HOST "Anfitri??o"
#define D_HOSTNAME "Nome do anfitri??o"
#define D_HUMIDITY "Umidade"
#define D_ILLUMINANCE "Lumin??ncia"
#define D_IMMEDIATE "Imediato"      // Button immediate
#define D_INDEX "??ndice"
#define D_INFO "Informa????o"
#define D_INFRARED "Infrared"
#define D_INITIALIZED "Inicializado"
#define D_IP_ADDRESS "Endere??o IP"
#define D_LIGHT "Luz"
#define D_LWT "LWT"
#define D_MODULE "M??dulo"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "multi-press??o"
#define D_NOISE "Ru??do"
#define D_NONE "Nenhum"
#define D_OFF "Desligado"
#define D_OFFLINE "Desconectado"
#define D_OK "Ok"
#define D_ON "Ligado"
#define D_ONLINE "Conectado"
#define D_PASSWORD "Senha"
#define D_PORT "Porta"
#define D_POWER_FACTOR "Fator de pot??ncia"
#define D_POWERUSAGE "Pot??ncia"
#define D_POWERUSAGE_ACTIVE "Active Power"
#define D_POWERUSAGE_APPARENT "Apparent Power"
#define D_POWERUSAGE_REACTIVE "Reactive Power"
#define D_PRESSURE "Press??o"
#define D_PRESSUREATSEALEVEL "Press??o ao n??vel do mar"
#define D_PROGRAM_FLASH_SIZE "Tamanho do programa na mem??ria"
#define D_PROGRAM_SIZE "Tamanho do programa"
#define D_PROJECT "Projeto"
#define D_RECEIVED "Recebido"
#define D_RESTART "Reiniciar"
#define D_RESTARTING "Reiniciando"
#define D_RESTART_REASON "Motivo do rein??cio"
#define D_RESTORE "Restaura????o"
#define D_RETAINED "Manter"
#define D_RULE "Regra"
#define D_SAVE "Salvar"
#define D_SENSOR "Sensor"
#define D_SSID "SSId"
#define D_START "Iniciar"
#define D_STD_TIME "STD"
#define D_STOP "Parar"
#define D_SUBNET_MASK "M??scara sub rede"
#define D_SUBSCRIBE_TO "Subescrever para"
#define D_SUCCESSFUL "Successo"
#define D_SUNRISE "Nascer do sol"
#define D_SUNSET "Por do sol"
#define D_TEMPERATURE "Temperatura"
#define D_TO "Para"
#define D_TOGGLE "Inverter"
#define D_TOPIC "T??pico"
#define D_TRANSMIT "Transmitir"
#define D_TRUE "Verdadeiro"
#define D_TVOC "TVOC"
#define D_UPGRADE "atualiza????o"
#define D_UPLOAD "Enviar"
#define D_UPTIME "Tempo de atividade"
#define D_USER "Usu??rio"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "??ndice UV"
#define D_UV_LEVEL "N??vel UV"
#define D_VERSION "Vers??o"
#define D_VOLTAGE "Voltagem"
#define D_WARMLIGHT "Luz quente"
#define D_WEB_SERVER "Servidor WEB"

// sonoff.ino
#define D_WARNING_MINIMAL_VERSION "AVISO esta vers??o n??o supporta configura????es persistentes"
#define D_LEVEL_10 "n??vel 1-0"
#define D_LEVEL_01 "n??vel 0-1"
#define D_SERIAL_LOGGING_DISABLED "Registro em serie desabilitado"
#define D_SYSLOG_LOGGING_REENABLED "Registro do Syslog reativado"

#define D_SET_BAUDRATE_TO "Ajuste da velocidade para"
#define D_RECEIVED_TOPIC "T??pico recebido"
#define D_DATA_SIZE "Tamanho de dados"
#define D_ANALOG_INPUT "Entrada anal??gica"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Loop bloqueado"
#define D_WPS_FAILED_WITH_STATUS "WPSconfig falha de estado"
#define D_ACTIVE_FOR_3_MINUTES "Ativo por 3 minutos"
#define D_FAILED_TO_START "Falha ao in??ciar"
#define D_PATCH_ISSUE_2186 "Quest??o 2186"
#define D_CONNECTING_TO_AP "Ligando ao PA"
#define D_IN_MODE "em modo"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "A liga????o falhou porque nenhum endere??o IP foi recebido"
#define D_CONNECT_FAILED_AP_NOT_REACHED "A liga????o falhou porque o PA n??o p??de ser alcan??ado"
#define D_CONNECT_FAILED_WRONG_PASSWORD "A liga????o falhou porque a senha est?? incorreta"
#define D_CONNECT_FAILED_AP_TIMEOUT "A liga????o falhou porque o tempo foi excedido"
#define D_ATTEMPTING_CONNECTION "Ligando..."
#define D_CHECKING_CONNECTION "Verificando liga????o..."
#define D_QUERY_DONE "Consulta finalizada. Servi??o MQTT n??o encontrado"
#define D_MQTT_SERVICE_FOUND "Servi??o MQTT encontrado em"
#define D_FOUND_AT "encontrado em"
#define D_SYSLOG_HOST_NOT_FOUND "Syslog anfitri??o n??o encontrado"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Guardado na flash em"
#define D_LOADED_FROM_FLASH_AT "Lido da flash em"
#define D_USE_DEFAULTS "Usar predefini????es"
#define D_ERASED_SECTOR "Apagar setores"

// webserver.ino
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "Firmware m??nimo - Atualizar por favor"
#define D_WEBSERVER_ACTIVE_ON "Servidor WEB ativo em"
#define D_WITH_IP_ADDRESS "com o endere??o IP"
#define D_WEBSERVER_STOPPED "Servidor WEB parou"
#define D_FILE_NOT_FOUND "Arquivo n??o encontrado"
#define D_REDIRECTED "Redirecionado para o portal ativo"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager configura o Ponto de Acesso e mant??m a esta????o"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager configura o Ponto de Acesso"
#define D_TRYING_TO_CONNECT "Conectar o dispositivo ?? rede"

#define D_RESTART_IN "Reinicia em"
#define D_SECONDS "segundos"
#define D_DEVICE_WILL_RESTART "O dispositivo ir?? reiniciar dentro de alguns segundos"
#define D_BUTTON_TOGGLE "Comandar"
#define D_CONFIGURATION "Configura????o"
#define D_INFORMATION "Informa????o"
#define D_FIRMWARE_UPGRADE "Atualiza????o de Firmware"
#define D_CONSOLE "Console"
#define D_CONFIRM_RESTART "Confirmar o reinicio"

#define D_CONFIGURE_MODULE "Configurar M??dulo"
#define D_CONFIGURE_WIFI "Configurar WiFi"
#define D_CONFIGURE_MQTT "Configurar MQTT"
#define D_CONFIGURE_DOMOTICZ "Configurar Domoticz"
#define D_CONFIGURE_LOGGING "Configurar Logging"
#define D_CONFIGURE_OTHER "Configurar outras op????es"
#define D_CONFIRM_RESET_CONFIGURATION "Confirmar limpeza de configura????o"
#define D_RESET_CONFIGURATION "Apagar configura????o"
#define D_BACKUP_CONFIGURATION "Salvar configura????o"
#define D_RESTORE_CONFIGURATION "Repor configura????o"
#define D_MAIN_MENU "Menu principal"

#define D_MODULE_PARAMETERS "Parametros do m??dulo"
#define D_MODULE_TYPE "Tipo de m??dulo"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Entrada serial"
#define D_SERIAL_OUT "Sa??da serial"

#define D_WIFI_PARAMETERS "Par??metros do wifi"
#define D_SCAN_FOR_WIFI_NETWORKS "Encontrar redes wifi"
#define D_SCAN_DONE "Busca finalizada"
#define D_NO_NETWORKS_FOUND "Sem redes"
#define D_REFRESH_TO_SCAN_AGAIN "Nova busca"
#define D_DUPLICATE_ACCESSPOINT "Ponto de Acesso duplicado"
#define D_SKIPPING_LOW_QUALITY "Ignorado devido ?? baixa qualidade do sinal"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "AP1 SSId"
#define D_AP1_PASSWORD "Senha AP1"
#define D_AP2_SSID "AP2 SSId"
#define D_AP2_PASSWORD "Senha AP2"

#define D_MQTT_PARAMETERS "Par??metros MQTT"
#define D_CLIENT "Cliente"
#define D_FULL_TOPIC "T??pico completo"

#define D_LOGGING_PARAMETERS "Par??metros Logging"
#define D_SERIAL_LOG_LEVEL "N??vel de registro serial"
#define D_WEB_LOG_LEVEL "N??vel de registro WEB"
#define D_SYS_LOG_LEVEL "N??vel de registro Syslog"
#define D_MORE_DEBUG "Depurar mais"
#define D_SYSLOG_HOST "Syslog anfitri??o"
#define D_SYSLOG_PORT "Porta Syslog"
#define D_TELEMETRY_PERIOD "Per??odo de telemetria"

#define D_OTHER_PARAMETERS "Outros par??metros"
#define D_WEB_ADMIN_PASSWORD "Senha de WEB Admin"
#define D_MQTT_ENABLE "MQTT habilitado"
#define D_FRIENDLY_NAME "Nome amig??vel"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "Dispositivo ??nico"
#define D_MULTI_DEVICE "M??ltiplos dispositivos"

#define D_SAVE_CONFIGURATION "Salvar configura????o"
#define D_CONFIGURATION_SAVED "Configura????o salva"
#define D_CONFIGURATION_RESET "Reinicializa????o da configura????o"

#define D_PROGRAM_VERSION "Vers??o do programa"
#define D_BUILD_DATE_AND_TIME "Data e Hora da constru????o"
#define D_CORE_AND_SDK_VERSION "Vers??o Core/SDK"
#define D_FLASH_WRITE_COUNT "Contagem de grava????o flash"
#define D_MAC_ADDRESS "Endere??o MAC"
#define D_MQTT_HOST "MQTT Servidor"
#define D_MQTT_PORT "MQTT Porta"
#define D_MQTT_CLIENT "MQTT Cliente"
#define D_MQTT_USER "MQTT Usu??rio"
#define D_MQTT_TOPIC "MQTT T??pico"
#define D_MQTT_GROUP_TOPIC "MQTT T??pico Grupo"
#define D_MQTT_FULL_TOPIC "MQTT T??pico Completo"
#define D_MDNS_DISCOVERY "Descobrir mDNS"
#define D_MDNS_ADVERTISE "Anunciar mDNS"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Flash Size"
#define D_FREE_PROGRAM_SPACE "Espa??o Livre Programa"

#define D_UPGRADE_BY_WEBSERVER "Atualizar pelo servidor WEB"
#define D_OTA_URL "OTA Url"
#define D_START_UPGRADE "Iniciar atualiza????o"
#define D_UPGRADE_BY_FILE_UPLOAD "Atualiza????o por arquivo local"
#define D_UPLOAD_STARTED "In??cio do envio"
#define D_UPGRADE_STARTED "Atualiza????o iniciada"
#define D_UPLOAD_DONE "Atualiza????o finalizada"
#define D_UPLOAD_ERR_1 "Nenhum arquivo selecionado"
#define D_UPLOAD_ERR_2 "N??o existe mem??ria dispon??vel"
#define D_UPLOAD_ERR_3 "Byte m??gico n??o ?? 0xE9"
#define D_UPLOAD_ERR_4 "O tamanho do programa ?? maior do que o tamanho da mem??ria"
#define D_UPLOAD_ERR_5 "Envio buffer miscompare"
#define D_UPLOAD_ERR_6 "Falha no envio. Habilitar logging 3"
#define D_UPLOAD_ERR_7 "Envio cancelado"
#define D_UPLOAD_ERR_8 "Arquivo inv??lido"
#define D_UPLOAD_ERR_9 "Arquivo muito grande"
#define D_UPLOAD_ERROR_CODE "C??digo de erro do envio"

#define D_ENTER_COMMAND "Inserir comando"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Habilitar weblog 2 se resposta esperada"
#define D_NEED_USER_AND_PASSWORD "Necess??rio user=<nome usu??rio>&password=<senha>"

// xdrv_00_mqtt.ino
#define D_FINGERPRINT "Verifique a impress??o digital TLS..."
#define D_TLS_CONNECT_FAILED_TO "TLS n??o conseguiu ligar"
#define D_RETRY_IN "Tentativa em"
#define D_VERIFIED "Verificado impress??o digital "
#define D_INSECURE "Liga????o insegura devido ?? impress??o digital inv??lida"
#define D_CONNECT_FAILED_TO "A liga????o falhou ao"

// xdrv_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast desabilitado"
#define D_MULTICAST_REJOINED "Multicast (re)ingressou"
#define D_MULTICAST_JOIN_FAILED "Multicast falha no reingresso"
#define D_FAILED_TO_SEND_RESPONSE "Falha no envio de reposta"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo evento b??sico"
#define D_WEMO_EVENT_SERVICE "WeMo evento de servi??o"
#define D_WEMO_META_SERVICE "WeMo servi??o meta"
#define D_WEMO_SETUP "WeMo configura????o"
#define D_RESPONSE_SENT "Resposta enviada"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Hue setup"
#define D_HUE_API_NOT_IMPLEMENTED "Hue API nao implementada"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST args"
#define D_3_RESPONSE_PACKETS_SENT "3 pacotes de resposta enviados"

// xdrv_05_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Par??metros Domoticz"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Chave idx"
#define D_DOMOTICZ_SWITCH_IDX "Interruptor idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Hum"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Hum,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Pot??ncia,Energia"
  #define D_DOMOTICZ_ILLUMINANCE "Lumin??ncia"
  #define D_DOMOTICZ_COUNT "Contagem/PM1"
  #define D_DOMOTICZ_VOLTAGE "Voltagem/PM2.5"
  #define D_DOMOTICZ_CURRENT "Corrente/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Qualidade do ar"
#define D_DOMOTICZ_UPDATE_TIMER "Tempo de atualiza????o"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configurar temporizador"
#define D_TIMER_PARAMETERS "Par??metros"
#define D_TIMER_ARM "Habilitar"
#define D_TIMER_TIME "Hor??rio"
#define D_TIMER_DAYS "Dias"
#define D_TIMER_REPEAT "Repetir"
#define D_TIMER_OUTPUT "Sa??da"
#define D_TIMER_ACTION "A????o"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configurar KNX"
#define D_KNX_PARAMETERS "Par??metros KNX"
#define D_KNX_GENERAL_CONFIG "Geral"
#define D_KNX_PHYSICAL_ADDRESS "Endere??o f??sico"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "(Deve ser ??nico na rede KNX)"
#define D_KNX_ENABLE "Habilitar KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Endere??o do grupo para enviar"
#define D_ADD "Adicionar"
#define D_DELETE "Remover"
#define D_REPLY "Responder"
#define D_KNX_GROUP_ADDRESS_TO_READ "Endere??o do grupo para receber"
#define D_LOG_KNX "KNX: "
#define D_RECEIVED_FROM "Recebido de"
#define D_KNX_COMMAND_WRITE "Escrever"
#define D_KNX_COMMAND_READ "Ler"
#define D_KNX_COMMAND_OTHER "Outros"
#define D_SENT_TO "Enviar para"
#define D_KNX_WARNING "O endere??o ( 0 / 0 / 0 ) ?? reservado e n??o pode ser usado."

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Consumo energ??tico de hoje"
#define D_ENERGY_YESTERDAY "Consumo energ??tico de ontem"
#define D_ENERGY_TOTAL "Consumo total de energia"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor ocupado"
#define D_SENSOR_CRC_ERROR "Erro sensor CRC"
#define D_SENSORS_FOUND "Sensores encontrados"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Fim do tempo de espera"
#define D_START_SIGNAL_LOW "Sinal de in??cio baixo"
#define D_START_SIGNAL_HIGH "Sinal de in??cio elevado"
#define D_PULSE "pulso"
#define D_CHECKSUM_FAILURE "Falha checksum"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Sensor n??o aceitou o comando ACK"
#define D_SHT1X_FOUND "SHT1X encontrado"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Part??culas"

// sonoff_template.h
#define D_SENSOR_NONE     "Nenhum"
#define D_SENSOR_DHT11    "DHT11"
#define D_SENSOR_AM2301   "AM2301"
#define D_SENSOR_SI7021   "SI7021"
#define D_SENSOR_DS18X20  "DS18x20"
#define D_SENSOR_I2C_SCL  "I2C SCL"
#define D_SENSOR_I2C_SDA  "I2C SDA"
#define D_SENSOR_WS2812   "WS2812"
#define D_SENSOR_IRSEND   "IRsend"
#define D_SENSOR_SWITCH   "Interruptor"   // Suffix "1"
#define D_SENSOR_BUTTON   "Bot??o"   // Suffix "1"
#define D_SENSOR_RELAY    "Rel??"    // Suffix "1i"
#define D_SENSOR_LED      "Led"      // Suffix "1i"
#define D_SENSOR_PWM      "PWM"      // Suffix "1"
#define D_SENSOR_COUNTER  "Contador"  // Suffix "1"
#define D_SENSOR_IRRECV   "IRrecv"
#define D_SENSOR_MHZ_RX   "MHZ Rx"
#define D_SENSOR_MHZ_TX   "MHZ Tx"
#define D_SENSOR_PZEM_RX  "PZEM Rx"
#define D_SENSOR_PZEM_TX  "PZEM Tx"
#define D_SENSOR_SAIR_RX  "SAir Rx"
#define D_SENSOR_SAIR_TX  "SAir Tx"
#define D_SENSOR_SPI_CS   "SPI CS"
#define D_SENSOR_SPI_DC   "SPI DC"
#define D_SENSOR_BACKLIGHT "Luz de fundo"
#define D_SENSOR_PMS5003  "PMS5003"
#define D_SENSOR_SDS0X1   "SDS0X1"
#define D_SENSOR_SBR_RX   "SerBr Rx"
#define D_SENSOR_SBR_TX   "SerBr Tx"
#define D_SENSOR_SR04_TRIG "SR04 Tri"
#define D_SENSOR_SR04_ECHO "SR04 Ech"
#define D_SENSOR_SDM120_TX "SDM120 Tx"
#define D_SENSOR_SDM120_RX "SDM120 Rx"

// Units
#define D_UNIT_AMPERE "A"
#define D_UNIT_CENTIMETER "cm"
#define D_UNIT_HERTZ "Hz"
#define D_UNIT_HOUR "H"
#define D_UNIT_KILOOHM "kOhm"
#define D_UNIT_KILOWATTHOUR "kWh"
#define D_UNIT_LUX "lx"
#define D_UNIT_MICROGRAM_PER_CUBIC_METER "ug/m3"
#define D_UNIT_MICROMETER "um"
#define D_UNIT_MICROSECOND "us"
#define D_UNIT_MILLIAMPERE "mA"
#define D_UNIT_MILLISECOND "ms"
#define D_UNIT_MINUTE "M"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "s"
#define D_UNIT_SECTORS "setores"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "W/h"

// Log message prefix
#define D_LOG_APPLICATION "APP: "  // Application
#define D_LOG_BRIDGE "BRG: "       // Bridge
#define D_LOG_CONFIG "CFG: "       // Settings
#define D_LOG_COMMAND "CMD: "      // Command
#define D_LOG_DEBUG "DBG: "        // Debug
#define D_LOG_DHT "DHT: "          // DHT sensor
#define D_LOG_DOMOTICZ "DOM: "     // Domoticz
#define D_LOG_DSB "DSB: "          // DS18xB20 sensor
#define D_LOG_HTTP "HTP: "         // HTTP webserver
#define D_LOG_I2C "I2C: "          // I2C
#define D_LOG_IRR "IRR: "          // Infra Red Received
#define D_LOG_LOG "LOG: "          // Logging
#define D_LOG_MODULE "MOD: "       // Module
#define D_LOG_MDNS "DNS: "         // mDNS
#define D_LOG_MQTT "MQT: "         // MQTT
#define D_LOG_OTHER "OTH: "        // Other
#define D_LOG_RESULT "RSL: "       // Result
#define D_LOG_RFR "RFR: "          // RF Received
#define D_LOG_SERIAL "SER: "       // Serial
#define D_LOG_SHT1 "SHT: "         // SHT1x sensor
#define D_LOG_UPLOAD "UPL: "       // Upload
#define D_LOG_UPNP "UPP: "         // UPnP
#define D_LOG_WIFI "WIF: "         // Wifi

#endif  // _LANGUAGE_PT_BR_H_
