/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 22/7/2020
WS8P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Employee.h"

namespace sdds {
	Employee::Employee(double hRate, int hours) : MIN_WORK_HOURS(hours) {
		m_hourlyRate = hRate;
	}

	Employee::~Employee(){}

	double Employee::getHourlyRate() const {
		return m_hourlyRate;
	}

	int Employee::getMinWorkHours() const {
		return MIN_WORK_HOURS;
	}

	std::ostream& operator<<(std::ostream& out, const Employee& emp) {
		emp.display(out);
		return out;
	}
}