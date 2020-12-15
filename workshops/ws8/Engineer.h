/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 22/7/2020
WS8P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H
#include<iostream>
#include "Employee.h"

namespace sdds {
	class Engineer : public Employee {
		int m_level;
	public:
		Engineer(double rate, int level);
		virtual double getSalary(int workedHours) const;
		virtual std::ostream& display(std::ostream& os) const;
	};
}
#endif // !SDDS_ENGINEER_h
