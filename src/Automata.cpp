#include "Automata.h"
#include <iostream>

Automata::Automata()
{
    cash = 0;
    menu = new std::string[3];
    menu[0] = "Coffee";
    menu[1] = "Tea";
    menu[2] = "Cola";
    prices = new int[3];
    prices[0] = 10;
    prices[1] = 20;
    prices[2] = 30;
    state = OFF;
}
void Automata::on()
{
    if(getState() == OFF)
    {
        state = WAIT;
        std::string checkmenu = etMenu();
    }
}
void Automata::off()
{
    if(getState() == WAIT)
    {
        state = OFF;
    }
}
void Automata::coin(int _cash)
{
    if(getState() == ACCEPT || getState() == WAIT)
    {
        if(getState() == WAIT)
            state = ACCEPT;
        cash += _cash;
    }
}
std::string Automata::etMenu()
{
    std::string clientsmenu ("Menu\n");
    for(int i = 0; i < 3; i++)
    {
        clientsmenu += "Beverage number " + std::to_string(i + 1) + " - " + menu[i] + ". Price - " + std::to_string(prices[i]) + "\n";

    }

    return clientsmenu;
}
States Automata::getState()
{
    return state;
}
void Automata::choice(int _choise)
{
    if(getState() == ACCEPT)
    {
        state = CHECK;
        if(_choise <= 3 && _choise >= 1 && check(_choise - 1))
        {
            cash -= prices[_choise - 1];
            cook();
        }
        else 
            cancel();
    }
}
bool Automata::check(int _choice)
{
    if(getState() == CHECK)
    {
        if(cash - prices[_choice] >= 0)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}
int Automata::cancel()
{
    if(getState() == ACCEPT || getState() == CHECK)
    {
        state = WAIT;
        int temp = cash;
        cash = 0;
        return temp;
    }
    else
        return 0;
}
void Automata::cook()
{
    if(getState() == CHECK)
    {
        state = COOK;
        if(cash == 0)
        {finish();}
    }
}
int Automata::finish()
{
    if(getState() == COOK)
    {
        state = WAIT;
        int temp = cash;
        cash = 0;
        return temp;
    }
    else
    {
        return 0;
    }
}
Automata::~Automata()
{
    delete[] menu;
    delete[] prices;
}
