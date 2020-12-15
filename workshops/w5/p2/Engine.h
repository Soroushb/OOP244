/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 29/06/2020
WS5P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
    const int TYPE_MAX_SIZE = 30;

    class Engine {
        double m_size;
        char m_type[TYPE_MAX_SIZE + 1];
    public:
        Engine();
        ~Engine();
        Engine(const char*, double);
        double get() const;
        void display() const;
        void emptyEngines();
    };
}
#endif
