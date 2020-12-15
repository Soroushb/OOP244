/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 22/7/2020
WS8P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include<iostream>
namespace sdds {

	class Employee {
	private:
		const int MIN_WORK_HOURS;
		double m_hourlyRate;
	protected:
		double getHourlyRate() const;
		int getMinWorkHours() const;
	public:
		Employee(double rate, int hours);
		virtual double getSalary(int workedHours) const = 0;
		virtual std::ostream& display(std::ostream& os = std::cout) const = 0;
		virtual ~Employee();
	};

	std::ostream& operator<<(std::ostream& out, const Employee& emp);
}
#endif 

