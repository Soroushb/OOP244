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


	void Cargo::initialize(const char* desc, double weight) {

		setDesc(desc);
		setWeight(weight);

	}


	const char* Cargo::getDesc() const {

		return name;

	}


	double Cargo::getWeight() const {

		return weight;

	}


	void Cargo::setDesc(const char* description) {


		strcpy(name, description);


	}


	void Cargo::setWeight(double weight) {

		if (weight < MIN_WEIGHT || weight > MAX_WEIGHT) {


			this->weight = MIN_WEIGHT;
		}
		else if (weight == MIN_WEIGHT) {
			cout.precision(4);
			this->weight = weight;
		}
		else
			this->weight = weight;



	}
}