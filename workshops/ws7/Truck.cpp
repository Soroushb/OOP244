/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 14/7/2020
WS7P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include<iomanip>
#include"MotorVehicle.h"
#include"Truck.h"

using namespace std;
 
namespace sdds {

	
	Truck::Truck(const char* plate, int year, double max, const char* address) : MotorVehicle(plate,year){
		maxWeight = max;
		currWeight = 0;
		MotorVehicle::moveTo(address);
	}
	bool Truck::addCargo(double cargo){
		bool valid;
		if (currWeight >= maxWeight)
			valid =  false;
		else {
			if (currWeight + cargo >= maxWeight) {
				currWeight = maxWeight;
			}
			else {
				currWeight += cargo;
			}
			valid = true;
		}

		return valid;
		
	}
	bool Truck::unloadCargo() {
		bool unload = currWeight > 0;
		currWeight = 0;
		return unload;
	}
	ostream& Truck::write(std::ostream& out) const{
		MotorVehicle::write(out);
		out << " | " << currWeight << "/" << maxWeight;
		return out;
	}
	istream& Truck::read(std::istream& in){
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> maxWeight;
		cout << "Cargo: ";
		in >> currWeight;
		return in;
	}
	ostream& operator<<(std::ostream& os,  const Truck& truck){
		return truck.write(os);
	}
	istream& operator>>(std::istream& in, Truck& truck){
		return truck.read(in);
	}
}