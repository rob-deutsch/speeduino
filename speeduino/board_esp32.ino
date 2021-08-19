#if defined(CORE_ESP32)
#include "globals.h"
#include "board_esp32.h"
#include "esp_bt_device.h"
#include <Ticker.h>

extern void oneMSInterval();

#if defined(NO_GLOBAL_SERIAL)
HardwareSerial Serial0(0);
SpeeduinoBTSerial Serial;

bool SpeeduinoBTSerial::begin(unsigned long baud)
{
    char name[] = "Speedy_000000";
    if (BluetoothSerial::begin("Speeduino_Loading")) {
        const uint8_t *addr = esp_bt_dev_get_address();
        sprintf(&name[7], "%02X", (uint8_t)addr[3]);
        sprintf(&(name[9]), "%02X", (uint8_t)addr[4]);
        sprintf(&(name[11]), "%02X", (uint8_t)addr[5]);
        return esp_bt_dev_set_device_name(name);
    }
    return false;
}
int SpeeduinoBTSerial::availableForWrite(void)
{
    return INT_MAX;
}
#endif

Ticker oneMSTimer;

void initBoard()
{
    // Useful for diagnostics
    Serial0.begin(115200);
    Serial0.println("Began diagnostics port");
    oneMSTimer.attach(0.001, oneMSInterval);
    /*
    ***********************************************************************************************************
    * General
    */

    /*
    ***********************************************************************************************************
    * Timers
    */

    /*
    ***********************************************************************************************************
    * Auxilliaries
    */

    /*
    ***********************************************************************************************************
    * Idle
    */

    /*
    ***********************************************************************************************************
    * Schedules
    */
}

uint16_t freeRam()
{
    return ESP.getFreeHeap();
}

void doSystemReset() { return; }
void jumpToBootloader() { return; }

#endif