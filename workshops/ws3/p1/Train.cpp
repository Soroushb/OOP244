
/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 09/06/2020 / after a little change -> 10/06/2020
WS3P1
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
		cargo->weight = car.weight;        //copying the data from parameters
		strcpy(cargo->name, car.name);     //copying the data from parameters

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

			cout << "Name: " << nameTrain << endl;
			cout << "ID: " << idNum << endl;
			cout << "No cargo on this train." << endl;
		}
		else {

			cout << "Name: " << nameTrain << endl;
			cout << "ID: " << idNum << endl;
			cout << "Cargo: " << cargo->name << endl;
			cout << "Weight: " << cargo->weight << endl;
			
		}
	}



}