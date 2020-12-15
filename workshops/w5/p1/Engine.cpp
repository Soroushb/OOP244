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
#include "Engine.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds {

	Engine::Engine() {

		emptyEngines();
	}
	Engine::Engine(const char* type, double size) {

		strcpy(m_type, type);
		m_size = size;
	}
	double Engine::get() const {
		return m_size;
	}
	void Engine::display() const {
		if (m_size > 0 && m_type[0] != '\0') {
			cout << m_size << " liters - " << m_type << endl;
		}
	}
	void Engine::emptyEngines() {

		m_size = 0;
		m_type[0] = '\0';
	}

	Engine::~Engine() {
		emptyEngines();
	}
}