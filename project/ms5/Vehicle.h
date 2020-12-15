/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 06/8/2020
MS5
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_VEHICLE_H__
#define SDDA_VEHICLE_H__
#include "ReadWritable.h"
namespace sdds {
	class Vehicle : public ReadWritable {
	private:
		char m_licensePlate[9];
		char* m_makeModel;
		int m_parkingSpot;
	public:
		Vehicle();
		Vehicle(const Vehicle&) = delete;
		void operator=(const Vehicle&) = delete;
		Vehicle(const char* licensePlate, const char* makeModel);
		virtual ~Vehicle();
		void setEmpty();
		bool isEmpty()const;
		const char* getLicensePlate()const;
		const char* getMakeModel()const;
		void setMakeModel(const char* value);
		int getParkingSpot() const;
		void setParkingSpot(int value);
		bool operator==(const char* licensePlate) const;
		bool operator==(const Vehicle& v) const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	
	};
}

#endif