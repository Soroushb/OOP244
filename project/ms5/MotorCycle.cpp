/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 06/8/2020
MS5
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Motorcycle.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Motorcycle::Motorcycle():Vehicle(), m_hasSideCar(false){}
	Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel), m_hasSideCar(false){}

	istream& Motorcycle::read(istream& istr) {

		if (!isCsv()) {

			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			m_hasSideCar = Utils::yes();

		}
		else {

			Vehicle::read(istr);
			istr >> m_hasSideCar;
			istr.ignore(100, '\n');
		}
		return istr;
	}

	ostream& Motorcycle::write(ostream& ostr) const {

		if (isEmpty())
			ostr << "Invalid Motorcycle Object" << endl;
		else if (isCsv())
		{
			ostr << "M,";
			Vehicle::write(ostr);
			ostr << m_hasSideCar << endl;
		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;

			Vehicle::write(ostr);

			if (m_hasSideCar == true){
				ostr << "With Sidecar" << endl;
			}
		}
		return ostr;
	}
}
