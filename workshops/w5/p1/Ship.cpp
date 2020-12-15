/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 25/06/2020
WS5P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <cstring> //for strcpy()
#include "Ship.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds {

	Ship::Ship() {

		emptyShips();

	}
	Ship::Ship(const char* type, const Engine* engines, int size) {

		if (type != nullptr && type[0] != '\0' && strlen(type) <= TYPE_MAX_SIZE && size <= MAX_ENGINES && size >= 1 && engines != nullptr) {


			strcpy(m_type, type);
			m_engCnt = size;
			for (int i = 0; i < size; i++)
			{
				m_engines[i] = engines[i];
			}

		}
		else {

			emptyShips();
		}

	}
	Ship::operator bool() const {

		bool valid;
		if (m_engCnt <= MAX_ENGINES && m_engCnt > 0 && m_type[0] != '\0' && strlen(m_type) <= TYPE_MAX_SIZE) {
			valid = true;
		}
		else
			valid = false;
		return valid;
	}

	Ship& Ship::operator+=(Engine engine) {
		if (operator bool()) {

			if (m_engCnt < MAX_ENGINES) {

				m_engines[m_engCnt++] = engine;
			}
		}
		else {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}

		return *this;
	}

	bool Ship::operator<(double power) const {
		bool valid;
		if (this->shipPower() < power) {
			valid = true;
		}
		else
		{
			valid = false;
		}
		return valid;
	}

	void Ship::emptyShips() {

        m_engines->emptyEngines();
        m_type[0] = '\0';
		m_engCnt = 0;
	} 

	bool operator<(double power, const Ship& theShip) {

		bool smaller;
		if (power < theShip.shipPower()) {

			smaller = true;
		}
		else
			smaller = false;
		return smaller;

	}

	double Ship::shipPower() const {

		double shipPower = 0.00;

		for (int i = 0; i < m_engCnt; i++)
		{
			shipPower += m_engines[i].get();
		}

		shipPower = shipPower * 5;
		return shipPower;
	}

	void Ship::display() const {

		if (m_type[0] != '\0' && operator bool()) {
			cout << m_type << " - " << this->shipPower() << endl;
			for (int i = 0; i < m_engCnt; i++) {
				m_engines[i].display();
			}
		}
		else {
			cout << "No available data" << endl;
		}

	}

	Ship::~Ship() {
		emptyShips();
	}
}