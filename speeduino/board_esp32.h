#ifndef ESP32_H
#define ESP32_H
#if defined(CORE_ESP32)

#include <soc/ledc_reg.h>


/*
***********************************************************************************************************
* General
*/
  #define PORT_TYPE uint32_t //Size of the port variables (Eg inj1_pin_port). Most systems use a byte, but SAMD21 and possibly others are a 32-bit unsigned int
  #define PINMASK_TYPE uint32_t
  #define BOARD_MAX_IO_PINS  52 //digital pins + analog channels + 1
  #define BOARD_MAX_DIGITAL_PINS 52 //Pretty sure this isn't right
  #define EEPROM_LIB_H <EEPROM.h> //The name of the file that provides the EEPROM class
  #define micros_safe() micros() //timer5 method is not used on anything but AVR, the micros_safe() macro is simply an alias for the normal micros()
  void initBoard();
  uint16_t freeRam();
  void doSystemReset();
  void jumpToBootloader();

  #define COMPARE_TYPE uint32_t
  #define pinIsReserved(pin)  ( ((pin) == 0) ) //Forbiden pins like USB

  #if !defined (A0)
    #define A0  0
    #define A1  1
    #define A2  2
    #define A3  3
    #define A4  4
    #define A5  5
    #define A6  6
    #define A7  7
    #define A8  8
    #define A9  9
  #endif

/*
***********************************************************************************************************
* Schedules
*/
  
  #define FUEL1_COUNTER (*(unsigned int *)LEDC_HSTIMER0_VALUE_REG)
  #define FUEL2_COUNTER (*(unsigned int *)LEDC_HSTIMER0_VALUE_REG)
  #define FUEL3_COUNTER (*(unsigned int *)LEDC_HSTIMER0_VALUE_REG)
  #define FUEL4_COUNTER (*(unsigned int *)LEDC_HSTIMER0_VALUE_REG)

  #define IGN1_COUNTER  (*(unsigned int *)LEDC_HSTIMER1_VALUE_REG)
  #define IGN2_COUNTER  (*(unsigned int *)LEDC_HSTIMER1_VALUE_REG)
  #define IGN3_COUNTER  (*(unsigned int *)LEDC_HSTIMER1_VALUE_REG)
  #define IGN4_COUNTER  (*(unsigned int *)LEDC_HSTIMER1_VALUE_REG)

  #define FUEL1_COMPARE (*(unsigned int *)LEDC_HSCH0_DUTY_REG)
  #define FUEL2_COMPARE (*(unsigned int *)LEDC_HSCH1_DUTY_REG)
  #define FUEL3_COMPARE (*(unsigned int *)LEDC_HSCH2_DUTY_REG)
  #define FUEL4_COMPARE (*(unsigned int *)LEDC_HSCH3_DUTY_REG)

  #define IGN1_COMPARE  (*(unsigned int *)LEDC_HSCH4_DUTY_REG)
  #define IGN2_COMPARE  (*(unsigned int *)LEDC_HSCH5_DUTY_REG)
  #define IGN3_COMPARE  (*(unsigned int *)LEDC_HSCH6_DUTY_REG)
  #define IGN4_COMPARE  (*(unsigned int *)LEDC_HSCH7_DUTY_REG)

  #define FUEL1_TIMER_ENABLE()
  #define FUEL2_TIMER_ENABLE()
  #define FUEL3_TIMER_ENABLE()
  #define FUEL4_TIMER_ENABLE()

  #define FUEL1_TIMER_DISABLE()
  #define FUEL2_TIMER_DISABLE()
  #define FUEL3_TIMER_DISABLE()
  #define FUEL4_TIMER_DISABLE()

  #define IGN1_TIMER_ENABLE()
  #define IGN2_TIMER_ENABLE()
  #define IGN3_TIMER_ENABLE()
  #define IGN4_TIMER_ENABLE()

  #define IGN1_TIMER_DISABLE()
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

  #define BOOST_TIMER_COMPARE   (*(unsigned int *)LEDC_LSCH0_DUTY_REG)
  #define BOOST_TIMER_COUNTER   (*(unsigned int *)LEDC_LSTIMER0_VALUE_REG)
  #define VVT_TIMER_COMPARE     (*(unsigned int *)LEDC_LSCH1_DUTY_REG)
  #define VVT_TIMER_COUNTER     (*(unsigned int *)LEDC_LSTIMER0_VALUE_REG)

/*
***********************************************************************************************************
* Idle
*/
  //Same as above, but for the timer controlling PWM idle
  #define IDLE_COUNTER          (*(unsigned int *)LEDC_LSTIMER0_VALUE_REG)
  #define IDLE_COMPARE          (*(unsigned int *)LEDC_LSCH2_DUTY_REG)

  #define IDLE_TIMER_ENABLE()
  #define IDLE_TIMER_DISABLE()

/*
***********************************************************************************************************
* CAN / Second serial
*/


#endif //CORE_TEMPLATE
#endif //TEMPLATE_H