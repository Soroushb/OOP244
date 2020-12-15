
/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 12/06/2020 
WS3P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include "Train.h" 
#include "Cargo.h"
#include <cstring> //for strcpy()
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds {


	void Train::initialize(const char* name, int id) {     //member function: intialize()


		if (name == nullptr || strlen(name) == 0) {   //If the inputted name is empty or nullptr

			idNum = 0;        //we set id to 0, so that the data inputted becomes invalid in isValid() function

		}
		else if (id < 1) {    //If the inputted id is not greater than 0

			idNum = 0;       //we set id to 0, so that the data inputted becomes invalid in isValid() function
		}
		else {                //otherwise,,

			idNum = id;       //copy the id inputted to the train id
			strcpy(nameTrain, name);      //copy the name inputted to the name of the train
			cargo = nullptr;     //initialize cargo to null
		}


	}





	bool Train::isValid() const {      //member function: isValid()


		bool valid;      //bool type valid

		if (idNum == 0 || nameTrain == nullptr) {

			valid = false;
		}
		else {
			valid = true;
		}
		return valid;

	}




	void Train::loadCargo(Cargo car) {     //member function: loadCargo()

		unloadCargo();
		cargo = new Cargo;              //allocating dynamic memory for a single instance of Cargo to the cargo pointer
		cargo->setWeight(car.getWeight());        //copying the data from parameters
		cargo->setDesc(car.getDesc());    //copying the data from parameters


	}




	void Train::unloadCargo() {            //member function: unloadCargo


		if (cargo != nullptr) {
			delete cargo;             //deallocating dynamic memory
			cargo = nullptr;
		}

	}





	void Train::display() const {     //member function: display()

		cout << "***Train Summary***" << endl;

		if (idNum == 0) {


			cout << "This is an invalid train." << endl;

		}
		else if (cargo == nullptr) {

			cout.width(10);         //field of size 10 aligned to right
			cout << "Name: " << nameTrain << endl;
			cout.width(10);
			cout << "ID: " << idNum << endl;
			cout << "No cargo on this train." << endl;
		}
		else {
			cout.width(10);
			cout << "Name: " << nameTrain << endl;
			cout.width(10);
			cout << "ID: " << idNum << endl;
			cout.width(10);
			cout << "Cargo: " << cargo->getDesc() << endl;

			if (cargo->getWeight() < 100) {   //if weight is smaller than 100, which means it has two numbers before decimal point.
				cout.precision(4);   //4 floating-point values
				cout.width(10);
				cout << "Weight: " << cargo->getWeight() << endl;
			}
			else {     //If number is greater or equal to 100, which means it has three numbers before decimal point.
				cout.precision(5);   //5 floating-point values
				cout.width(10);
				cout << "Weight: " << cargo->getWeight() << endl;
			}


		}
	}





	bool Train::swapCargo(Train& other) {   //Train class member function: swapCargo()

		bool swap;
		char* tempName = nullptr;
		tempName = new char[MAX_NAME + 1];   //a temporary dynamic-memory array of characters to hold the description
		double tempWeight = 0;      //a temporary double type value to hold the weight

		if (isValid() && other.isValid() && other.cargo != nullptr && cargo != nullptr) {

			strcpy(tempName, other.cargo->getDesc());   
			tempWeight = other.cargo->getWeight();    
			other.cargo->setWeight(cargo->getWeight());  
			other.cargo->setDesc(cargo->getDesc());   
			cargo->setWeight(tempWeight); 
			cargo->setDesc(tempName);
			swap = true;

			
		}
		else {

			swap = false;

		}

		delete[] tempName;   //deallocating the dynamic memory
		tempName = nullptr;
		return swap;

	}
	bool Train::increaseCargo(double weight) {   //Train class member function: increaseCargo()


		bool increase = false;
		double max;
		cout.precision(6);
		max = MAX_WEIGHT;

		if (isValid() && cargo != nullptr && cargo->getWeight() != MAX_WEIGHT) {

			if (cargo->getWeight() + weight > MAX_WEIGHT) {


				cargo->setWeight(max);
				increase = true;

			}
			else if (cargo->getWeight() + weight < MAX_WEIGHT) {

				cargo->setWeight(weight + cargo->getWeight());
				increase = true;
			}
			else {
				increase = false;
			}



		}

		return increase;

	}
	bool Train::decreaseCargo(double weight) {    //Train class member function: decreaseCargo()


		bool decrease = false;
		double min;
		cout.precision(6);
		min = MIN_WEIGHT;

		if (isValid() && cargo != nullptr && cargo->getWeight() != MIN_WEIGHT) {

			if (cargo->getWeight() - weight < MIN_WEIGHT) {


				cargo->setWeight(min);
				decrease = true;

			}
			else if (cargo->getWeight() - weight > MIN_WEIGHT) {

				cargo->setWeight(cargo->getWeight() - weight);
				decrease = true;
			}
			else

				decrease = false;
		}

		return decrease;

	}

}