/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 7/7/2020
WS6P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BASKET_H //safeguards
#define SDDS_BASKET_H

namespace sdds { //sdds namespace

    struct Fruit //fruit struct
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket { //Basket class
    private: //private members(data members)
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public: //public members(member functions)
        Basket(); //default constructor
        ~Basket(); //destructor
        Basket(Fruit* objects, int size, double price);//Custom constructor
        Basket(const Basket&);//copy constructor
        Basket& operator=(const Basket&);//copy assignment operator
        void setPrice(double price);//setter function
        operator bool() const;//conversion to bool
        Basket& operator+=(Fruit fruit);//overload +=
        friend std::ostream& operator<<(std::ostream& os, const Basket& basket);//overload <<
        void emptybasket(); //additional function, empties the object
    };
}


#endif