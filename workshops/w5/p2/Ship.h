/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 29/06/2020
WS5P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H

#include "Engine.h"

namespace sdds
{
    const double MIN_STD_POWER = 90.111;
    const double MAX_STD_POWER = 99.999;
    const int MAX_ENGINE = 10;

    class Ship
    {
        int m_engCnt;
        char* m_type;
        Engine* m_engines;

    public:
        Ship();
        ~Ship();
        Ship(const char* type, const Engine* engines, int size);
        explicit operator bool() const;
        Ship& operator+=(Engine engine);
        bool operator<(double power) const;
        void display() const;
        void emptyShip();
        double shipPower() const;
        friend bool operator<(double power, const Ship& theShip);
    };

}
#endif