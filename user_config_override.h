/*
  user_config_override.h - user configuration overrides my_user_config.h for Sonoff-Tasmota

  Copyright (C) 2019  Theo Arends

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

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is inlcuded
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *         ie2 : enable in file platformio.ini "build_flags = -Wl,-Tesp8266.flash.1m0.ld -DUSE_CONFIG_OVERRIDE"
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++         Aenderungen erst ab hier vornehmen.               +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ _MINIMAL_user_config_override.h                           +++
// +++ NoitaercX +++ 13.01.2019 16:00:00                         +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ Kommentare von mir werden durch '+++' gekennzeichnet.     +++
// +++ ALLES was hier NICHT geaendert werden soll,               +++
// +++ kann als Kommentar // oder /* */ auskommentiert werden    +++
// +++ und bleibt dann so, wie in der my_user_config.h definiert.+++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++                Abschnitt 1 (SECTION 1)                    +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++ Eigene WLAN-Einstellungen +++++++++++++++++++++++++++
#undef  STA_SSID1                           // [SSId1] Wifi SSID
#define STA_SSID1         ""                // "MeinRouter"
#undef  STA_PASS1                           // [Password1] Wifi password
#define STA_PASS1         ""                // "MeinPasswort"

// -- Project -------------------------------------
#undef  PROJECT                             // +++ Default Topic
#define PROJECT          "meinsonoff"       // PROJECT is used as the default topic delimiter

// +++ Eigene MQTT-Einstellungen +++++++++++++++++++++++++++
#undef  MQTT_USE                            // +++ mit '0' ist MQTT beim Start deaktiviert
#define MQTT_USE          0                 // [SetOption3] Select default MQTT use (0 = Off, 1 = On)
#undef  MQTT_HOST
#define MQTT_HOST         "192.168.x.x"     // [MqttHost] +++ MQTT-Host Einstellung
#undef  MQTT_PORT
#define MQTT_PORT         1883              // [MqttPort] +++ MQTT-Port Einstellung

// -- HTTP ----------------------------------------
#undef  FRIENDLY_NAME                       // +++ angezeigter Name des Geraetes
#define FRIENDLY_NAME     "MeinSonoff"      // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

// +++ Location -------- Orts-Einstellung ---------
// +++                     'Berlin'
#undef  LATITUDE
#define LATITUDE       52.520006   	      	// [Latitude]  +++ Breitengrad-Angabe fuer die Berechnung von Astro-Zeiten
#undef  LONGITUDE                         	
#define LONGITUDE      13.404954   	      	// [Longitude] +++ Laengengrad-Angabe fuer die Berechnung von Astro-Zeiten

// -- Application ---------------------------------
#undef  APP_TIMEZONE                               // +++ Zeitzone: 99 = Sommer-/Winterzeit
#define APP_TIMEZONE           99                  // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ Befehle in eckigen Klammern koennen direkt in der Tasmota Konsole oder               +++
// +++ per MQTT zur Abfrage bzw. Konfiguration eingegeben werden z.B. [SSId1]               +++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++ Spracheinstellung +++++++++++++++++++++++++++++++++++
#undef  MY_LANGUAGE
#define MY_LANGUAGE      de-DE                 // German in Germany

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++                Abschnitt 2 (SECTION 2)                                               +++
// +++ Falls die Funktion in der my_user_config.h aktiviert wurde mit #define               +++
// +++ dann kann sie hier deaktiviert werden                      mit #undef                +++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#undef USE_ENERGY_SENSOR                       // Disable energy sensors
#undef  USE_ARDUINO_OTA                        // Disable support for Arduino OTA
#undef  USE_WPS                                // Disable support for WPS as initial wifi configuration tool
#undef  USE_SMARTCONFIG                        // Disable support for Wifi SmartConfig as initial wifi configuration tool
#undef  USE_MQTT_TLS                           // Disable TLS support won't work as the MQTTHost is not set
//#undef  USE_CUSTOM                             // Disable Custom features

//#undef  USE_DOMOTICZ                           // Disable Domoticz (+6k code, +0.3k mem)
#undef  USE_HOME_ASSISTANT                     // Disable Home Assistant Discovery Support (+2k code)
#undef  USE_KNX                                // Disable KNX IP Protocol Support (+9.4k code, +3k7 mem)
  #undef  USE_KNX_WEB_MENU                     // Disable KNX WEB MENU (+8.3k code, +144 mem)

// -- Rules --------------------------------------- // +++ Achtung: dadurch kann die Verwendung von Rules deaktiviert werden
//#undef  USE_RULES                              // Disable support for rules (+4k4 code)

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ Sensoren +++                                                                         +++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// -- I2C sensors --------------------------------- // +++ I2C kann hier mit #undef USE_I2C komplett deaktiviert werden
//#undef  USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ OPTIONALE FIRMWARE KONFIGURATION                                                     +++
// +++ KEINE oder EINE auswaehlen                                                           +++
// +++ KEINE: entspricht den Einstellungen in my_user_config.h und den oben vorgenommenen.  +++
// +++ EINE:  die dann enthaltenen Features und Sensoren sind in 'RELEASENOTES.md'          +++
// +++        beschrieben, die Einstellungen von Abschnitt 2 werden dadurch ueberschrieben. +++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define BE_MINIMAL            // +++ 1. Tasmota sonoff-minimal: Minimal Firmware fuer OTA 
//#define USE_CLASSIC           // +++ 2. Tasmota sonoff-classic: mit WPS, SmartConfig und WifiManager
//#define USE_SENSORS           // +++ 3. Tasmota sonoff-sensors: mit den meisten Sensoren
//#define USE_BASIC             // +++ 5. Tasmota sonoff-basic:   OHNE Sensoren
//#define USE_DISPLAYS          // +++ 6. Tasmota sonoff-display: mit aktivierten Display Treibern

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ ENDE von Abschnitt 2 (SECTION 2)                                                     +++
// +++ Folgende Zeilen nicht aendern                                                        +++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif  // _USER_CONFIG_OVERRIDE_H_