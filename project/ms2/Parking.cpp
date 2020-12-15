/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 28/7/2020
MS2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring"
#include "Parking.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	Parking::Parking(const char* datafile) :
		m_datafile(nullptr),
		m_parkingMenu("Parking Menu, select an action:"),
		m_vehicleMenu("Select type of the vehicle:", 1) {
		if (datafile != nullptr) {

				m_datafile = new char[strlen(datafile) + 1];
				strcpy(m_datafile, datafile);
			
		}
		if (load()) {
			m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
		}
		else{
			cout << "Error in data file" << endl;
			setEmpty();
		}
		
	}

	void Parking::parkVehicle() {
		int option;
		option = m_vehicleMenu.run();

		switch (option)
		{
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
			break;
		default:
			break;
		}
	}

	void Parking::returnVehicle() {
		cout << "Returning Vehicle" << endl;
	}

	void Parking :: listParkedVehicles() {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() {
		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitParkingApp() {
		bool option = false;
		if ((option = Utils::confirmed("terminate the program")))
			cout << "Exiting program!" << endl;
		return option;
	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	Parking::~Parking() {
		save();
		setEmpty();
	}

	bool Parking::load() {
		if (!isEmpty())
			cout << "loading data from " << m_datafile << endl;
		return (!isEmpty());
	}

	void Parking::save() {
		if (!isEmpty())
			cout << "Saving data into " << m_datafile << endl;
	}

	bool Parking::isEmpty() const {
		return m_datafile == nullptr;
	}

	void Parking::setEmpty() {
		delete[] m_datafile;
		m_datafile = nullptr;
	}

	int Parking::run() {
		bool done = false;
		int selection = 0;
		while (!isEmpty() && !done) {
			parkingStatus();
			selection = m_parkingMenu.run();
			if (selection == 1)
				parkVehicle();
			if (selection == 2)
				returnVehicle();
			if (selection == 3)
				listParkedVehicles();
			if (selection == 4)
				done = closeParking();
			if (selection == 5)
				done = exitParkingApp();


		}
		return 0;
	}
}