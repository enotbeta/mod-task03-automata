#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
    Automata machine = Automata();
    machine.on();
    machine.coin(13);
    machine.choise(2);
    States result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test2)
{
    Automata machine = Automata();
    machine.on();
    machine.choise(1);
    States result = machine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test3)
{
    Automata machine = Automata();
    machine.on();
    machine.coin(20);
    machine.choise(1);
    int result = machine.finish();
    EXPECT_EQ(10, result);
}

TEST(task, test4)
{
    Automata machine = Automata();
    machine.on();
    machine.coin(20);
    machine.coin(30);
    machine.choise(1);
    int result = machine.finish();
    EXPECT_EQ(40, result);
}