/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/06/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SAIYAN_H // safeguards
#define SDDS_SAIYAN_H


namespace sdds {


    class Saiyan {

        char * m_name;
        int m_dob;
        int m_power;
        bool m_super;
        int m_level;

    public:

        Saiyan();
        Saiyan(const char* name, int birthYear, int power);
        void set(const char* name, int dob, int power, int level = 0 ,bool super = false);
        void empty(void);
        bool isValid() const;
        void display() const;
        bool fight(Saiyan& other);
        ~Saiyan();
    };


}

#endif