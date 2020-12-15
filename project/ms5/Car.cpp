/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 06/8/2020
MS5
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Car.h"
#include "Utils.h"


using namespace std;
namespace sdds {
	Car::Car() :Vehicle(), m_carWash(false) {};

	Car::Car(const char* licensePlate, const char* makeModel) :
		Vehicle(licensePlate, makeModel), m_carWash(false) {}

	std::istream& Car::read(std::istream& istr) {

		if (!isCsv()) {

			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			m_carWash = Utils::yes();
			
		}
		else {
			
			Vehicle::read(istr);
			istr >> m_carWash;
			istr.ignore(100, '\n');
		}
		return istr;
	}

	std::ostream& Car::write(std::ostream& ostr) const {

		if (isEmpty())
			ostr << "Invalid Car Object" << endl;
		else if (isCsv())
		{
			ostr << "C,";
			Vehicle::write(ostr);
			ostr << m_carWash << endl;
		}
		else {
			ostr << "Vehicle type: Car" << endl;

			Vehicle::write(ostr);

			if (isCsv()) {
				ostr << m_carWash << endl;
			}
			else {
				if (m_carWash == true)
					ostr << "With Carwash" << endl;
				else
					ostr << "Without Carwash" << endl;
			}
		}
		return ostr;

	}
}