#if defined(CORE_ESP32)
#include "globals.h"
#include "board_esp32.h"
#include <Ticker.h>

extern void oneMSInterval();

#if defined(NO_GLOBAL_SERIAL)
HardwareSerial Serial0(0);
SpeeduinoBTSerial Serial;

bool SpeeduinoBTSerial::begin(unsigned long baud)
{
    return BluetoothSerial::begin("SHOOP");
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