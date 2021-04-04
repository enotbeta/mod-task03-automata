#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
    Automata machine = Automata();
    machine.on();
    machine.coin(13);
    machine.choice(2);
    States result = machine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test2)
{
    Automata machine = Automata();
    machine.on();
    machine.choice(2);
    States result = machine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test3)
{
    Automata machine = Automata();
    machine.on();
    machine.coin(20);
    machine.choice(1);
    int result = machine.finish();
    EXPECT_EQ(10, result);
}
