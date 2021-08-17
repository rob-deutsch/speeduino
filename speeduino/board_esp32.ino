#if defined(CORE_ESP32)
#include "globals.h"

#if defined(NO_GLOBAL_SERIAL)
HardwareSerial Serial(0);
#endif

void initBoard()
{
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