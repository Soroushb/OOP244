/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 29/06/2020
WS5P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <cstring> //for strcpy()
#include "Ship.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds
{

	Ship::Ship() {

		emptyShip();
	}

	Ship::~Ship() {
		if (m_type != nullptr) {
			delete[] m_type;
			m_type = nullptr;
		}
		if (m_engines != nullptr) {
			delete[] m_engines;
			m_engines = nullptr;
		}
	}

	Ship::Ship(const char* type, const Engine* engines, int size) {

		emptyShip();

		if (engines != nullptr && type != nullptr && size > 0)
		{

			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_engines = new Engine[size];
			for (int i = 0; i < size; i++) {
				m_engines[i] = engines[i];
			}
			m_engCnt = size;
		}
	}


	Ship::operator bool() const {
		bool valid = true;
		if (m_engines == nullptr && m_type == nullptr && m_engCnt == 0) {

			valid = false;
		}
		return valid;
	}

	Ship& Ship::operator+=(Engine engine) {
		if (operator bool()) {

			Engine* newEngine = nullptr;
			newEngine = new Engine[m_engCnt + 1];

			for (int i = 0; i < m_engCnt; i++)
			{
				newEngine[i] = m_engines[i];
			}

			newEngine[m_engCnt++] = engine;
			delete[] m_engines;

			m_engines = nullptr;
			m_engines = newEngine;
		}
		else {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}

		return *this;
	}

	bool Ship::operator<(double power) const {
		bool valid = false;
		if (this->shipPower() < power) {
			valid = true;
		}
		return valid;
	}

	void Ship::display() const {
		if (operator bool() && m_type != nullptr) {
			cout << m_type << " - ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(6);
			cout << this->shipPower() << endl;
			cout.unsetf(ios::fixed);
			cout.precision(6);
			for (int i = 0; i < m_engCnt; i++) {
				m_engines[i].display();
			}
		}
		else {

			cout << "No available data" << endl;
		}
	}

	void Ship::emptyShip() {

		m_engines = nullptr;
		m_type = nullptr;
		m_engCnt = 0;
	}

	double Ship::shipPower() const {

		double result = 0;
		for (int i = 0; i < m_engCnt; i++) {
			result += m_engines[i].get();
		}
		result = result * 5;
		return result;
	}

	bool operator<(double power, const Ship& theShip) {
		bool check = false;
		if (power < theShip.shipPower()) {
			check = true;
		}
		return check;
	}




}