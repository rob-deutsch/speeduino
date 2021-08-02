
#include <Arduino.h>
#include <unity.h>

#include "scheduler.h"

#define TIMEOUT 1000
#define DURATION 1000

static void emptyCallback(void) {  }

void test_status_running_to_pending_inj1(void)
{
    initialiseSchedulers();
    setFuelSchedule1(TIMEOUT, DURATION);
    while(fuelSchedule1.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule1(2*TIMEOUT, DURATION);
    while(fuelSchedule1.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule1.Status);
}

void test_status_running_to_pending_inj2(void)
{
    initialiseSchedulers();
    setFuelSchedule2(TIMEOUT, DURATION);
    while(fuelSchedule2.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule2(2*TIMEOUT, DURATION);
    while(fuelSchedule2.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule2.Status);
}

void test_status_running_to_pending_inj3(void)
{
    initialiseSchedulers();
    setFuelSchedule3(TIMEOUT, DURATION);
    while(fuelSchedule3.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule3(2*TIMEOUT, DURATION);
    while(fuelSchedule3.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule3.Status);
}

void test_status_running_to_pending_inj4(void)
{
    initialiseSchedulers();
    setFuelSchedule4(TIMEOUT, DURATION);
    while(fuelSchedule4.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule4(2*TIMEOUT, DURATION);
    while(fuelSchedule4.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule4.Status);
}

void test_status_running_to_pending_inj5(void)
{
#if INJ_CHANNELS >= 5
    initialiseSchedulers();
    setFuelSchedule5(TIMEOUT, DURATION);
    while(fuelSchedule5.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule5(2*TIMEOUT, DURATION);
    while(fuelSchedule5.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule5.Status);
#endif
}

void test_status_running_to_pending_inj6(void)
{
#if INJ_CHANNELS >= 6
    initialiseSchedulers();
    setFuelSchedule6(TIMEOUT, DURATION);
    while(fuelSchedule6.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule6(2*TIMEOUT, DURATION);
    while(fuelSchedule6.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule6.Status);
#endif
}

void test_status_running_to_pending_inj7(void)
{
#if INJ_CHANNELS >= 7
    initialiseSchedulers();
    setFuelSchedule7(TIMEOUT, DURATION);
    while(fuelSchedule7.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule7(2*TIMEOUT, DURATION);
    while(fuelSchedule7.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule7.Status);
#endif
}

void test_status_running_to_pending_inj8(void)
{
#if INJ_CHANNELS >= 8
    initialiseSchedulers();
    setFuelSchedule8(TIMEOUT, DURATION);
    while(fuelSchedule8.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setFuelSchedule8(2*TIMEOUT, DURATION);
    while(fuelSchedule8.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, fuelSchedule8.Status);
#endif
}


void test_status_running_to_pending_ign1(void)
{
    initialiseSchedulers();
    setIgnitionSchedule1(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule1.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule1(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule1.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule1.Status);
}

void test_status_running_to_pending_ign2(void)
{
    initialiseSchedulers();
    setIgnitionSchedule2(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule2.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule2(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule2.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule2.Status);
}

void test_status_running_to_pending_ign3(void)
{
    initialiseSchedulers();
    setIgnitionSchedule3(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule3.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule3(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule3.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule3.Status);
}

void test_status_running_to_pending_ign4(void)
{
    initialiseSchedulers();
    setIgnitionSchedule4(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule4.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule4(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule4.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule4.Status);
}

void test_status_running_to_pending_ign5(void)
{
#if IGN_CHANNELS >= 5
    initialiseSchedulers();
    setIgnitionSchedule5(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule5.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule5(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule5.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule5.Status);
#endif
}

void test_status_running_to_pending_ign6(void)
{
#if INJ_CHANNELS >= 6
    initialiseSchedulers();
    setIgnitionSchedule6(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule6.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule6(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule6.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule6.Status);
#endif
}

void test_status_running_to_pending_ign7(void)
{
#if INJ_CHANNELS >= 7
    initialiseSchedulers();
    setIgnitionSchedule7(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule7.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule7(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule7.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule7.Status);
#endif
}

void test_status_running_to_pending_ign8(void)
{
#if INJ_CHANNELS >= 8
    initialiseSchedulers();
    setIgnitionSchedule8(emptyCallback, TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule8.Status == PENDING_SPEEDUINO) /*Wait*/ ;
    setIgnitionSchedule8(emptyCallback, 2*TIMEOUT, DURATION, emptyCallback);
    while(ignitionSchedule8.Status == RUNNING) /*Wait*/ ;
    TEST_ASSERT_EQUAL(PENDING_SPEEDUINO, ignitionSchedule8.Status);
#endif
}

void test_status_running_to_pending(void)
{
    RUN_TEST(test_status_running_to_pending_inj1);
    RUN_TEST(test_status_running_to_pending_inj2);
    RUN_TEST(test_status_running_to_pending_inj3);
    RUN_TEST(test_status_running_to_pending_inj4);
    RUN_TEST(test_status_running_to_pending_inj5);
    RUN_TEST(test_status_running_to_pending_inj6);
    RUN_TEST(test_status_running_to_pending_inj7);
    RUN_TEST(test_status_running_to_pending_inj8);

    RUN_TEST(test_status_running_to_pending_ign1);
    RUN_TEST(test_status_running_to_pending_ign2);
    RUN_TEST(test_status_running_to_pending_ign3);
    RUN_TEST(test_status_running_to_pending_ign4);
    RUN_TEST(test_status_running_to_pending_ign5);
    RUN_TEST(test_status_running_to_pending_ign6);
    RUN_TEST(test_status_running_to_pending_ign7);
    RUN_TEST(test_status_running_to_pending_ign8);
}
