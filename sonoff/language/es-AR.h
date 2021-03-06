/*
  es-AR.h - localization for Spanish - Argentina for Sonoff-Tasmota

  Copyright (C) 2018  Adrian Scillato

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

#ifndef _LANGUAGE_ES_AR_H_
#define _LANGUAGE_ES_AR_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v5.14.0
\*********************************************************************/

#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)

// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "es"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "DomLunMarMieJueVieSab"
#define D_MONTH3LIST "EneFebMarAbrMayJunJulAgoSepOctNovDic"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR ","

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Calidad del Aire"
#define D_AP "AP"                    // Access Point
#define D_AS "como"
#define D_AUTO "AUTO"
#define D_BLINK "Blink"
#define D_BLINKOFF "BlinkOff"
#define D_BOOT_COUNT "Conteo Reinicios"
#define D_BRIGHTLIGHT "Brillante"
#define D_BUTTON "Bot??n"
#define D_BY "por"                    // Written by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CO2 "CO2"
#define D_CODE "c??digo"                // Button code
#define D_COLDLIGHT "Fr??a"
#define D_COMMAND "Comando"
#define D_CONNECTED "Conectado"
#define D_COUNT "Conteo"
#define D_COUNTER "Contador"
#define D_CURRENT "Corriente"          // As in Voltage and Current
#define D_DATA "Datos"
#define D_DARKLIGHT "Oscura"
#define D_DEBUG "Debug"
#define D_DISABLED "Deshabilitado"
#define D_DISTANCE "Distancia"
#define D_DNS_SERVER "DNS Server"
#define D_DONE "Listo"
#define D_DST_TIME "DST"
#define D_ECO2 "eCO2"
#define D_EMULATION "Emulaci??n"
#define D_ENABLED "Habilitado"
#define D_ERASE "Borrar"
#define D_ERROR "Error"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Fall??"
#define D_FALLBACK "Fallback"
#define D_FALLBACK_TOPIC "FallbackTopic"
#define D_FALSE "Falso"
#define D_FILE "Archivo"
#define D_FREE_MEMORY "Memoria Libre"
#define D_FREQUENCY "Frecuencia"
#define D_GAS "Gas"
#define D_GATEWAY "Gateway"
#define D_GROUP "Grupo"
#define D_HOST "Host"
#define D_HOSTNAME "Hostname"
#define D_HUMIDITY "Humedad"
#define D_ILLUMINANCE "Luminancia"
#define D_IMMEDIATE "inmediato"      // Button immediate
#define D_INDEX "??ndice"
#define D_INFO "Informaci??n"
#define D_INFRARED "Infrarrojo"
#define D_INITIALIZED "Inicializado"
#define D_IP_ADDRESS "Direcci??n IP"
#define D_LIGHT "Luz"
#define D_LWT "LWT"
#define D_MODULE "M??dulo"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "multi-press"
#define D_NOISE "Ruido"
#define D_NONE "Ninguno"
#define D_OFF "Apagado"
#define D_OFFLINE "Offline"
#define D_OK "Ok"
#define D_ON "Encendido"
#define D_ONLINE "Online"
#define D_PASSWORD "Clave"
#define D_PORT "Puerto"
#define D_POWER_FACTOR "Factor de Potencia"
#define D_POWERUSAGE "Potencia"
#define D_POWERUSAGE_ACTIVE "Potencia Activa"
#define D_POWERUSAGE_APPARENT "Potencia Aparente"
#define D_POWERUSAGE_REACTIVE "Potencia Reactiva"
#define D_PRESSURE "Presi??n"
#define D_PRESSUREATSEALEVEL "Presi??n al nivel del mar"
#define D_PROGRAM_FLASH_SIZE "Tama??o de Flash de Programa"
#define D_PROGRAM_SIZE "Tama??o Programa"
#define D_PROJECT "Proyecto"
#define D_RECEIVED "Recibido"
#define D_RESTART "Reinicio"
#define D_RESTARTING "Reiniciando"
#define D_RESTART_REASON "Causa Reinicio"
#define D_RESTORE "Restauraci??n"
#define D_RETAINED "Grabado"
#define D_RULE "Regla"
#define D_SAVE "Grabar"
#define D_SENSOR "Sensor"
#define D_SSID "SSId"
#define D_START "Iniciar"
#define D_STD_TIME "STD"
#define D_STOP "Detener"
#define D_SUBNET_MASK "M??scara Subred"
#define D_SUBSCRIBE_TO "Suscribir a"
#define D_SUCCESSFUL "Exitosa"
#define D_SUNRISE "Salida del Sol"
#define D_SUNSET "Puesta del Sol"
#define D_TEMPERATURE "Temperatura"
#define D_TO "a"
#define D_TOGGLE "Conmutar"
#define D_TOPIC "Topic"
#define D_TRANSMIT "Transmitir"
#define D_TRUE "Verdadero"
#define D_TVOC "TVOC"
#define D_UPGRADE "Actualizaci??n"
#define D_UPLOAD "Carga"
#define D_UPTIME "Tiempo Encendido"
#define D_USER "Usuario"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "??ndice UV"
#define D_UV_LEVEL "Nivel UV"
#define D_VERSION "Versi??n"
#define D_VOLTAGE "Tensi??n"
#define D_WARMLIGHT "C??lida"
#define D_WEB_SERVER "Servidor Web"

// sonoff.ino
#define D_WARNING_MINIMAL_VERSION "Precauci??n, esta versi??n no salva los cambios"
#define D_LEVEL_10 "level 1-0"
#define D_LEVEL_01 "level 0-1"
#define D_SERIAL_LOGGING_DISABLED "Log serial deshabilitado"
#define D_SYSLOG_LOGGING_REENABLED "Syslog re-habilitado"

#define D_SET_BAUDRATE_TO "Baudrate a"
#define D_RECEIVED_TOPIC "Topic Recibido"
#define D_DATA_SIZE "Tama??o de Datos"
#define D_ANALOG_INPUT "Entrada Anal??gica"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Ciclo Bloqueado"
#define D_WPS_FAILED_WITH_STATUS "WPSconfig FALL?? con estado"
#define D_ACTIVE_FOR_3_MINUTES "activo por 3 minutos"
#define D_FAILED_TO_START "fall?? inicio"
#define D_PATCH_ISSUE_2186 "Patch issue 2186"
#define D_CONNECTING_TO_AP "Connectando a AP"
#define D_IN_MODE "en modo"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "Fall?? Conecci??n, Direcci??n IP no recibida"
#define D_CONNECT_FAILED_AP_NOT_REACHED "Fall?? Conecci??n, AP no pudo ser contactado"
#define D_CONNECT_FAILED_WRONG_PASSWORD "Fall?? Conecci??n, clave de AP incorrecta"
#define D_CONNECT_FAILED_AP_TIMEOUT "Fall?? Conecci??n, timeout de AP"
#define D_ATTEMPTING_CONNECTION "Intentando conectar..."
#define D_CHECKING_CONNECTION "Probando conecci??n..."
#define D_QUERY_DONE "Consulta lista. Servicio MQTT encontrado"
#define D_MQTT_SERVICE_FOUND "Servicio MQTT encontrado en"
#define D_FOUND_AT "encontrado en"
#define D_SYSLOG_HOST_NOT_FOUND "Syslog Host no encontrado"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Grabado a la flash en"
#define D_LOADED_FROM_FLASH_AT "Cargado desde flash en"
#define D_USE_DEFAULTS "Usar valores por defecto"
#define D_ERASED_SECTOR "Sector borrado"

// webserver.ino
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "Firmware M??NIMO - actualice por favor"
#define D_WEBSERVER_ACTIVE_ON "Servidor web activo en"
#define D_WITH_IP_ADDRESS "con direcci??n IP"
#define D_WEBSERVER_STOPPED "Servidor web detenido"
#define D_FILE_NOT_FOUND "Archivo No Encontrado"
#define D_REDIRECTED "Redireccinado al portal captivo"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager como AccessPoint y Estaci??n"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager como AccessPoint"
#define D_TRYING_TO_CONNECT "Intentado conectar dispositivo a la red"

#define D_RESTART_IN "Reinicio en"
#define D_SECONDS "segundos"
#define D_DEVICE_WILL_RESTART "El dispositivo se reiniciar?? en pocos segundos"
#define D_BUTTON_TOGGLE "Alternar ON/OFF"
#define D_CONFIGURATION "Configuraci??n"
#define D_INFORMATION "Informaci??n"
#define D_FIRMWARE_UPGRADE "Actualizaci??n Firmware"
#define D_CONSOLE "Consola"
#define D_CONFIRM_RESTART "Confirmar Reinicio"

#define D_CONFIGURE_MODULE "Configuraci??n del M??dulo"
#define D_CONFIGURE_WIFI "Configuraci??n WiFi"
#define D_CONFIGURE_MQTT "Configuraci??n MQTT"
#define D_CONFIGURE_DOMOTICZ "Configuraci??n Domoticz"
#define D_CONFIGURE_LOGGING "Configuraci??n Logging"
#define D_CONFIGURE_OTHER "Configuraci??n Extra"
#define D_CONFIRM_RESET_CONFIGURATION "Confirmar Reset Configuraci??n"
#define D_RESET_CONFIGURATION "Reset de Configuraci??n"
#define D_BACKUP_CONFIGURATION "Backup de Configuraci??n"
#define D_RESTORE_CONFIGURATION "Restaurar Configuraci??n"
#define D_MAIN_MENU "Men?? Principal"

#define D_MODULE_PARAMETERS "Par??metros del m??dulo"
#define D_MODULE_TYPE "Tipo m??dulo"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Serial In"
#define D_SERIAL_OUT "Serial Out"

#define D_WIFI_PARAMETERS "Par??metros Wifi"
#define D_SCAN_FOR_WIFI_NETWORKS "Buscar redes wifi"
#define D_SCAN_DONE "Busqueda finalizada"
#define D_NO_NETWORKS_FOUND "Ninguna red encontrada"
#define D_REFRESH_TO_SCAN_AGAIN "Recargar p??gina para buscar nuevamente"
#define D_DUPLICATE_ACCESSPOINT "AccessPoint duplicado"
#define D_SKIPPING_LOW_QUALITY "Ignorado debido a baja calidad"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "SSId AP1"
#define D_AP1_PASSWORD "Clave AP1"
#define D_AP2_SSID "SSId AP2"
#define D_AP2_PASSWORD "Clave AP2"

#define D_MQTT_PARAMETERS "Par??metros MQTT"
#define D_CLIENT "Cliente"
#define D_FULL_TOPIC "Full Topic"

#define D_LOGGING_PARAMETERS "Par??metros Logging"
#define D_SERIAL_LOG_LEVEL "Nivel de log Serial"
#define D_WEB_LOG_LEVEL "Nivel de log Web"
#define D_SYS_LOG_LEVEL "Nivel de Syslog"
#define D_MORE_DEBUG "Mas Debug"
#define D_SYSLOG_HOST "Host del Syslog"
#define D_SYSLOG_PORT "Puerto del Syslog"
#define D_TELEMETRY_PERIOD "Per??odo de Telemetr??a"

#define D_OTHER_PARAMETERS "Otros par??metros"
#define D_WEB_ADMIN_PASSWORD "Clave Administrador Web"
#define D_MQTT_ENABLE "Habilitar MQTT"
#define D_FRIENDLY_NAME "Nombre Amigable"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "dispositivo simple"
#define D_MULTI_DEVICE "dispositivo m??ltiple"

#define D_SAVE_CONFIGURATION "Grabar configuraci??n"
#define D_CONFIGURATION_SAVED "Configuraci??n grabada"
#define D_CONFIGURATION_RESET "Configuraci??n restablecida"

#define D_PROGRAM_VERSION "Versi??n del Programa"
#define D_BUILD_DATE_AND_TIME "Fecha y Hora de la Compilaci??n"
#define D_CORE_AND_SDK_VERSION "Versi??n Core/SDK"
#define D_FLASH_WRITE_COUNT "Contador de escritura en Flash"
#define D_MAC_ADDRESS "Direcci??n MAC"
#define D_MQTT_HOST "Host MQTT"
#define D_MQTT_PORT "Puerto MQTT"
#define D_MQTT_CLIENT "Cliente MQTT"
#define D_MQTT_USER "Usuario MQTT"
#define D_MQTT_TOPIC "Topic MQTT"
#define D_MQTT_GROUP_TOPIC "Group Topic MQTT"
#define D_MQTT_FULL_TOPIC "Full Topic MQTT"
#define D_MDNS_DISCOVERY "mDNS Discovery"
#define D_MDNS_ADVERTISE "mDNS Advertise"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Tama??o Flash"
#define D_FREE_PROGRAM_SPACE "Memoria de Programa Libre"

#define D_UPGRADE_BY_WEBSERVER "Actualizar por servidor web"
#define D_OTA_URL "OTA Url"
#define D_START_UPGRADE "Comenzar actualizaci??n"
#define D_UPGRADE_BY_FILE_UPLOAD "Actualizar cargando archivo bin"
#define D_UPLOAD_STARTED "Cargando archivo"
#define D_UPGRADE_STARTED "Actualizaci??n iniciada"
#define D_UPLOAD_DONE "Carga finalizada"
#define D_UPLOAD_ERR_1 "Ning??n archivo seleccionado"
#define D_UPLOAD_ERR_2 "Espacio insuficiente"
#define D_UPLOAD_ERR_3 "Magic byte no corresponde a 0xE9"
#define D_UPLOAD_ERR_4 "El tama??o de la memoria de programa es mayor que la de la flash"
#define D_UPLOAD_ERR_5 "Error de comparaci??n del buffer de carga"
#define D_UPLOAD_ERR_6 "Carga fallida. Habilitar logging 3"
#define D_UPLOAD_ERR_7 "Carga cancelada"
#define D_UPLOAD_ERR_8 "Archivo no v??lido"
#define D_UPLOAD_ERR_9 "Archivo muy grande"
#define D_UPLOAD_ERROR_CODE "C??digo de error de carga"

#define D_ENTER_COMMAND "Ingresar comando"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Habilitar weblog 2 si desea respuesta"
#define D_NEED_USER_AND_PASSWORD "Se necesita user=<username>&password=<password>"

// xdrv_00_mqtt.ino
#define D_FINGERPRINT "Verificar TLS fingerprint..."
#define D_TLS_CONNECT_FAILED_TO "Fall?? Conecci??n TLS a"
#define D_RETRY_IN "Reintentando"
#define D_VERIFIED "Verificado Fingerprint"
#define D_INSECURE "Conecci??n insegura por Fingerprint no v??lido"
#define D_CONNECT_FAILED_TO "Fall?? Conecci??n a"

// xdrv_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast deshabilitado"
#define D_MULTICAST_REJOINED "Multicast (re)conectado"
#define D_MULTICAST_JOIN_FAILED "Conecci??n Multicast fallida"
#define D_FAILED_TO_SEND_RESPONSE "Falla al enviar respuesta"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "Evento base de WeMo"
#define D_WEMO_EVENT_SERVICE "Evento de servicio de WeMo"
#define D_WEMO_META_SERVICE "Meta Servicio de WeMo"
#define D_WEMO_SETUP "Configuraci??n de WeMo"
#define D_RESPONSE_SENT "Respuesta enviada"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Configuraci??n Hue"
#define D_HUE_API_NOT_IMPLEMENTED "API de Hue no implementada"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST args"
#define D_3_RESPONSE_PACKETS_SENT "3 paquetes de respuesta enviados"

// xdrv_05_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Par??metros Domoticz"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Key idx"
#define D_DOMOTICZ_SWITCH_IDX "Switch idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Hum"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Hum,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Potencia,Energ??a"
  #define D_DOMOTICZ_ILLUMINANCE "Luminancia"
  #define D_DOMOTICZ_COUNT "Contador/PM1"
  #define D_DOMOTICZ_VOLTAGE "Voltaje/PM2,5"
  #define D_DOMOTICZ_CURRENT "Corriente/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Calidad del Aire"
#define D_DOMOTICZ_UPDATE_TIMER "Intervalo de refresco"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configuraci??n Temporizadores"
#define D_TIMER_PARAMETERS "Par??metros de Temporizadores"
#define D_TIMER_ARM "Activo"
#define D_TIMER_TIME "Hora"
#define D_TIMER_DAYS "D??as"
#define D_TIMER_REPEAT "Repetir"
#define D_TIMER_OUTPUT "Salida"
#define D_TIMER_ACTION "Estado"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configuraci??n de KNX"
#define D_KNX_PARAMETERS "Par??metros de KNX"
#define D_KNX_GENERAL_CONFIG "General"
#define D_KNX_PHYSICAL_ADDRESS "Direcci??n F??sica"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "( Debe ser ??nica en la red KNX )"
#define D_KNX_ENABLE "Habilitar KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Datos a Enviar a las Direcciones de Grupo"
#define D_ADD "Agregar"
#define D_DELETE "Eliminar"
#define D_REPLY "Responder"
#define D_KNX_GROUP_ADDRESS_TO_READ "Direcciones de Grupo para Recibir Datos"
#define D_LOG_KNX "KNX: "
#define D_RECEIVED_FROM "Recibido desde"
#define D_KNX_COMMAND_WRITE "Escribir"
#define D_KNX_COMMAND_READ "Leer"
#define D_KNX_COMMAND_OTHER "Otro"
#define D_SENT_TO "enviada a"
#define D_KNX_WARNING "La direcci??n de grupo ( 0 / 0 / 0 ) est?? reservada y no puede ser utilizada."

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Energ??a Hoy"
#define D_ENERGY_YESTERDAY "Energ??a Ayer"
#define D_ENERGY_TOTAL "Energ??a Total"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor ocupado"
#define D_SENSOR_CRC_ERROR "Error CRC del Sensor"
#define D_SENSORS_FOUND "Sensores encontrados"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Espera de timeout por"
#define D_START_SIGNAL_LOW "iniciar se??al baja"
#define D_START_SIGNAL_HIGH "iniciar se??al alta"
#define D_PULSE "pulso"
#define D_CHECKSUM_FAILURE "Checksum fallido"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Sensor no ha enviado el comando ACK"
#define D_SHT1X_FOUND "SHT1X encontrado"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Part??culas"

// sonoff_template.h
#define D_SENSOR_NONE     "Ninguno"
#define D_SENSOR_DHT11    "DHT11"
#define D_SENSOR_AM2301   "AM2301"
#define D_SENSOR_SI7021   "SI7021"
#define D_SENSOR_DS18X20  "DS18x20"
#define D_SENSOR_I2C_SCL  "I2C SCL"
#define D_SENSOR_I2C_SDA  "I2C SDA"
#define D_SENSOR_WS2812   "WS2812"
#define D_SENSOR_IRSEND   "IR TX"
#define D_SENSOR_SWITCH   "Llave"   // Suffix "1"
#define D_SENSOR_BUTTON   "Bot??n"   // Suffix "1"
#define D_SENSOR_RELAY    "Rel??"    // Suffix "1i"
#define D_SENSOR_LED      "Led"      // Suffix "1i"
#define D_SENSOR_PWM      "PWM"      // Suffix "1"
#define D_SENSOR_COUNTER  "Counter"  // Suffix "1"
#define D_SENSOR_IRRECV   "IR RX"
#define D_SENSOR_MHZ_RX   "MHZ Rx"
#define D_SENSOR_MHZ_TX   "MHZ Tx"
#define D_SENSOR_PZEM_RX  "PZEM Rx"
#define D_SENSOR_PZEM_TX  "PZEM Tx"
#define D_SENSOR_SAIR_RX  "SAir Rx"
#define D_SENSOR_SAIR_TX  "SAir Tx"
#define D_SENSOR_SPI_CS   "SPI CS"
#define D_SENSOR_SPI_DC   "SPI DC"
#define D_SENSOR_BACKLIGHT "BkLight"
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
#define D_UNIT_HOUR "Hr"
#define D_UNIT_KILOOHM "kOhm"
#define D_UNIT_KILOWATTHOUR "kWh"
#define D_UNIT_LUX "lx"
#define D_UNIT_MICROGRAM_PER_CUBIC_METER "ug/m3"
#define D_UNIT_MICROMETER "um"
#define D_UNIT_MICROSECOND "us"
#define D_UNIT_MILLIAMPERE "mA"
#define D_UNIT_MILLISECOND "ms"
#define D_UNIT_MINUTE "Min"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "seg"
#define D_UNIT_SECTORS "sectores"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "Wh"

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

#endif  // _LANGUAGE_ES_AR_H_
