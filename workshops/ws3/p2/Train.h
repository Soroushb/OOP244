/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 12/06/2020
WS3P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TRAIN_H // safeguards
#define SDDS_TRAIN_H
#include "Cargo.h"   


namespace sdds {

	const int MAX_NAME = 30;


	class Train {
	private:         //data members


		char nameTrain[MAX_NAME + 1];
		int idNum;
		Cargo* cargo;


	public:          //member functions

		void initialize(const char* name, int id);
		bool isValid() const;    //query
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;    //query
		bool swapCargo(Train& other);
		bool increaseCargo(double weight);
		bool decreaseCargo(double weight);

	};



}


#endif

