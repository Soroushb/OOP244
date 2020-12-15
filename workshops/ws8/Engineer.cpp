/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 22/7/2020
WS8P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include "Engineer.h"

using namespace std;
namespace sdds {
	Engineer::Engineer(double rate, int level) : Employee(rate, 30){
		m_level = level;
	}
	double Engineer::getSalary(int workedHours) const {
		double total = 0.00;

		total = (workedHours * Employee::getHourlyRate()) + (m_level * 40.00);
		if (workedHours < Employee::getMinWorkHours()) {
			total -= (0.2 * total);
		}
		return total;
	}

	ostream& Engineer::display(ostream& os) const {
		
		os << "Engineer" << endl;
		os.width(20);
		os.setf(ios::right);
		os << "Level: " << m_level << endl;
		os.width(20);
		os << "Pay Rate: " << Employee::getHourlyRate() << endl;
		os.width(20);
		os << "Min Hours: " << Employee::getMinWorkHours() << endl;
		return os;
	}
}