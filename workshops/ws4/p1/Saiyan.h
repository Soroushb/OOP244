/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 17/06/2020
WS4P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SAIYAN_H // safeguards
#define SDDS_SAIYAN_H
  

namespace sdds {


    class Saiyan {
     
        char m_name[32];
        int m_dob;
        int m_power;
        bool m_super;

    public: 

        Saiyan();
        Saiyan(const char * name, int birthYear, int power);
        void set(const char* name, int dob, int power, bool super = false);
        bool isValid() const;
        void display() const;
        bool fight(const Saiyan& other) const;

    };


}



#endif