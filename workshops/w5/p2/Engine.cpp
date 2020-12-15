/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 29/06/2020
WS5P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include <cstring> //for strcpy()
#include "Engine.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds
{

	Engine::Engine() {

		emptyEngines();
	}

	Engine::~Engine() {
		emptyEngines();
	}

	Engine::Engine(const char* type, double size) {

		emptyEngines();
		if (size > 0 && type != nullptr) {

			m_size = size;
			strcpy(m_type, type);
		}
	}


	double Engine::get() const {

		return m_size;
	}

	void Engine::display() const {
		if (m_size > 0 && m_type != nullptr) {
			cout.setf(ios::fixed);
			cout << fixed << setprecision(2) << m_size << " liters - " << m_type << endl;
			cout.unsetf(ios::fixed);
			cout.precision(6);
		}
	}
	void Engine::emptyEngines() {

		m_size = 0;
		m_type[0] = '\0';
	}


}
