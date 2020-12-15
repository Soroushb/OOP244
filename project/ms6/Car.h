/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 10/8/2020
MS6
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace sdds {
	class Car :
		public Vehicle {
		bool m_carWash;
	public:
		Car();
		Car(const char* licensePlate, const char* makeModel);
		Car(const Car&) = delete;
		void operator=(const Car&) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout) const;
	};

}

	