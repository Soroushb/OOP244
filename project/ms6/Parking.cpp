/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 10/8/2020
MS6
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "string"
#include "Parking.h"
#include "Car.h"
#include "Menu.h"
#include "Motorcycle.h"
#include "Utils.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


namespace sdds {


	Parking::Parking(const char* datafile, int noOfSpots) :
		m_datafile(nullptr),
		m_parkingMenu("Parking Menu, select an action:"),
		m_vehicleMenu("Select type of the vehicle:", 1) {

		setEmpty();//setting to a safe state

		if (datafile != nullptr && strlen(datafile) > 0 && noOfSpots <= MAX_LOT_SIZE && noOfSpots > 9) { //if in a good state
	
			m_datafile = new char[strlen(datafile) + 1]; //dynamically allocate memory for m_datafile in parameter size plus null pointer
			strcpy(m_datafile, datafile);//copy data
			for (int i = 0; i < m_noOfSpots; i++) { 
				m_parkingSpots[i] = nullptr;//put all the spots to nyllptr
			}
			m_noOfSpots = noOfSpots;
			m_parked = 0;

		}
		
		if (load()) {
			m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			m_vehicleMenu << "Car" << "Motorcycle" << "Cancel"; //adding options to menu
		}
		else {
			cout << "Error in data file" << endl; //if doesn't load give an error
		}
	}

	void Parking::parkVehicle() {

		if (m_noOfSpots == m_parked) { //if number of parked are equal to number of spots
			cout << "Parking is full" << endl;
		}
		else {
			int option = m_vehicleMenu;
			if (option == 3) { //if choose cancel
				cout << "Parking Cancelled" << endl;
			}
			else if (option == 1) { //if choose car
				int i = findSpot(); //finds an empty spot
				m_parkingSpots[i] = new Car; //allocate dynamic memory in the empty spot that was found
				cin >> *m_parkingSpots[i]; 
				m_parkingSpots[i]->setParkingSpot(i + 1); 
				m_parked++; //one number is added to parked spots
				cout << endl << "Parking Ticket" << endl;
				m_parkingSpots[i]->setCsv(false); //not putting in comma separated
				cout << *m_parkingSpots[i] << endl;

			}
			else if (option == 2) { //same as above, for motorcycle
				int i = findSpot();
				m_parkingSpots[i] = new Motorcycle;
				cin >> *m_parkingSpots[i];
				m_parkingSpots[i]->setParkingSpot(i + 1);
				m_parked++;
				cout << endl << "Parking Ticket" << endl;
				m_parkingSpots[i]->setCsv(false);
				cout << *m_parkingSpots[i] << endl;
			}
			else {
				cout << "Invalid Option" << endl;
			}
		}
		
		
	}

	void Parking::returnVehicle() {
		char temp[9]; //8 chars + null pointer
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		cin.get(temp, 10); //I put 10 instead of 9, because the user may enter an invalid licence number which is more than 8 charactars, and the only to find out is to get more than 8 characters and see if the input is more than 8
		while (strlen(temp) < 1 || strlen(temp) > 8) { //invalid licence plate
			cout << "Invalid Licence Plate, try again: ";
			cin.get(temp, 10);
		}
		
		Utils::toUpper(temp);
		int j = 0;
		bool findLicence = false;
		
		for (int i = 0; i < m_noOfSpots && !findLicence; i++) {
			if (m_parkingSpots[i]) {
				if (*m_parkingSpots[i] == temp) {
					cout << "Returning: " << endl;
					m_parkingSpots[j]->setCsv(false); 
					cout << *m_parkingSpots[j] << endl; //returning 
					delete m_parkingSpots[i];//delete dynamically allocated memory
					m_parkingSpots[i] = nullptr;
					m_parked--;//one number is reduced from parked numbers
					findLicence = true;

				}
			}
		}
		
			
	}

	void Parking::listParkedVehicles() {

		cout << "*** List of parked vehicles ***" << endl;

		if (isEmpty() == false) { //if not empty
			for (int i = 0; i < m_noOfSpots; i++)
			{
				if (m_parkingSpots[i] != nullptr) {//if it's not empty
					m_parkingSpots[i]->setCsv(false);//not putting in csv 
					cout << *m_parkingSpots[i];//outputting
					cout << "-------------------------------" << endl;
				}
			}
		}
	}

	bool Parking::closeParking() {
		bool closed = false; //not closed yet
		if(m_parked == 0){ //if there is no vehicle in the parking
			closed = true;
			cout << "Closing Parking" << endl;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			closed = Utils::yes();//using utils module function to get the answer
			
			if (closed) {//if true
				cout << "Closing Parking" << endl;
				for (int i = 0; i < m_noOfSpots; i++)//for each spot
				{
					if (m_parkingSpots[i])
					{
						cout << endl;
						cout << "Towing request" << endl;
						cout << "*********************" << endl;

						m_parkingSpots[i]->setCsv(false);
						cout << *m_parkingSpots[i];//show the vehicle, not in csv mode
						delete m_parkingSpots[i];//delete its memory
						m_parkingSpots[i] = nullptr;
					}
				}
			}
			else {
				cout << "not closed" << endl;
			}
			

		}
		
		return closed;//return closed bool(T or F)
	}

	bool Parking::exitParkingApp() {//unchanged
		bool option = false;
		if ((option = Utils::confirmed("terminate the program")))
			cout << "Exiting program!" << endl;
		return option;
	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots:  ";
		cout.width(4);
		cout.setf(ios::left);//left aligned
        cout << (m_noOfSpots - m_parked) << "*****" << endl;//find available spots by reducing parked spaces from number of the spots
		cout.unsetf(ios::left);
	}

	Parking::~Parking() {//destructor 
		save();
		setEmpty();
	}

	bool Parking::load() {//load function

		bool load = false;


		if (!isEmpty()) {//if not empty
			bool done = false;
			ifstream dataFile(m_datafile, ios::in);
			
			Vehicle* newVehicle = nullptr;
			for (int i = 0; i < m_noOfSpots && !done; i++) {
				char type[2];
				dataFile.get(type, 2, ',');
				dataFile.ignore();
				if (dataFile.eof()) {
					done = true;
					load = true;
				}
				else {
					int j = 0;
					if (type[0] == 'M') {//If the character is "M"

						newVehicle = new Motorcycle;//allocate dynamic memory 
						newVehicle->setCsv(true);//put in cooma separated 

						dataFile >> *newVehicle;
						j = newVehicle->getParkingSpot() - 1;
						m_parkingSpots[j] = newVehicle;
						
					}
					else if (type[0] == 'C') {

						newVehicle = new Car;
						newVehicle->setCsv(true);

						dataFile >> *newVehicle;
						j = newVehicle->getParkingSpot() - 1;
						m_parkingSpots[j] = newVehicle;
					}
					

					if (dataFile.fail()) {

						done = true;
						load = false;

						delete m_parkingSpots[j];
						m_parkingSpots[j] = nullptr;

						
					}
					else {
						m_parked++;//if works, add one number to the parked number
						load = true;
					}
				}
				newVehicle = nullptr;
			}
			dataFile.clear();
			dataFile.close();
		}
		return load;
	}

	void Parking::save() {

		if (!isEmpty()) {
			ofstream dataFile(m_datafile, ios::out);
			for (int i = 0; i < m_noOfSpots; i++) {
				if (m_parkingSpots[i]) {
					m_parkingSpots[i]->setCsv(true);
					dataFile << *m_parkingSpots[i];
				}
			}
		}
	}

	bool Parking::isEmpty() const {
		return m_datafile == nullptr;
	}

	void Parking::setEmpty() {
		delete[] m_datafile;
		m_datafile = nullptr;
		m_datafile = nullptr;
		m_parked = -1;
		m_noOfSpots = 0;
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

	int Parking::findSpot() {

		bool find = false;
		int spot = 0;
		for (int i = 0; i < m_noOfSpots && !find; i++)
		{
			if (!m_parkingSpots[i]) {
				spot = i;
				find = true;
			}
		}
		return spot;
	}
}