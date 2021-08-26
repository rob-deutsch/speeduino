#ifndef ESP32_H
#define ESP32_H
#if defined(CORE_ESP32)

#include "driver/ledc.h"
#include <soc/ledc_struct.h>

#if defined(NO_GLOBAL_SERIAL)
extern HardwareSerial Serial0;

#include "BluetoothSerial.h"
class SpeeduinoBTSerial: public BluetoothSerial
{
  public:
    bool begin(unsigned long baud);
    int availableForWrite(void);
  private:
};
extern SpeeduinoBTSerial Serial;
#endif

/*
***********************************************************************************************************
* General
*/
  #define PORT_TYPE uint32_t //Size of the port variables (Eg inj1_pin_port). Most systems use a byte, but SAMD21 and possibly others are a 32-bit unsigned int
  #define PINMASK_TYPE uint32_t
  #define BOARD_MAX_IO_PINS  40 //digital pins + analog channels + 1
  #define BOARD_MAX_DIGITAL_PINS 40 //Pretty sure this isn't right
  #define EEPROM_LIB_H <src/ESP32_EEPROM/src/EEPROM.h> //The name of the file that provides the EEPROM class
  #define micros_safe() micros() //timer5 method is not used on anything but AVR, the micros_safe() macro is simply an alias for the normal micros()
  void initBoard();
  uint16_t freeRam();
  void doSystemReset();
  void jumpToBootloader();

  #define COMPARE_TYPE uint32_t
  #define pinIsReserved(pin)  ( (((pin) >= 1) && ((pin) <= 3)) || (((pin) >= 6) && (pin <=12)) ) //Forbiden pins like USB

  #if !defined (A0)
    #define A0  36
    #define A1  39
    #define A2  32
    #define A3  33
    #define A4  34
    #define A5  35
    #define A6   4
    #define A7   0
    #define A8   2
    #define A9  15
    #define A10 13
    #define A11 12
    #define A12 14
    #define A13 27
    #define A14 25
    #define A15 26
  #endif

/*
***********************************************************************************************************
* Schedules
*/

  #define FUEL1_COUNTER LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define FUEL2_COUNTER LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define FUEL3_COUNTER LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define FUEL4_COUNTER LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt

  #define IGN1_COUNTER  LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define IGN2_COUNTER  LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define IGN3_COUNTER  LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define IGN4_COUNTER  LEDC.timer_group[LEDC_HIGH_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt

  #define FUEL1_COMPARE LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_0].duty.duty
  #define FUEL2_COMPARE LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_1].duty.duty
  #define FUEL3_COMPARE LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_2].duty.duty
  #define FUEL4_COMPARE LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_3].duty.duty

  #define IGN1_COMPARE  LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_4].duty.duty
  #define IGN2_COMPARE  LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_5].duty.duty
  #define IGN3_COMPARE  LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_6].duty.duty
  #define IGN4_COMPARE  LEDC.channel_group[LEDC_HIGH_SPEED_MODE].channel[LEDC_CHANNEL_7].duty.duty

  #define FUEL1_TIMER_ENABLE()
  #define FUEL2_TIMER_ENABLE()
  #define FUEL3_TIMER_ENABLE()
  #define FUEL4_TIMER_ENABLE()

  #define FUEL1_TIMER_DISABLE()
  #define FUEL2_TIMER_DISABLE()
  #define FUEL3_TIMER_DISABLE()
  #define FUEL4_TIMER_DISABLE()

  #define IGN1_TIMER_ENABLE() LEDC.int_clr.duty_chng_end_hsch4 = 1; LEDC.int_ena.duty_chng_end_hsch4 = 1;
  #define IGN2_TIMER_ENABLE()
  #define IGN3_TIMER_ENABLE()
  #define IGN4_TIMER_ENABLE()

  #define IGN1_TIMER_DISABLE() LEDC.int_ena.duty_chng_end_hsch4 = 0;
  #define IGN2_TIMER_DISABLE()
  #define IGN3_TIMER_DISABLE()
  #define IGN4_TIMER_DISABLE()

  
  #define MAX_TIMER_PERIOD 139808 //This is the maximum time, in uS, that the compare channels can run before overflowing. It is typically 65535 * <how long each tick represents>
  #define uS_TO_TIMER_COMPARE(uS) ((uS * 15) >> 5) //Converts a given number of uS into the required number of timer ticks until that time has passed.

/*
***********************************************************************************************************
* Auxilliaries
*/
  //macro functions for enabling and disabling timer interrupts for the boost and vvt functions
  #define ENABLE_BOOST_TIMER()
  #define DISABLE_BOOST_TIMER()

  #define ENABLE_VVT_TIMER()    
  #define DISABLE_VVT_TIMER()   

  #define BOOST_TIMER_COMPARE   LEDC.channel_group[LEDC_LOW_SPEED_MODE].channel[LEDC_CHANNEL_0].duty.duty
  #define BOOST_TIMER_COUNTER   LEDC.timer_group[LEDC_LOW_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define VVT_TIMER_COMPARE     LEDC.channel_group[LEDC_LOW_SPEED_MODE].channel[LEDC_CHANNEL_1].duty.duty
  #define VVT_TIMER_COUNTER     LEDC.timer_group[LEDC_LOW_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt

/*
***********************************************************************************************************
* Idle
*/
  //Same as above, but for the timer controlling PWM idle
  #define IDLE_COUNTER          LEDC.timer_group[LEDC_LOW_SPEED_MODE].timer[LEDC_TIMER_0].value.timer_cnt
  #define IDLE_COMPARE          LEDC.channel_group[LEDC_LOW_SPEED_MODE].channel[LEDC_CHANNEL_2].duty.duty

  #define IDLE_TIMER_ENABLE()
  #define IDLE_TIMER_DISABLE()

/*
***********************************************************************************************************
* CAN / Second serial
*/


#endif //CORE_TEMPLATE
#endif //TEMPLATE_H