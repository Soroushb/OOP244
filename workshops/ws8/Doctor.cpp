/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 22/7/2020
WS8P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Doctor.h"

using namespace std;
namespace sdds {
	Doctor::Doctor(const char* type, double rate, int hours, bool spec) : Employee(rate, hours) {
		strcpy(m_type, type);
		m_specialist = spec;
	}

	double Doctor::getSalary(int workedHours) const {

		int extra = 0;
		double total = 0.00;

		if (workedHours > Employee::getMinWorkHours()) {
			
			extra = workedHours - Employee::getMinWorkHours();
			total = (Employee::getMinWorkHours() * Employee::getHourlyRate()) + extra * (Employee::getHourlyRate() * 1.5);
			
		}
		else {
			total = workedHours * Employee::getHourlyRate();
		}
		
		if (m_specialist == true) {
			total += 2000.00;
		}
		return total;
	}
	ostream& Doctor::display(ostream& os)const {
		os << "Doctor" << endl;;
		
		if (m_specialist == true)
		{
			os.width(16);
			os << "Type: " << m_type << " (specialist)" << endl;
		}	
		else {
			os.width(16);
			
			os << "Type: " << m_type << endl;
		}
		os.width(16);
		os << "Pay Rate: " << Employee::getHourlyRate() << endl;
		os.width(16);
		os << "Min Hours: " << Employee::getMinWorkHours() << endl;

		return os;
	}
}