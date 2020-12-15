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
#include<cstring>
#include"MotorVehicle.h"


using namespace std;

namespace sdds {
	
	MotorVehicle::MotorVehicle(const char* plate, int year){
		strcpy(m_plate, plate);
		strcpy(m_address, "Factory");
		m_year = year;
	}
	void MotorVehicle::moveTo(const char* address){
		if (strcmp(m_address, address) != 0) {
			cout << "|";
			cout.width(10);
			cout.setf(ios::right);
			cout << m_plate;
			cout << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_address;
			cout << " --->--- ";
			cout.width(20);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << address;
			cout << "|" << endl;
			strcpy(m_address, address);
	}
	}
	ostream& MotorVehicle::write(ostream& out) const{
		out << "| ";
		out << m_year;
		out << " | ";
		out << m_plate;
		out << " | ";
		out << m_address;
		return out;
	
	}
	istream& MotorVehicle::read(istream& in){
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_plate;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}
	ostream& operator<<(ostream& os, const MotorVehicle& motor){
		return motor.write(os);
	}
	istream& operator>>(istream& in, MotorVehicle& motor){
		return motor.read(in);
	}
}