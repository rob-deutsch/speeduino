#if defined(CORE_ESP32)
#include "globals.h"
#include "board_esp32.h"
#include "esp_bt_device.h"
#include <Ticker.h>
#include <freertos/xtensa_api.h>
#include "scheduler.h"
#include <driver/timer.h>

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
void h(XtExcFrame*);
void initBoard()
{
    xt_set_exception_handler(EXCCAUSE_DIVIDE_BY_ZERO, h);

    // Useful for diagnostics
    Serial0.begin(115200);
    Serial0.println("Began diagnostics port");
    oneMSTimer.attach(0.001, oneMSInterval);
    timer_config_t config = {
        .alarm_en = TIMER_ALARM_DIS,
        .counter_en = TIMER_START,
        .intr_type = TIMER_INTR_LEVEL,
        .counter_dir = TIMER_COUNT_UP,
        .auto_reload = TIMER_AUTORELOAD_DIS,
        .divider = 80
    };
    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_init(TIMER_GROUP_0, TIMER_1, &config);
    timer_init(TIMER_GROUP_1, TIMER_0, &config);
    timer_init(TIMER_GROUP_1, TIMER_1, &config);

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

void h(XtExcFrame* f) {
  // Set the return value to UINT_MAX as per
  // page 471 of Xtensa® Instruction Set Architecture Reference Manual
  // https://0x04.net/~mwk/doc/xtensa.pdf
  long address_of_rs_byte = f->pc + 1;
  long address_of_rs_word = address_of_rs_byte & 0xFFFFFFFC;
  uint32_t rs_word = *(uint32_t*)address_of_rs_word;
  uint8_t rs = 0xFF & (rs_word >> (8*(address_of_rs_byte-address_of_rs_word)));
  uint8_t r = 0xF & (rs >> 4);

  uint32_t value_of_result = UINT_MAX;
  switch (r) {
    case 0:
      f->a0 = value_of_result;
      break;
    case 1:
      f->a1 = value_of_result;
      break;
    case 2:
      f->a2 = value_of_result;
      break;
    case 3:
      f->a3 = value_of_result;
      break;
    case 4:
      f->a4 = value_of_result;
      break;
    case 5:
      f->a5 = value_of_result;
      break;
    case 6:
      f->a6 = value_of_result;
      break;
    case 7:
      f->a7 = value_of_result;
      break;
    case 8:
      f->a8 = value_of_result;
      break;
    case 9:
      f->a9 = value_of_result;
      break;
    case 10:
      f->a10 = value_of_result;
      break;
    case 11:
      f->a11 = value_of_result;
      break;
    case 12:
      f->a12 = value_of_result;
      break;
    case 13:
      f->a13 = value_of_result;
      break;
    case 14:
      f->a14 = value_of_result;
      break;
    case 15:
      f->a15 = value_of_result;
      break;
  }

  // Move past this instruction
  f->pc = f->pc+3;
}

#endif