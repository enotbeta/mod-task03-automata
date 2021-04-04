#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
    Automata machine = Automata();
    machine.on();
    machine.coin(13);
    machine.choice(2);
    States result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

