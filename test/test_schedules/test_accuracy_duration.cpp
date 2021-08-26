
#include <Arduino.h>
#include <unity.h>

#include "scheduler.h"

#define TIMEOUT 1000
#define DURATION 1000
#define DELTA 20

static uint32_t start_time, end_time;
static void startCallback(void) { start_time = micros(); }
static void endCallback(void) { end_time = micros(); }

void test_accuracy_duration_inj1(void)
{
    initialiseSchedulers();
    setFuelSchedule1(TIMEOUT, DURATION);
    while(fuelSchedule1.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule1.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
}

void test_accuracy_duration_inj2(void)
{
    initialiseSchedulers();
    setFuelSchedule2(TIMEOUT, DURATION);
    while(fuelSchedule2.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule2.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
}

void test_accuracy_duration_inj3(void)
{
    initialiseSchedulers();
    setFuelSchedule3(TIMEOUT, DURATION);
    while(fuelSchedule3.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule3.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
}

void test_accuracy_duration_inj4(void)
{
    initialiseSchedulers();
    setFuelSchedule4(TIMEOUT, DURATION);
    while(fuelSchedule4.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule4.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
}

void test_accuracy_duration_inj5(void)
{
#if INJ_CHANNELS >= 5
    initialiseSchedulers();
    setFuelSchedule5(TIMEOUT, DURATION);
    while(fuelSchedule5.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule5.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
#endif
}

void test_accuracy_duration_inj6(void)
{
#if INJ_CHANNELS >= 6
    initialiseSchedulers();
    setFuelSchedule6(TIMEOUT, DURATION);
    while(fuelSchedule6.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule6.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
#endif
}

void test_accuracy_duration_inj7(void)
{
#if INJ_CHANNELS >= 7
    initialiseSchedulers();
    setFuelSchedule7(TIMEOUT, DURATION);
    while(fuelSchedule7.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule7.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
#endif
}

void test_accuracy_duration_inj8(void)
{
#if INJ_CHANNELS >= 8
    initialiseSchedulers();
    setFuelSchedule8(TIMEOUT, DURATION);
    while(fuelSchedule8.Status == SCH_PENDING) /*Wait*/ ;
    start_time = micros();
    while(fuelSchedule8.Status == SCH_RUNNING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
#endif
}



void test_accuracy_duration_ign1(void)
{
#if IGN_CHANNELS >= 1
    initialiseSchedulers();
    setIgnitionSchedule1(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[0].Status == SCH_PENDING) || (ignitionSchedule[0].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, DURATION, end_time - start_time);
#endif
}

void test_accuracy_duration_ign2(void)
{
#if IGN_CHANNELS >= 2
    initialiseSchedulers();
    setIgnitionSchedule2(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[1].Status == SCH_PENDING) || (ignitionSchedule[1].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration_ign3(void)
{
#if IGN_CHANNELS >= 3
    initialiseSchedulers();
    setIgnitionSchedule3(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[2].Status == SCH_PENDING) || (ignitionSchedule[2].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration_ign4(void)
{
#if IGN_CHANNELS >= 4
    initialiseSchedulers();
    setIgnitionSchedule4(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[3].Status == SCH_PENDING) || (ignitionSchedule[3].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration_ign5(void)
{
#if IGN_CHANNELS >= 5
    initialiseSchedulers();
    setIgnitionSchedule5(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[4].Status == SCH_PENDING) || (ignitionSchedule[4].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration_ign6(void)
{
#if IGN_CHANNELS >= 6
    initialiseSchedulers();
    setIgnitionSchedule6(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[5].Status == SCH_PENDING) || (ignitionSchedule[5].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration_ign7(void)
{
#if IGN_CHANNELS >= 7
    initialiseSchedulers();
    setIgnitionSchedule7(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[6].Status == SCH_PENDING) || (ignitionSchedule[6].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration_ign8(void)
{
#if IGN_CHANNELS >= 8
    initialiseSchedulers();
    setIgnitionSchedule8(startCallback, TIMEOUT, DURATION, endCallback);
    while( (ignitionSchedule[7].Status == SCH_PENDING) || (ignitionSchedule[7].Status == SCH_RUNNING) ) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_duration(void)
{
    RUN_TEST(test_accuracy_duration_inj1);
    RUN_TEST(test_accuracy_duration_inj2);
    RUN_TEST(test_accuracy_duration_inj3);
    RUN_TEST(test_accuracy_duration_inj4);
    RUN_TEST(test_accuracy_duration_inj5);
    RUN_TEST(test_accuracy_duration_inj6);
    RUN_TEST(test_accuracy_duration_inj7);
    RUN_TEST(test_accuracy_duration_inj8);

    RUN_TEST(test_accuracy_duration_ign1);
    RUN_TEST(test_accuracy_duration_ign2);
    RUN_TEST(test_accuracy_duration_ign3);
    RUN_TEST(test_accuracy_duration_ign4);
    RUN_TEST(test_accuracy_duration_ign5);
    RUN_TEST(test_accuracy_duration_ign6);
    RUN_TEST(test_accuracy_duration_ign7);
    RUN_TEST(test_accuracy_duration_ign8);
}
