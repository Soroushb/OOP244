/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 25/06/2020
WS5P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include <cstring>
#include "Engine.h"

namespace sdds {

	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;
    const int MAX_ENGINES = 10;

	class Ship {
	private:

		Engine m_engines[MAX_ENGINES];
		char m_type[TYPE_MAX_SIZE + 1];
		int m_engCnt;

	public:

		Ship();
		~Ship();
		Ship(const char* type, const Engine* engines, int size);
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		void emptyShips();
		double shipPower() const;
		
	};

	bool operator<(double power, const Ship& theShip);

}


#endif
