Sourced from https://github.com/espressif/arduino-esp32/tree/de66c39f04880e3ae05501d7107762381561fc69/libraries/EEPROM

## EEPROM

EEPROM is deprecated.  For new applications on ESP32, use Preferences.  EEPROM is provided for backwards compatibility with existing Arduino applications.
EEPROM is implemented using a single blob within NVS, so it is a container within a container. As such, it is not going to be a high performance storage method.  Preferences will directly use nvs, and store each entry as a single object therein.
