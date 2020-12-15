/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 14/7/2020
WS7P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {
	private:
		double maxWeight;
		double currWeight;
	public:
		Truck(const char* plate, int year, double max, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream& in);


	};
	std::istream& operator>>(std::istream& in, Truck& truck);
	std::ostream& operator<<(std::ostream& out,const Truck& truck);
	
}

#endif