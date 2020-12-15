/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 10/8/2020
MS6
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once


#include "Menu.h"
#include "Vehicle.h"

namespace sdds {
	const int MAX_LOT_SIZE = 100;
	class Parking {
		char* m_datafile;
		Menu m_parkingMenu;
		Menu m_vehicleMenu;
		int m_noOfSpots;
		int m_parked;
		Vehicle* m_parkingSpots[MAX_LOT_SIZE];
	private:
		bool isEmpty() const;
		void setEmpty();
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		bool closeParking();
		bool exitParkingApp();
		bool load();
		void save();
		int findSpot();
	public:
		Parking();
		Parking(const char* datafile, int noOfSpots);
		Parking(const Parking&) = delete;
		void operator=(const Parking&) = delete;
		int run();
		~Parking();
	};
}
