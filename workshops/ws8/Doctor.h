/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 22/7/2020
WS8P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include <iostream>
#include "Employee.h"

namespace sdds {
	const int MAX_CHAR = 32;

	class Doctor : public Employee {
		char m_type[MAX_CHAR + 1];
		bool m_specialist;
	public: 
		Doctor(const char* type, double rate, int hours, bool specialist = false);
		virtual double getSalary(int workedHours) const;
		virtual std::ostream& display(std::ostream& os = std::cout) const;
	};
}
#endif // !SDDS_DOCTOR_H
