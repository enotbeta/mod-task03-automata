#pragma once
#include <string>

enum States
{
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata
{
    private:
        int cash;
        std::string* menu;
        int* prices;
        States state;
        void cook();    
        bool check(int _choice);
    
    public:
        Automata();
        void on();
        void off();
        void coin(int money);
        std::string etMenu();
        States getState();
        void choice(int choice);
        int cancel();
        int finish();
        
        ~Automata();
};
