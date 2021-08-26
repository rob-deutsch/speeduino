
#include <Arduino.h>
#include <unity.h>

#include "scheduler.h"
#include "scheduledIO.h"

#define TIMEOUT 1000
#define DURATION 1000
#define DELTA 20

static uint32_t start_time, end_time;
static void startCallback(void) { end_time = micros(); }
static void endCallback(void) { /*Empty*/ }

void test_accuracy_timeout_inj1(void)
{
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule1(TIMEOUT, DURATION);
    while(fuelSchedule1.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_inj2(void)
{
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule2(TIMEOUT, DURATION);
    while(fuelSchedule2.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_inj3(void)
{
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule3(TIMEOUT, DURATION);
    while(fuelSchedule3.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_inj4(void)
{
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule4(TIMEOUT, DURATION);
    while(fuelSchedule4.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_inj5(void)
{
#if INJ_CHANNELS >= 5
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule5(TIMEOUT, DURATION);
    while(fuelSchedule5.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout_inj6(void)
{
#if INJ_CHANNELS >= 6
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule6(TIMEOUT, DURATION);
    while(fuelSchedule6.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout_inj7(void)
{
#if INJ_CHANNELS >= 7
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule7(TIMEOUT, DURATION);
    while(fuelSchedule7.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout_inj8(void)
{
#if INJ_CHANNELS >= 8
    initialiseSchedulers();
    start_time = micros();
    setFuelSchedule8(TIMEOUT, DURATION);
    while(fuelSchedule8.Status == SCH_PENDING) /*Wait*/ ;
    end_time = micros();
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}


void test_accuracy_timeout_ign1(void)
{
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule1(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[0].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_ign2(void)
{
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule2(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[1].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_ign3(void)
{
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule3(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[2].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_ign4(void)
{
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule4(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[3].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
}

void test_accuracy_timeout_ign5(void)
{
#if IGN_CHANNELS >= 5
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule5(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[4].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout_ign6(void)
{
#if INJ_CHANNELS >= 6
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule6(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[5].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout_ign7(void)
{
#if INJ_CHANNELS >= 7
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule7(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[6].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout_ign8(void)
{
#if INJ_CHANNELS >= 8
    initialiseSchedulers();
    start_time = micros();
    setIgnitionSchedule8(startCallback, TIMEOUT, DURATION, endCallback);
    while(ignitionSchedule[7].Status == SCH_PENDING) /*Wait*/ ;
    TEST_ASSERT_UINT32_WITHIN(DELTA, TIMEOUT, end_time - start_time);
#endif
}

void test_accuracy_timeout(void)
{
    RUN_TEST(test_accuracy_timeout_inj1);
    RUN_TEST(test_accuracy_timeout_inj2);
    RUN_TEST(test_accuracy_timeout_inj3);
    RUN_TEST(test_accuracy_timeout_inj4);
    RUN_TEST(test_accuracy_timeout_inj5);
    RUN_TEST(test_accuracy_timeout_inj6);
    RUN_TEST(test_accuracy_timeout_inj7);
    RUN_TEST(test_accuracy_timeout_inj8);

    RUN_TEST(test_accuracy_timeout_ign1);
    RUN_TEST(test_accuracy_timeout_ign2);
    RUN_TEST(test_accuracy_timeout_ign3);
    RUN_TEST(test_accuracy_timeout_ign4);
    RUN_TEST(test_accuracy_timeout_ign5);
    RUN_TEST(test_accuracy_timeout_ign6);
    RUN_TEST(test_accuracy_timeout_ign7);
    RUN_TEST(test_accuracy_timeout_ign8);
}
